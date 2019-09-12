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
	BasicInteger test(999999999);
	BasicInteger test2(999999999);
	
	
	

	std::cout << string(test.Addition(test2).one) <<"    " << string(test.Addition(test2).two);

}
