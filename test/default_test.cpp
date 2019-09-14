// default_test.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: archivo de pruebas principal.

#include <iostream>
#include <iostream>
#include "../src/basicinteger.h"
#include "../src/arrayinteger.h"

using namespace std;

int main()
{
	BasicInteger int1(999999999);
	BasicInteger int2(999999999);
 
  BasicInteger carriage;
  BasicInteger result = int1.Multiplication(int2, &carriage);

  cout << carriage.toString() << result.fullString() << std::endl;
  
  ArrayInteger a1("31234123412341234");
  ArrayInteger a2("67891234986723458745");
  
  cout << "-- ArrayIntegers --" << endl;
  cout << a1.toString() << endl;
  cout << a2.toString() << endl;

  cout << a1.Substraction(a2).toString() << endl;
  cout << a2.Substraction(a1).toString() << endl;

  return EXIT_SUCCESS;
}
