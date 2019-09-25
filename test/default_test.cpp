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
  ArrayInteger a1(string(ArrayInteger::getMaximumSize() * BasicInteger::DigitNumber(),'9'));
  BasicInteger a2(BasicInteger::MaximumNumberPlusOne() - 1);
  cout << "-- ArrayIntegers --" << endl;
  cout << a1.toString() << endl;
  cout << a2.toString() << endl;
  
  cout << "a1: " << a1.getCurrentSize() << endl;
  cout << "a1.maximum size: " << a1.getMaximumSize() << endl;
  cout << "a2: " << a2.CurrentSize() << endl;
  cout << "a2.digits: " << a2.DigitNumber() << endl;

  ArrayInteger carriage;
  ArrayInteger result = a1.Multiplication(a1, &carriage);

  cout << endl << carriage.toString() << result.fullString() << endl;

  return EXIT_SUCCESS;
}
