#include "graphnode.h"

GraphNode::GraphNode()
{

}

GraphNode::GraphNode(GraphNodeType type)
    :_id(0), _idRef1(0), _idRef2(0), _type(type), _value(0)
{

}

GraphNode::GraphNode(int id, GraphNodeType type, int value)
    :_id(id), _idRef1(0), _idRef2(0), _type(type), _value(value)
{

}

GraphNode::GraphNode(int id, int idRef1, int idRef2, GraphNodeType type, int value, QString name)
    :_id(id),  _idRef1(idRef1), _idRef2(idRef2), _type(type), _value(value), _functionName(name)
{

}

GraphNode::~GraphNode()
{

}

int GraphNode::id()
{
    return this->_id;
}

int GraphNode::idRef1()
{
    return this->_idRef1;
}

int GraphNode::idRef2()
{
    return this->_idRef2;
}

GraphNodeType GraphNode::type()
{
    return this->_type;
}

QString GraphNode::functionName()
{
    return this->_functionName;
}

int GraphNode::value()
{
    return this->_value;
}

QString GraphNode::ToString()
{
    QString retValue;
    switch(this->_type)
    {
    case 0:
        retValue = "HOLE";
        break;
    case 1:
        retValue = "INTEGER\nNODE [" + QString::number(this->_id + 1) + "]\nValue = " + QString::number(this->_value);
        break;
    case 2:
        retValue = "FUNCTION\nNODE [" + QString::number(this->_id + 1) + "]\n" + this->_functionName;
        break;
    case 3:
        retValue = "CONST\nNODE[" + QString::number(this->_id + 1) + "]\nNODE [" + QString::number(this->_idRef1 + 1)
                + "]\nNODE [" + QString::number(this->_idRef2 + 1);
        break;
    case 4:
        retValue = "APPLICATION\nNODE[" + QString::number(this->_id + 1) + "]\nNODE [" + QString::number(this->_idRef1 + 1)
                + "]\nNODE [" + QString::number(this->_idRef2 + 1) + "]";
        break;
    }

    return retValue;
}

