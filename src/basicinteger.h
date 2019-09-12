// basicinteger.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la declaración de la clase más básica que compone
//              la clase Integer.

#ifndef INTEGER_SRC_BASICINTEGER_H_
#define INTEGER_SRC_BASICINTEGER_H_

#include <string>
#include <exception>
#include <cmath>

#include "pair.h"

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

  Base getDigit(int) const;
  short getCurrentSize() const;
  static short getMaximumSize();

  bool operator == (const BasicInteger&) const;
  bool operator != (const BasicInteger&) const;
  bool operator > (const BasicInteger&) const;
  bool operator < (const BasicInteger&) const;
  bool operator >= (const BasicInteger&) const;
  bool operator <= (const BasicInteger&) const;

  Pair<BasicInteger, BasicInteger> Addition(const BasicInteger&) const;
  Pair<BasicInteger, BasicInteger> Substraction(const BasicInteger&) const;
  Pair<BasicInteger, BasicInteger> Multiplication(const BasicInteger&) const;
  BasicInteger Division(const BasicInteger&) const;

  operator std::string();
 private:
  static short MaximumSize();

  static short maximum_size_;
  short current_size_;
  Base data_;
};

#endif // INTEGER_SRC_BASICINTEGER_H_
