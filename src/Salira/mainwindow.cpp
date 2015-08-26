#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <fstream>
#include <QTextStream>
#include <Engines/translator.h>
#include <Engines/parser.h>
#include <Engines/executor.h>
#include <unistd.h>
#include <QTime>
#include <iostream>

static QString fileName = "parser/ulaz.txt";
static QList<GCommand> gCommands;
static QList<VAXCommand> vaxCommands;
static bool _stopped;
static bool _gCodeValid;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FillGCodeEditor()
{
    ui -> txtEditorGCode->clear();

    if(gCommands.size() == 0)
        return;

    QString buffer;
    int i = 0, currentCommandNumber = Executor::Instance().currentState().currentLineNumber() - 1;
    foreach (GCommand command, gCommands)
    {
        if(i == currentCommandNumber)
            buffer += "<font color=\"red\">" + command.ToString() + "</font><br>";
        else
            buffer += command.ToString() + "<br>";
        i++;
    }
    ui->txtEditorGCode->setHtml(buffer);

    ui->tsmiSaveGCode->setEnabled(true);
    _gCodeValid = true;
}

void MainWindow::FillVAXCodeEditor(bool clearOnly)
{
    ui -> txtEditorVAXCode->clear();

    if(clearOnly)
        return;

    if(!Translator::Instance().Translate(gCommands, &vaxCommands) || vaxCommands.size() == 0)
    {
        ui->tsmiSaveVAXCode->setEnabled(false);
        return;
    }

    foreach (VAXCommand command, vaxCommands)
        ui->txtEditorVAXCode->append(command.ToString());
    ui->tsmiSaveVAXCode->setEnabled(true);
}

void MainWindow::FillStack(bool clearOnly)
{
    this->RemoveAllButtons(ui->frameStack->layout());

    if(clearOnly)
        return;

    for(int i = Executor::Instance().currentState().stack().length() - 1; i >= 0; i--)
    {
        QString nodeName = "NODE [" + QString::number(Executor::Instance().currentState().stack().at(i)+1) + "]";
        ui->frameStack->layout()->addWidget(new QPushButton(nodeName));
    }
}

void MainWindow::FillGraph(bool clearOnly)
{
    this->RemoveAllButtons(ui->frameGraph->layout());

    if(clearOnly)
        return;

    for(int i = Executor::Instance().currentState().graph().length()-1; i >= 0 ; i--)
        ui->frameGraph->layout()->addWidget(new QPushButton(Executor::Instance().currentState().graph()[i].ToString()));
}

void MainWindow::FillDump(bool clearOnly)
{
    this->RemoveAllButtons(ui->frameDump->layout());

    if(clearOnly)
        return;

    if(Executor::Instance().currentState().dump().length() > 0)
    {
        // Avoiding sigsev.
        // Check if stack of dump element is empty, if it is, ignoring dump stack
        // NOTE: Pogledaj ovo.
        bool avoidSigSev = Executor::Instance().currentState().dump().last().stack().empty();
        if(!avoidSigSev){
            for(int i = Executor::Instance().currentState().dump().length()-1; i <= 0; i++)
            {
                QString nodeName = "NODE [" + QString::number(Executor::Instance().currentState().dump().last().stack().at(i)+1) + "]";
                ui->frameDump->layout()->addWidget(new QPushButton(nodeName));
            }
        }
    }

}

void MainWindow::FillOutput(bool clearOnly)
{
    ui->txtOutput->clear();

    if(clearOnly)
        return;

    foreach (QString line, Executor::Instance().currentState().output())
        ui->txtOutput->append(">> " + line + "\n");
}

void MainWindow::RefreshUI(bool clearOnly, bool keepGCodeText)
{
    if(!keepGCodeText)
        this->FillGCodeEditor();
    this->FillStack(clearOnly);
    this->FillGraph(clearOnly);
    this->FillDump(clearOnly);
    this->FillOutput(clearOnly);
}

void MainWindow::RefreshFileMenu(bool saveGCodeEnabled, bool saveVAXCodeEnabled)
{
    ui->tsmiSaveGCode->setEnabled(saveGCodeEnabled);
    ui->tsmiSaveVAXCode->setEnabled(saveVAXCodeEnabled);
}

void MainWindow::RefreshRunMenu(bool evaluateEnabled, bool nextEnabled, bool previousEnabled, bool runEnabled, bool stopEnabled)
{
    ui->tsmiRestart->setEnabled(evaluateEnabled);
    ui->tsmiNext->setEnabled(nextEnabled);
    ui->tsmiPrevious->setEnabled(previousEnabled);
    ui->tsmiRun->setEnabled(runEnabled);
    ui->tsmiStop->setEnabled(stopEnabled);

    ui->btnRestart->setEnabled(evaluateEnabled);
    ui->btnNext->setEnabled(nextEnabled);
    ui->btnPrevious->setEnabled(previousEnabled);
    ui->btnRun->setEnabled(runEnabled);
    ui->btnStop->setEnabled(stopEnabled);
}

