// arrayinteger.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la declaración del array que amplia el almacenamiento.

#ifndef INTEGER_SRC_ARRAYINTEGER_H_
#define INTEGER_SRC_ARRAYINTEGER_H_

#include <string>
#include <iostream>

#include "basicinteger.h"

class ArrayInteger
{
 public:
  static const short kBytes = 128;
  ArrayInteger(const int& = 0);
	ArrayInteger(const long&);
  ArrayInteger(const std::string&);
  ArrayInteger(const BasicInteger&);
  ArrayInteger(const ArrayInteger&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  void operator = (const BasicInteger&);
  void operator = (const ArrayInteger&);
  ~ArrayInteger();
  void setInteger(const int&);
  void setInteger(const long&);
  void setInteger(const std::string&);
  void setInteger(const BasicInteger&);
  short getCurrentSize() const;
  static short getMaximumSize();
  short getDigits() const;
  bool operator == (const ArrayInteger&) const;
  bool operator != (const ArrayInteger&) const;
  bool operator > (const ArrayInteger&) const;
  bool operator < (const ArrayInteger&) const;
  bool operator >= (const ArrayInteger&) const;
  bool operator <= (const ArrayInteger&) const;
	ArrayInteger Addition(const ArrayInteger&, ArrayInteger* = nullptr) const;
	ArrayInteger Substraction(const ArrayInteger&) const;
	ArrayInteger Multiplication(const ArrayInteger&, ArrayInteger* = nullptr) const;
	ArrayInteger Multiplication(const BasicInteger&, BasicInteger* = nullptr) const;
	ArrayInteger Division(const ArrayInteger&) const;
  std::string toString() const;
  std::string fullString() const; 
 protected:
  static short MaximumSize();
  bool addBasicInteger(const BasicInteger&);
  void Split(ArrayInteger*, ArrayInteger*, short) const;
  ArrayInteger AddPadding(short, ArrayInteger* = nullptr) const;
  void recalculateCurrentSize();
  static short maximum_size_;
  short current_size_;
  BasicInteger* data_;
};

#endif // INTEGER_SRC_ARRAYINTEGER_H_
