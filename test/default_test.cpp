// default_test.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: archivo con las pruebas principales para la clase Integer.

#include <iostream>
#include "../src/integer.h"

int main()
{
  Integer n1(std::string(300, '9'));
  Integer n2(std::string(500, '7'));

  std::cout << Integer(std::string(9, '9')) / Integer(std::string(4, '5')) << std::endl;
    
  std::cout << "9.9999e299: " << std::endl;
  std::cout << n1 << std::endl;
  std::cout << std::endl;

  std::cout << "7.7777e499: " << std::endl;
  std::cout << n2 << std::endl;
  std::cout << std::endl;

  std::cout << "Test 1: 9.9999e299 * 7.7777e499" << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << n1 * n2 << std::endl;
  std::cout << std::endl;

  std::cout << "Test 2: 9.9999e299 + 7.7777e499" << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << n1 + n2 << std::endl;
  std::cout << std::endl;

  std::cout << "Test 3: 9.9999e299 - 7.7777e499" << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << n1 - n2 << std::endl;
  std::cout << std::endl;

  std::cout << "Test 4: 7.7777e499 / 9.9999e299" << std::endl;
  std::cout << "Resultado: " << std::endl;
  std::cout << n2 / n1 << std::endl;
  std::cout << std::endl;

  std::cout << "Test 5: 1000!" << std::endl;
  std::cout << Integer::Factorial(1000) << std::endl;
  std::cout << std::endl;

  std::cout << "Test 6: Fibonacci(1000)" << std::endl;
  std::cout << Integer::Fibonacci(1000) << std::endl;
  std::cout << std::endl;

  std::cout << "Test 7: Combinations(1000, 350) y Combinations(1000, 650)" << std::endl;
  std::cout << "Nota: dura bastante haciendo todas las combinaciones." << std::endl;
  Integer result = Integer::Combinations(1000, 350);
  std::cout << (result == Integer::Combinations(1000, 650) ? "Son equivalentes." : "No son equivalentes.") << std::endl;
  std::cout << result << std::endl;
  std::cout << std::endl;

  std::cout << "Test 8: Combinations(1000, 500)" << std::endl;
  std::cout << Integer::Combinations(1000, 500) << std::endl;
  std::cout << std::endl;

  return EXIT_SUCCESS;
}
