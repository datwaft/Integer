#ifndef INTEGER_SRC_INTEGER_H_
#define INTEGER_SRC_INTEGER_H_

#include "basicinteger.h"
#include "arrayinteger.h"
#include "nodeinteger.h"

class Integer
{
public:
  Integer(const int& = 0);
  Integer(const long&);
  Integer(const std::string&);
  Integer(const BasicInteger&);
  Integer(const ArrayInteger&);
  Integer(const NodeInteger&);
  Integer(const Integer&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  void operator = (const BasicInteger&);
  void operator = (const ArrayInteger&);
  void operator = (const NodeInteger&);
  void operator = (const Integer&);
  ~Integer();
  void setInteger(const int&);
  void setInteger(const long&);
  void setInteger(const std::string&);
  void setInteger(const BasicInteger&);
  void setInteger(const ArrayInteger&);
  void setInteger(const NodeInteger&);
  void setInteger(const Integer&);
  int getCurrentSize() const;
  bool operator == (const Integer&) const;
  bool operator != (const Integer&) const;
  bool operator > (const Integer&) const;
  bool operator < (const Integer&) const;
  bool operator >= (const Integer&) const;
  bool operator <= (const Integer&) const;
  Integer Addition(const Integer&) const;
  Integer Substraction(const Integer&) const;
  Integer Multiplication(const Integer&) const;
  Integer Division(const Integer&) const;
  std::string toString() const;
  std::string fullString() const;
private:
  int current_size_;
  NodeInteger* first_;
};

#endif // INTEGER_SRC_INTEGER_H_
