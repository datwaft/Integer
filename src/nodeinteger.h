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
  void operator=(const NodeInteger&);
  NodeInteger* getNext();
  NodeInteger* getPrev();
  NodeInteger* createNext(const NodeInteger&);
  NodeInteger* createPrev(const NodeInteger&);
  bool deleteNext();
  bool deletePrev();
 private:
  NodeInteger* next_;
  NodeInteger* prev_;
};

#endif // !INTEGER_SRC_NODEINTEGER_H_
