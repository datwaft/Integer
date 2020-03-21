// default_test.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: archivo con las pruebas principales para la clase Integer.

#include <iostream>
#include "../src/integer.h"

int main()
{
  Integer n1(std::string(300, '9'));
  Integer n2(std::string(500, '7'));

  std::cout << "Test 4: 7.7777e499 / 9.9999e299" << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << n2 / n1 << std::endl;
  std::cout << std::endl;
  std::cout << "Test 8: Combinations(1000, 500)" << std::endl;
  std::cout << Integer::Combinations(1000, 500) << std::endl;
  std::cout << std::endl;
}
