// nodeinteger.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la declaración del nodo que compone el Integer.

#ifndef INTEGER_SRC_NODEINTEGER_H_
#define INTEGER_SRC_NODEINTEGER_H_

#include <string>

#include "arrayinteger.h"

class NodeInteger: public ArrayInteger
{
 public:
  NodeInteger(const int& = 0);
	NodeInteger(const long&);
  NodeInteger(const std::string&);
  NodeInteger(const BasicInteger&);
  NodeInteger(const ArrayInteger&);
  NodeInteger(const NodeInteger&);
  NodeInteger* next;
};

#endif // !INTEGER_SRC_NODEINTEGER_H_
