// default_test.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: archivo de pruebas principal.

#include <iostream>
#include <iostream>
#include "../src/basicinteger.h"
#include "../src/pair.h"

using namespace std;

int main()
{
	BasicInteger int1(999999999);
	BasicInteger int2(999999999);
 
  BasicInteger carriage;
  BasicInteger result = int1.Multiplication(int2, &carriage);

  cout << carriage.toString() << result.fullString() << std::endl;
  
  return EXIT_SUCCESS;
}
