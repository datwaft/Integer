// pair.h
// Autores: David Guevara & Mario Arguello
// Descripción: contiene una estructura para almacenar dos datos de tipo
//              cualquiera.

#ifndef INTEGER_SRC_PAIR_H_
#define INTEGER_SRC_PAIR_H_

template <class type1, class type2>
struct Pair
{
  type1 one;
  type2 two;
  Pair()
  {
    one = type1();
    two = type2();
  }
};

#endif // INTEGER_SRC_PAIR_H_