void MainWindow::RemoveAllButtons(QLayout *layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0)
    {
        delete child->widget();
        delete child;
    }
}

void MainWindow::Clear(bool keepGCodeText)
{
    gCommands.clear();
    vaxCommands.clear();
    Executor::Instance().Reset();

    this->RefreshFileMenu(false, false);
    this->RefreshRunMenu(false, false, false, false, false);
    this->RefreshUI(true, keepGCodeText);

    ui->txtEditorVAXCode->clear();
    _gCodeValid = false;
}

void MainWindow::Open()
{
    try
    {
        fileName = QFileDialog::getOpenFileName (this, tr("Open File"), fileName /*, tr("Files (.)")*/);

        if(fileName.length() > 0)
        {
            QFile file(fileName);
            if(file.open(QIODevice::ReadOnly))
            {
                QTextStream in(&file);
                QList<QString> buffer;

                while(!in.atEnd())
                    buffer.push_back(in.readLine());
                file.close();

                for (int i = 0; i <= buffer.length() - 1 && buffer[0] == ""; i++)
                    buffer.removeAt(0);

                for (int i = buffer.length() - 1; i >= 0 && buffer[i] == ""; i--)
                    buffer.removeAt(i);

                ui->txtEditHaskell->clear();
                foreach (QString line, buffer)
                    ui->txtEditHaskell->append(line);
                ui->btnTranslate->setEnabled(true);
            }
        }
    }
    catch(std::exception e)
    {
       ui->txtOutput->append("Error: Opening Haskell file");
    }
}

void MainWindow::Translate()
{
    try
    {
        QFile file("parser/input.txt");
        file.open(QIODevice::WriteOnly);

        QTextStream outStream(&file);
        if(ui->txtEditHaskell->toPlainText().length() > 0)
            outStream << ui->txtEditHaskell->toPlainText();
        outStream.flush();

        file.close();
    }
    catch(std::exception e)
    {
        ui->txtOutput->append("Error: Saving input.txt file");
    }

    try
    {
        QFile file("gcode.txt");
        if(file.open(QIODevice::WriteOnly))
            file.resize(0);
        file.close();
    }
    catch(std::exception e)
    {
        ui->txtOutput->append("Error: Clearing gcode.txt file");
    }

    if(!system("parser/proba < parser/input.txt"))
    {
        QList<QString> buffer;
        try
        {
            QFile file("gcode.txt");
            if(file.open(QIODevice::ReadOnly))
            {
                QTextStream in(&file);
                while(!in.atEnd())
                    buffer.push_back(in.readLine());

                file.close();

                for (int i = 0; i <= buffer.length() - 1 && buffer[0] == ""; i++)
                    buffer.removeAt(0);

                for (int i = buffer.length() - 1; i >= 0 && buffer[i] == ""; i--)
                    buffer.removeAt(i);

                ui->txtEditorGCode->clear();
                foreach (QString line, buffer)
                    ui->txtEditorGCode->append(line);
            }
        }
        catch(std::exception e)
        {
           ui->txtOutput->append("Error: Opening gcode.txt file");
        }

        if(Parser::Instance().Parse(buffer, &gCommands))
        {
            QString errorMessage;
            if(Executor::Instance().Init(gCommands, errorMessage))
            {
                this->RefreshUI();
                this->RefreshFileMenu(true, false);
                this->RefreshRunMenu(false, true, false, true, false);
                this->FillVAXCodeEditor();
                _gCodeValid = true;
            }
            else
            {
                ui->txtEditorGCode->clear();
                ui->txtOutput->clear();
                ui->txtOutput->append(errorMessage);
            }
        }
    }
}

void MainWindow::Save(QTextEdit *editor, QString fileName)
{
    try
    {
         QString saveFilename = QFileDialog::getSaveFileName(this, tr("Save file"), fileName);

         QFile file(saveFilename);
         file.open(QIODevice::WriteOnly);

         QTextStream outStream(&file);

         if(editor->toPlainText().length() > 0)
             outStream << editor->toPlainText();

         outStream.flush();
         file.close();
     }
     catch(std::exception e)
     {
        ui->txtOutput->append("Error: Saving " + fileName + " file");
     }
}

