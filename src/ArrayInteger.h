#ifndef INTEGER_SRC_ARRAYINTEGER_H_
#define INTEGER_SRC_ARRAYINTEGER_H_

#include <string>

#include "pair.h"
#include "basicinteger.h"


class ArrayInteger
{
public:
	ArrayInteger(const int&);
	ArrayInteger(const std::string);
	Pair<ArrayInteger, ArrayInteger> Addition(const ArrayInteger&) const;
	Pair<ArrayInteger, ArrayInteger> Substraction(const ArrayInteger&) const;
	Pair<ArrayInteger, ArrayInteger> Multiplication(const ArrayInteger&) const;
	ArrayInteger Division(const ArrayInteger&) const;

private:
	BasicInteger arrayInteger[10]; //temp

};

#endif // INTEGER_SRC_ARRAYINTEGER_H_
