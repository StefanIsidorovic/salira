#include "executor.h"

static Executor *instance = nullptr;
const int STACK_SIZE = 256;

Executor::Executor()
{
}

Executor& Executor::Instance()
{
    static Executor instance;
    return instance;
}

QList<State> Executor::states()
{
    return this->_states;
}

State Executor::currentState()
{
    return this->_currentState;
}

int Executor::valueOfGraphNode(int id, State state)
{
    for(int i = 0; i < state.graph().length(); i++)
        if(state.graph()[i].id() == id)
            return state.graph()[i].value();
    throw "Unknown node!";
}

GraphNodeType Executor::typeOfGraphNode(int id, State state)
{
    for(int i = 0; i < state.graph().length(); i++)
        if(state.graph()[i].id() == id)
            return state.graph()[i].type();
    throw "Unknown node!";
}

QString Executor::nameOfGraphNode(int id, State state)
{
    for(int i = 0; i < state.graph().length(); i++)
        if(state.graph()[i].id() == id)
            return state.graph()[i].functionName();
    throw "Unknown node!";
}

int Executor::argOfFunction(QString name, QList<GCommand> commands)
{
    for(int i = 0; i < commands.length(); i++)
        if(commands[i].value() == "GLOBSTART" && commands[i].args()[0]->ToString() == name)
            return commands[i].args()[1]->ToString().toInt();
    return -1;
}

bool Executor::Init(QList<GCommand> commands, QString& errorMessage)
{
    this->Reset();

    State initialState = State(0);
    this->_states.push_back(initialState);

    State nextState = State();
    State state = State();

    for (int i = 0; i < commands.length(); i++)
    {
        GCommand command = commands[i];
        state = nextState;

        if(!(this->_states.last().GetNext(command, nextState, commands, i)))
        {
            errorMessage = nextState.errorMessage();;
            return false;
        }

        if(command.value() == "END")
        {
            this->_states.push_back(nextState);
            break;
        }

        if(nextState.command().value() == "JUMP")
        {
            QString labelName = nextState.command().args()[0]->ToString();

            for(int j = 0; j < commands.length(); j++)
            {
                if(commands[j].ToString() == QString("LABEL " + labelName + ";"))
                {
                    i = j - 1;
                    break;
                }
            }
        }

        if(nextState.command().value() == "JFALSE" && valueOfGraphNode(state.stack().last(), state) == 0)
        {
            QString labelName = nextState.command().args()[0]->ToString();

            for(int j = 0; j < commands.length(); j++)
            {
                if(commands[j].ToString() == QString("LABEL " + labelName + ";"))
                {
                    i = j - 1;
                    break;
                }
            }
        }

        if(nextState.command().value() == "RETURN")
        {
            if(State::returnTo().length() > 0)
            {
                i = nextState._returnTo.pop();
                continue;
            }
        }

        if(nextState.command().value() == "EVAL")
        {
            QString funName = nameOfGraphNode(state.stack().last(), nextState);

            for(int j = 0; j < commands.length(); j++)
            {
                if(commands[j].ToString() == QString("GLOBSTART " + funName + " 0;"))
                {
                    i = j-1;
                    break;
                }
            }
        }

        if(nextState.command().value() == "UNWIND")
        {
            QString funName = nameOfGraphNode(state.stack().last(), nextState);
            int arg = argOfFunction(funName, commands);

            if((funName == "$NEG" || state.stack().length() > arg)
                    && State::returnTo().length() > 0)
            {
                i = nextState._returnTo.pop();
            }
        }

        this->_states.push_back(nextState);

        if(_states.length() >= STACK_SIZE)
        {
            errorMessage = "Error: Stack or Graph overflow! It is possible that there is an infinite loop on input!";
            return false;
        }
    }

    if(this->_states.length() < 3)
    {
        errorMessage = "Error: GCode must contain minimum two commands!";
        return false;
    }

    this->_currentState = this->_states[0];
    return true;
}

void Executor::Execute(bool forward)
{
    if(forward)
    {
        while(_currentState.id() < State::maxID() && this->_states[this->_currentState.id() + 1].command().value() == "")
            _currentState = this->_states[_currentState.id() + 1];
    }
    else
    {
        while(_currentState.id() > 0 && this->_states[this->_currentState.id() - 1].command().value() == "")
            _currentState = this->_states[_currentState.id() - 1];
    }
}

void Executor::ExecuteNext()
{
    this->Execute(true);
    if(_currentState.id() < State::maxID())
        _currentState = this->_states[_currentState.id() + 1];
}

void Executor::ExecutePrevious()
{
    this->Execute(false);
    if(_currentState.id() > 0)
        _currentState = this->_states[_currentState.id() - 1];
}

void Executor::Reset()
{
    this->_states.clear();
    this->currentState() = State();
    State::setMaxID(0);
}
