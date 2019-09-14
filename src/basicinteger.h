// basicinteger.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la declaración de la clase más básica que compone
//              la clase Integer.

#ifndef INTEGER_SRC_BASICINTEGER_H_
#define INTEGER_SRC_BASICINTEGER_H_

#include <string>
#include <exception>
#include <cmath>

class BasicInteger
{
 public:
  using Base = int;
  BasicInteger(const int& = 0);
  BasicInteger(const long&);
  BasicInteger(const std::string&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  short CurrentSize() const;
  static short DigitNumber();
  bool operator == (const BasicInteger&) const;
  bool operator != (const BasicInteger&) const;
  bool operator > (const BasicInteger&) const;
  bool operator < (const BasicInteger&) const;
  bool operator >= (const BasicInteger&) const;
  bool operator <= (const BasicInteger&) const;
  BasicInteger Addition(const BasicInteger&, BasicInteger* = nullptr) const;
  BasicInteger Substraction(const BasicInteger&) const;
  BasicInteger Multiplication(const BasicInteger&, BasicInteger* = nullptr) const;
  BasicInteger Division(const BasicInteger&) const;
  static Base MaximumNumberPlusOne();
  std::string toString() const;
  std::string fullString() const;
 private:
  static short CalculateDigitNumber();
  static short digitnumber_;
  Base data_;
};

#endif // INTEGER_SRC_BASICINTEGER_H_
