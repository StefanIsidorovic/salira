#ifndef SALIRA_TYPES_H__
#define SALIRA_TYPES_H__

#include "expression.hh"
/*
 * Primitive value class which inherits expression. Purpose is to identify constant values
 * inside of expression tree. Currently is implemented as template class but in future can be
 * derivated so can represent more complex values as lists, strings, object, etc.
 * 
 */
class PrimitiveValue : public ExpressionBase {
public:
    PrimitiveValue() 
      : ExpressionBase(true){}
    virtual bool isConstant() const {return true;}
    virtual bool isToken() {return false;}
    virtual Expression eval(const std::vector<Expression>& values) const =0;
    
};

/* 
 * Derived Primitive Value class SaliraInt which basically represents integer.
 */

class SaliraInt : public PrimitiveValue {
private:
  int _value;
public:
  SaliraInt(int value) : PrimitiveValue(), _value(value) {}
  virtual std::string print() const { return std::string("SaliraInt: ")+std::to_string(_value); }
  inline int value() { return _value; }
  inline void setValue(int new_value) { _value = new_value;}
  virtual Type getType() const {return S_INT;};
  
  virtual bool isConstant() const {return true;}
  virtual bool isToken() const {return false;}
  // Eval
  virtual Expression eval(const std::vector<Expression>& values) const {
    return new SaliraInt(_value);
  }
};

/*
 * Derived Primitive Value class SaliraDouble. Represents double.
 */
class SaliraDouble : public PrimitiveValue {
private:
  double _value;
public:
  SaliraDouble(double value) : PrimitiveValue(), _value(value) {}
  virtual std::string print() const { return std::string("SaliraDouble: ")+std::to_string(_value); }
  inline double value() { return _value; }
  inline void setValue(double new_value) { _value = new_value;}
  virtual Type getType() const {return S_DOUBLE;};
  virtual bool isConstant() const {return true;}
  virtual bool isToken() const {return false;}
  
  // Eval
  virtual Expression eval(const std::vector<Expression>& values) const {
    return new SaliraDouble(_value);
  }  
};

/* 
 * Type which will represent lists. Concept still need to be worked out. 
 * But initialy it will represent array of PrimitiveValues, with checking types.
 */

class SaliraList : public ExpressionBase {
private:
  Type _type_of_elements;
  std::vector<Expression> _elements;
public:
  SaliraList(Type type, std::vector<Expression> arr) : _type_of_elements(type), _elements(arr) {}
  virtual bool isToken() const {return false;}
  virtual bool isConstant() const {return false;}
  virtual std::string print() {return std::string("List");}
  virtual Type getType() const {return T_LIST;}
  virtual Expression eval(const std::vector<Expression>& values)const { return new SaliraInt(-1);}
  
  
};

/*
 * Dummy class which will represent arguments in function. More precisely it represent places where arguments
 * should be placed inside of Expressiovn tree.  
 * 
 * Token changed so it can represent more types.
 */

class Token : public ExpressionBase {
private:
  int _placement;
  Type _type;
public:
  virtual bool isToken() const { return true; }
  virtual bool isConstant() const { return false; }
  virtual Expression eval(const std::vector<Expression>& values) const{ 
    // NOTE: Possible problem, not sure yet
    // Inside of recursive iteration one of tokens can be another function, problem is giving aditional 
    // arguments for that function. Possibility of different values vector which next line couldn't solve
    // Again not sure, its 2:46am
    return values[_placement]->eval(values);
  }
  virtual Type getType() const {return _type;}
  Token(int place, Type type) : _placement(place), _type(type), ExpressionBase(false) {}
  virtual std::string print() const { 
    std::string p1("Token: ");
    switch(_type){
      case S_INT:
	return p1+std::string("int");
      case S_DOUBLE:
	return p1 + std::string("double");
      default:
	return p1 + std::string(" just token");
    }
  }
};


#endif // SALIRA_TYPES_H__