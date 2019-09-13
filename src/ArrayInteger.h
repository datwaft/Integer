// arrayinteger.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la declaración del array que amplia el almacenamiento.

#ifndef INTEGER_SRC_ARRAYINTEGER_H_
#define INTEGER_SRC_ARRAYINTEGER_H_

#include <string>

#include "pair.h"
#include "basicinteger.h"

class ArrayInteger
{
 public:
  static const short kBytes = 128;
  ArrayInteger(const int& = 0);
	ArrayInteger(const long&);
  ArrayInteger(const std::string&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  ~ArrayInteger();
  void setInteger(const int&);
  void setInteger(const long&);
  void setInteger(const std::string&);
  short getCurrentSize() const;
  static short getMaximumSize();
  bool operator == (const ArrayInteger&) const;
  bool operator != (const ArrayInteger&) const;
  bool operator > (const ArrayInteger&) const;
  bool operator < (const ArrayInteger&) const;
  bool operator >= (const ArrayInteger&) const;
  bool operator <= (const ArrayInteger&) const;
	ArrayInteger Addition(const ArrayInteger&, ArrayInteger* = nullptr) const;
	ArrayInteger Substraction(const ArrayInteger&, ArrayInteger* = nullptr) const;
	ArrayInteger Multiplication(const ArrayInteger&, ArrayInteger* = nullptr) const;
	ArrayInteger Division(const ArrayInteger&) const;
  std::string toString() const;
  std::string fullString() const; 
 private:
  static short MaximumSize();
  static short maximum_size_;
  short current_size_;
  BasicInteger* data_;
};

#endif // INTEGER_SRC_ARRAYINTEGER_H_
