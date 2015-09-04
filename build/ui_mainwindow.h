/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *tsmiOpen;
    QAction *tsmiSaveGCode;
    QAction *tsmiSaveVAXCode;
    QAction *tsmiPrevious;
    QAction *tsmiNext;
    QAction *tsmiRun;
    QAction *tsmiStop;
    QAction *tsmiRestart;
    QAction *tsmiAbout;
    QAction *tsmiClose;
    QAction *tsmiClear;
    QAction *tsmiTranslate;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout;
    QLabel *labelHaskell;
    QPushButton *btnOpen;
    QPushButton *btnClear;
    QPushButton *btnTranslate;
    QTextEdit *txtEditHaskell;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnRestart;
    QFrame *line;
    QPushButton *btnPrevious;
    QPushButton *btnNext;
    QPushButton *btnRun;
    QPushButton *btnStop;
    QTextEdit *txtEditorGCode;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QTextEdit *txtEditorVAXCode;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QScrollArea *scrollAreaStack;
    QWidget *frameStack;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QScrollArea *scrollAreaGraph;
    QWidget *frameGraph;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QScrollArea *scrollAreaDump;
    QWidget *frameDump;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QTextEdit *txtOutput;
    QLabel *label_6;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1102, 500);
        MainWindow->setMinimumSize(QSize(980, 500));
        tsmiOpen = new QAction(MainWindow);
        tsmiOpen->setObjectName(QStringLiteral("tsmiOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/Images/folder-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiOpen->setIcon(icon);
        tsmiSaveGCode = new QAction(MainWindow);
        tsmiSaveGCode->setObjectName(QStringLiteral("tsmiSaveGCode"));
        tsmiSaveGCode->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/Images/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiSaveGCode->setIcon(icon1);
        tsmiSaveVAXCode = new QAction(MainWindow);
        tsmiSaveVAXCode->setObjectName(QStringLiteral("tsmiSaveVAXCode"));
        tsmiSaveVAXCode->setEnabled(false);
        tsmiSaveVAXCode->setIcon(icon1);
        tsmiPrevious = new QAction(MainWindow);
        tsmiPrevious->setObjectName(QStringLiteral("tsmiPrevious"));
        tsmiPrevious->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/Images/arrow-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiPrevious->setIcon(icon2);
        tsmiNext = new QAction(MainWindow);
        tsmiNext->setObjectName(QStringLiteral("tsmiNext"));
        tsmiNext->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/Images/arrow-forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiNext->setIcon(icon3);
        tsmiRun = new QAction(MainWindow);
        tsmiRun->setObjectName(QStringLiteral("tsmiRun"));
        tsmiRun->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/Images/arrow-play.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiRun->setIcon(icon4);
        tsmiStop = new QAction(MainWindow);
        tsmiStop->setObjectName(QStringLiteral("tsmiStop"));
        tsmiStop->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/Images/shape-square.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiStop->setIcon(icon5);
        tsmiRestart = new QAction(MainWindow);
        tsmiRestart->setObjectName(QStringLiteral("tsmiRestart"));
        tsmiRestart->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/Images/arrow-refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiRestart->setIcon(icon6);
        tsmiAbout = new QAction(MainWindow);
        tsmiAbout->setObjectName(QStringLiteral("tsmiAbout"));
        tsmiClose = new QAction(MainWindow);
        tsmiClose->setObjectName(QStringLiteral("tsmiClose"));
        tsmiClose->setEnabled(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/Images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiClose->setIcon(icon7);
        tsmiClear = new QAction(MainWindow);
        tsmiClear->setObjectName(QStringLiteral("tsmiClear"));
        tsmiClear->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/Images/brush.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiClear->setIcon(icon8);
        tsmiTranslate = new QAction(MainWindow);
        tsmiTranslate->setObjectName(QStringLiteral("tsmiTranslate"));
        tsmiTranslate->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/Images/book-go.png"), QSize(), QIcon::Normal, QIcon::Off);
        tsmiTranslate->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(220, 456));
        groupBox_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_7 = new QVBoxLayout(groupBox_5);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 5, -1, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(2);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelHaskell = new QLabel(groupBox_5);
        labelHaskell->setObjectName(QStringLiteral("labelHaskell"));
        labelHaskell->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(labelHaskell);

        btnOpen = new QPushButton(groupBox_5);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOpen->sizePolicy().hasHeightForWidth());
        btnOpen->setSizePolicy(sizePolicy);
        btnOpen->setMinimumSize(QSize(32, 32));
        btnOpen->setMaximumSize(QSize(32, 32));
        btnOpen->setIcon(icon);
        btnOpen->setIconSize(QSize(32, 32));
        btnOpen->setFlat(true);

        horizontalLayout->addWidget(btnOpen);

        btnClear = new QPushButton(groupBox_5);
        btnClear->setObjectName(QStringLiteral("btnClear"));
        btnClear->setEnabled(false);
        btnClear->setMinimumSize(QSize(32, 32));
        btnClear->setMaximumSize(QSize(32, 32));
        btnClear->setIcon(icon8);
        btnClear->setIconSize(QSize(32, 32));
        btnClear->setFlat(true);

        horizontalLayout->addWidget(btnClear);

        btnTranslate = new QPushButton(groupBox_5);
        btnTranslate->setObjectName(QStringLiteral("btnTranslate"));
        btnTranslate->setEnabled(false);
        btnTranslate->setMinimumSize(QSize(32, 32));
        btnTranslate->setMaximumSize(QSize(32, 32));
        btnTranslate->setIcon(icon9);
        btnTranslate->setIconSize(QSize(32, 32));
        btnTranslate->setAutoDefault(false);
        btnTranslate->setFlat(true);

        horizontalLayout->addWidget(btnTranslate);


        verticalLayout_6->addLayout(horizontalLayout);

        txtEditHaskell = new QTextEdit(groupBox_5);
        txtEditHaskell->setObjectName(QStringLiteral("txtEditHaskell"));
        txtEditHaskell->setMinimumSize(QSize(0, 0));

        verticalLayout_6->addWidget(txtEditHaskell);


        verticalLayout_7->addLayout(verticalLayout_6);


        horizontalLayout_2->addWidget(groupBox_5);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(220, 456));
        groupBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(4);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(4, 4, 4, 4);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnRestart = new QPushButton(groupBox);
        btnRestart->setObjectName(QStringLiteral("btnRestart"));
        btnRestart->setEnabled(false);
        btnRestart->setMinimumSize(QSize(32, 32));
        btnRestart->setMaximumSize(QSize(32, 32));
        btnRestart->setIcon(icon6);
        btnRestart->setIconSize(QSize(32, 32));
        btnRestart->setFlat(true);

        horizontalLayout_4->addWidget(btnRestart);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        btnPrevious = new QPushButton(groupBox);
        btnPrevious->setObjectName(QStringLiteral("btnPrevious"));
        btnPrevious->setEnabled(false);
        btnPrevious->setMinimumSize(QSize(32, 32));
        btnPrevious->setMaximumSize(QSize(32, 32));
        btnPrevious->setIcon(icon2);
        btnPrevious->setIconSize(QSize(32, 32));
        btnPrevious->setFlat(true);

        horizontalLayout_4->addWidget(btnPrevious);

        btnNext = new QPushButton(groupBox);
        btnNext->setObjectName(QStringLiteral("btnNext"));
        btnNext->setEnabled(false);
        btnNext->setMinimumSize(QSize(32, 32));
        btnNext->setMaximumSize(QSize(32, 32));
        btnNext->setIcon(icon3);
        btnNext->setIconSize(QSize(32, 32));
        btnNext->setFlat(true);

        horizontalLayout_4->addWidget(btnNext);

        btnRun = new QPushButton(groupBox);
        btnRun->setObjectName(QStringLiteral("btnRun"));
        btnRun->setEnabled(false);
        btnRun->setMinimumSize(QSize(32, 32));
        btnRun->setMaximumSize(QSize(32, 32));
        btnRun->setIcon(icon4);
        btnRun->setIconSize(QSize(32, 32));
        btnRun->setFlat(true);

        horizontalLayout_4->addWidget(btnRun);

        btnStop = new QPushButton(groupBox);
        btnStop->setObjectName(QStringLiteral("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setMinimumSize(QSize(32, 32));
        btnStop->setMaximumSize(QSize(32, 32));
        btnStop->setIcon(icon5);
        btnStop->setIconSize(QSize(32, 32));
        btnStop->setFlat(true);

        horizontalLayout_4->addWidget(btnStop);


        verticalLayout->addLayout(horizontalLayout_4);

        txtEditorGCode = new QTextEdit(groupBox);
        txtEditorGCode->setObjectName(QStringLiteral("txtEditorGCode"));
        txtEditorGCode->setEnabled(true);
        txtEditorGCode->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        txtEditorGCode->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        txtEditorGCode->setReadOnly(true);

        verticalLayout->addWidget(txtEditorGCode);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(220, 456));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setSpacing(4);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(4, 4, 4, 4);
        txtEditorVAXCode = new QTextEdit(groupBox_2);
        txtEditorVAXCode->setObjectName(QStringLiteral("txtEditorVAXCode"));
        txtEditorVAXCode->setEnabled(true);
        txtEditorVAXCode->setReadOnly(true);

        gridLayout_3->addWidget(txtEditorVAXCode, 1, 0, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 32));
        label->setMaximumSize(QSize(16777215, 32));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalLayout_2->setStretch(1, 10);
        horizontalLayout_2->setStretch(2, 10);

        gridLayout->addLayout(horizontalLayout_2, 0, 0, 4, 7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(416, 0));
        groupBox_3->setMaximumSize(QSize(600, 16777215));
        groupBox_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        gridLayout_5 = new QGridLayout(groupBox_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 18));
        label_3->setMaximumSize(QSize(16777215, 18));

        gridLayout_5->addWidget(label_3, 0, 1, 1, 1);

        scrollAreaStack = new QScrollArea(groupBox_3);
        scrollAreaStack->setObjectName(QStringLiteral("scrollAreaStack"));
        scrollAreaStack->setFrameShape(QFrame::StyledPanel);
        scrollAreaStack->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaStack->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaStack->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollAreaStack->setWidgetResizable(true);
        frameStack = new QWidget();
        frameStack->setObjectName(QStringLiteral("frameStack"));
        frameStack->setGeometry(QRect(0, 0, 125, 232));
        verticalLayout_3 = new QVBoxLayout(frameStack);
        verticalLayout_3->setSpacing(1);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        scrollAreaStack->setWidget(frameStack);

        gridLayout_5->addWidget(scrollAreaStack, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 18));
        label_4->setMaximumSize(QSize(16777215, 18));

        gridLayout_5->addWidget(label_4, 0, 3, 1, 1);

        scrollAreaGraph = new QScrollArea(groupBox_3);
        scrollAreaGraph->setObjectName(QStringLiteral("scrollAreaGraph"));
        scrollAreaGraph->setFrameShape(QFrame::StyledPanel);
        scrollAreaGraph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaGraph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaGraph->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollAreaGraph->setWidgetResizable(true);
        frameGraph = new QWidget();
        frameGraph->setObjectName(QStringLiteral("frameGraph"));
        frameGraph->setGeometry(QRect(0, 0, 126, 232));
        verticalLayout_4 = new QVBoxLayout(frameGraph);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        scrollAreaGraph->setWidget(frameGraph);

        gridLayout_5->addWidget(scrollAreaGraph, 1, 3, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 18));
        label_5->setMaximumSize(QSize(16777215, 18));

        gridLayout_5->addWidget(label_5, 0, 5, 1, 1);

        scrollAreaDump = new QScrollArea(groupBox_3);
        scrollAreaDump->setObjectName(QStringLiteral("scrollAreaDump"));
        scrollAreaDump->setFrameShape(QFrame::StyledPanel);
        scrollAreaDump->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaDump->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaDump->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollAreaDump->setWidgetResizable(true);
        frameDump = new QWidget();
        frameDump->setObjectName(QStringLiteral("frameDump"));
        frameDump->setGeometry(QRect(0, 0, 125, 232));
        verticalLayout_5 = new QVBoxLayout(frameDump);
        verticalLayout_5->setSpacing(1);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        scrollAreaDump->setWidget(frameDump);

        gridLayout_5->addWidget(scrollAreaDump, 1, 5, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(416, 0));
        groupBox_4->setMaximumSize(QSize(600, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(4);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(4, 4, 4, 4);
        txtOutput = new QTextEdit(groupBox_4);
        txtOutput->setObjectName(QStringLiteral("txtOutput"));
        txtOutput->setReadOnly(true);

        gridLayout_4->addWidget(txtOutput, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_4);

        verticalLayout_2->setStretch(0, 6);
        verticalLayout_2->setStretch(1, 4);

        gridLayout->addLayout(verticalLayout_2, 0, 7, 4, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1102, 30));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("Images/arrow-back.png"), QSize(), QIcon::Normal, QIcon::Off);
        menuRun->setIcon(icon10);
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuFile->addAction(tsmiOpen);
        menuFile->addSeparator();
        menuFile->addAction(tsmiTranslate);
        menuFile->addAction(tsmiClear);
        menuFile->addAction(tsmiSaveGCode);
        menuFile->addAction(tsmiSaveVAXCode);
        menuFile->addSeparator();
        menuFile->addAction(tsmiClose);
        menuRun->addAction(tsmiRestart);
        menuRun->addSeparator();
        menuRun->addAction(tsmiNext);
        menuRun->addAction(tsmiPrevious);
        menuRun->addAction(tsmiRun);
        menuRun->addAction(tsmiStop);

        retranslateUi(MainWindow);

        btnTranslate->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GCode Executor", 0));
        tsmiOpen->setText(QApplication::translate("MainWindow", "&Open", 0));
        tsmiSaveGCode->setText(QApplication::translate("MainWindow", "&Save G Code", 0));
        tsmiSaveVAXCode->setText(QApplication::translate("MainWindow", "Save &VAX Code", 0));
        tsmiPrevious->setText(QApplication::translate("MainWindow", "&Previous Command", 0));
        tsmiNext->setText(QApplication::translate("MainWindow", "&Next Command", 0));
        tsmiRun->setText(QApplication::translate("MainWindow", "&Run Commands", 0));
        tsmiStop->setText(QApplication::translate("MainWindow", "&Stop Execution", 0));
        tsmiRestart->setText(QApplication::translate("MainWindow", "&Evaluate", 0));
        tsmiAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        tsmiClose->setText(QApplication::translate("MainWindow", "Close &Program", 0));
        tsmiClear->setText(QApplication::translate("MainWindow", "&Clear", 0));
        tsmiTranslate->setText(QApplication::translate("MainWindow", "&Translate to G Code", 0));
        groupBox_5->setTitle(QString());
        labelHaskell->setText(QApplication::translate("MainWindow", "Haskell code", 0));
        btnOpen->setText(QString());
        btnClear->setText(QString());
        btnTranslate->setText(QString());
#ifndef QT_NO_TOOLTIP
        groupBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        groupBox->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        groupBox->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        btnRestart->setText(QString());
        btnPrevious->setText(QString());
        btnNext->setText(QString());
        btnRun->setText(QString());
        btnStop->setText(QString());
        label->setText(QApplication::translate("MainWindow", "VAX Code", 0));
        label_3->setText(QApplication::translate("MainWindow", "Stack", 0));
        label_4->setText(QApplication::translate("MainWindow", "Graph", 0));
        label_5->setText(QApplication::translate("MainWindow", "Dump", 0));
        label_6->setText(QApplication::translate("MainWindow", "Output", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", 0));
        menuRun->setTitle(QApplication::translate("MainWindow", "&Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