void MainWindow::Evaluate()
{
    this->Clear(true);

    QList<QString> buffer;
    QString plainText = ui->txtEditorGCode->toPlainText();

    int beginIndex = 0, endIndex = 0;
    while((endIndex = plainText.indexOf("\n", beginIndex)) != -1)
    {
        buffer.push_back(QString(plainText.begin() + beginIndex, endIndex - beginIndex));
        beginIndex = endIndex + 1;
    }
    endIndex = plainText.lastIndexOf("\n") + 1;
    buffer.push_back(QString(plainText.begin() + endIndex, plainText.length() - endIndex));

    for (int i = 0; i <= buffer.length() - 1 && buffer[0] == ""; i++)
        buffer.removeAt(0);

    for (int i = buffer.length() - 1; i >= 0 && buffer[i] == ""; i--)
        buffer.removeAt(i);

    if(Parser::Instance().Parse(buffer, &gCommands))
    {
        QString errorMessage;
        if(Executor::Instance().Init(gCommands, errorMessage))
        {
            this->RefreshUI();
            this->RefreshRunMenu(false, true, false, true, false);
            this->FillVAXCodeEditor();
            _gCodeValid = true;
        }
        else
        {
            ui->txtOutput->clear();
            ui->txtOutput->append(errorMessage);
        }
    }

    this->RefreshFileMenu(ui->txtEditorGCode->toPlainText().length() > 0,
                          ui->txtEditorVAXCode->toPlainText().count() > 0);
}

void MainWindow::Next()
{
    Executor::Instance().ExecuteNext();
    this->RefreshUI();

    int currentID = Executor::Instance().currentState().id();
    this->RefreshRunMenu(currentID > 0, currentID < State::maxID(), currentID > 0, currentID < State::maxID(), false);
}

void MainWindow::Previous()
{
    Executor::Instance().ExecutePrevious();
    this->RefreshUI();

    int currentID = Executor::Instance().currentState().id();
    this->RefreshRunMenu(currentID > 0, currentID < State::maxID(), currentID > 0, currentID < State::maxID(), false);
}

void MainWindow::Run()
{
    _stopped = false;
    this->RefreshRunMenu(false, false, false, false, true);

    while(Executor::Instance().currentState().id() < State::maxID())
    {
        if(_stopped)
            break;
        this->delay(500);
        Executor::Instance().ExecuteNext();
        this->RefreshUI();
    }
    _stopped = true;

    int currentID = Executor::Instance().currentState().id();
    this->RefreshRunMenu(currentID > 0, currentID < State::maxID(), currentID > 0, currentID < State::maxID(), false);
}

void MainWindow::Stop()
{
    _stopped = true;
    ui->btnStop->setEnabled(false);
}

void MainWindow::on_tsmiOpen_triggered()
{
    this->Open();
}

void MainWindow::on_tsmiTranslate_triggered()
{
    this->Translate();
}

void MainWindow::on_tsmiClear_triggered()
{
    ui->txtEditHaskell->clear();
}

void MainWindow::on_tsmiSaveGCode_triggered()
{
    this->Save(ui->txtEditorGCode, "GCode.txt");
}

void MainWindow::on_tsmiSaveVAXCode_triggered()
{
    this->Save(ui->txtEditorVAXCode, "VAXCode.txt");
}

void MainWindow::on_tsmiClose_triggered()
{
   this->close();
}

void MainWindow::on_tsmiRestart_triggered()
{
    this->Evaluate();
}

void MainWindow::on_tsmiNext_triggered()
{
    this->Next();
}

void MainWindow::on_tsmiPrevious_triggered()
{
    this->Previous();
}

void MainWindow::on_tsmiRun_triggered()
{
    this->Run();
}

void MainWindow::on_tsmiStop_triggered()
{
    this->Stop();
}

void MainWindow::on_btnOpen_clicked()
{
    this->Open();
}

void MainWindow::on_btnClear_clicked()
{
    ui->txtEditHaskell->clear();
}

void MainWindow::on_btnTranslate_clicked()
{
    this->Translate();
}

void MainWindow::on_txtEditHaskell_textChanged()
{
    bool enabled = ui->txtEditHaskell->toPlainText().count() > 0;
    ui->tsmiTranslate->setEnabled(enabled);
    ui->btnTranslate->setEnabled(enabled);
    ui->tsmiClear->setEnabled(enabled);
    ui->btnClear->setEnabled(enabled);
}

void MainWindow::on_btnRestart_clicked()
{
    this->Evaluate();
}

void MainWindow::on_btnNext_clicked()
{
    this->Next();
}

void MainWindow::on_btnPrevious_clicked()
{
    this->Previous();
}

void MainWindow::on_btnRun_clicked()
{
    this->Run();
}

void MainWindow::on_btnStop_clicked()
{
    this->Stop();
}

void MainWindow::on_txtEditorGCode_textChanged()
{
    bool notEmpty = ui->txtEditorGCode->toPlainText().length() > 0;
    _gCodeValid = false;

    this->RefreshFileMenu(notEmpty, ui->txtEditorVAXCode->toPlainText().length() > 0);
    this->RefreshRunMenu(notEmpty, false, false, false, false);
}

void MainWindow::on_txtEditorVAXCode_textChanged()
{
    ui->tsmiSaveVAXCode->setEnabled(ui->txtEditorVAXCode->toPlainText().length() > 0);
}

void MainWindow::delay( int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
