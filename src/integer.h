#ifndef INTEGER_SRC_INTEGER_H_
#define INTEGER_SRC_INTEGER_H_

#include "basicinteger.h"

class Integer
{
public:
  static const short kBytes = 128;
  Integer(const int& = 0);
  Integer(const long&);
  Integer(const std::string&);
  Integer(const BasicInteger&);
  Integer(const Integer&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  void operator = (const BasicInteger&);
  void operator = (const Integer&);
  ~Integer();
  void setInteger(const int&);
  void setInteger(const long&);
  void setInteger(const std::string&);
  void setInteger(const BasicInteger&);
  short getCurrentSize() const;
  bool operator == (const Integer&) const;
  bool operator != (const Integer&) const;
  bool operator > (const Integer&) const;
  bool operator < (const Integer&) const;
  bool operator >= (const Integer&) const;
  bool operator <= (const Integer&) const;
  Integer Addition(const Integer&, Integer* = nullptr) const;
  Integer Substraction(const Integer&) const;
  Integer Multiplication(const Integer&, Integer* = nullptr) const;
  Integer Division(const Integer&) const;
  std::string toString() const;
  std::string fullString() const;
private:
  
};

#endif // INTEGER_SRC_INTEGER_H_
