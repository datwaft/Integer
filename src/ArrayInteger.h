#ifndef INTEGER_SRC_ARRAYINTEGER_H_
#define INTEGER_SRC_ARRAYINTEGER_H_

#include <string>

#include "pair.h"
#include "basicinteger.h"

class ArrayInteger
{
 public:
  ArrayInteger(const int&);
	ArrayInteger(const long&);
  ArrayInteger(const std::string&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  ~ArrayInteger();

  short getCurrentSize() const;
  static short getMaximumSize();

  bool operator == (const ArrayInteger&) const;
  bool operator != (const ArrayInteger&) const;
  bool operator > (const ArrayInteger&) const;
  bool operator < (const ArrayInteger&) const;
  bool operator >= (const ArrayInteger&) const;
  bool operator <= (const ArrayInteger&) const;

	Pair<ArrayInteger, ArrayInteger> Addition(const ArrayInteger&) const;
	Pair<ArrayInteger, ArrayInteger> Substraction(const ArrayInteger&) const;
	Pair<ArrayInteger, ArrayInteger> Multiplication(const ArrayInteger&) const;
	ArrayInteger Division(const ArrayInteger&) const;

  operator std::string();
 private:
  static short MaximumSize();

  static short maximum_size_;
  short current_size_;
  BasicInteger* data_;
};

#endif // INTEGER_SRC_ARRAYINTEGER_H_
