// default_test.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: archivo de pruebas principal.

#include <iostream>
#include "../src/basicinteger.h"
#include "../src/arrayinteger.h"
#include "../src/integer.h"

using namespace std;

int main()
{
  // ArrayInteger a1(string(ArrayInteger::getMaximumSize() * BasicInteger::DigitNumber(),'9'));
  // BasicInteger a2(BasicInteger::MaximumNumberPlusOne() - 1);
  // cout << "-- ArrayIntegers --" << endl;
  // cout << a1.toString() << endl;
  // cout << a2.toString() << endl;
  // 
  // ArrayInteger carriage;
  // ArrayInteger result = a1.Multiplication(a1, &carriage);

  // cout << endl << carriage.toString() << result.fullString() << endl;
  
  // BasicInteger a2(BasicInteger::MaximumNumberPlusOne() - 1);
  // cout << "a2: " << endl << a2.toString() << endl << endl;
  // cout << "complemento: " << endl << a2.Complement().fullString() << endl << endl;
  // cout << "complemento+1: " << endl << a2.Complement().Addition(1).fullString() << endl << endl;
  // ArrayInteger temp(string(ArrayInteger::getMaximumSize() * BasicInteger::DigitNumber(),'9'));
  // cout << "temp: " << endl << temp.fullString() << endl << endl;
  // cout << "complemento: " << endl << temp.Complement().fullString() << endl << endl;
  // cout << "complemento+1: " << endl << temp.Complement().Addition(1).fullString() << endl << endl;
  // Integer number(string(ArrayInteger::getMaximumSize() * BasicInteger::DigitNumber() * 3,'9'));
  // cout << "number: " << endl << number << endl << endl;
  // cout << "complemento: " << endl << number.Complement() << endl << endl;
  // cout << "complemento+1: " << endl << number.Complement() + 1 << endl << endl;

  Integer n1(string(600, '9'));
  Integer n2(string(350, '7'));

  cout << "n1: " << endl << n1 << endl << endl;
  // cout << "complemento: " << endl << n1.Complement() << endl << endl;
  // cout << "complemento+1: " << endl << n1.Complement(n2.getCurrentSize()) + 1 << endl << endl;
  cout << "n2: " << endl << n2 << endl << endl;
  // cout << "complemento: " << endl << n2.Complement() << endl << endl;
  // cout << "complemento+1: " << endl << n2.Complement(n1.getCurrentSize()) + 1 << endl << endl;
  cout << "n1 - n2: " << endl << n1 - n2 << endl << endl;
  cout << "n2 - n1: " << endl << n2 - n1 << endl << endl;
  cout << "n2 + n1: " << endl << n2 + n1 << endl << endl;
   
  Integer counter(0);
  while (true)
  {
    cout << counter << endl;
    counter = counter + 1;
  }

  return EXIT_SUCCESS;
}
