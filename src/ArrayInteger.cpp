// arrayinteger.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la implementación del array que amplia el almacenamiento.

#include "ArrayInteger.h"

short ArrayInteger::maximum_size_ = ArrayInteger::MaximumSize();

ArrayInteger::ArrayInteger(const int& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

ArrayInteger::ArrayInteger(const long& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

ArrayInteger::ArrayInteger(const std::string& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const int& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const long& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const std::string& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

ArrayInteger::~ArrayInteger()
{
  delete[] this->data_;
}

void ArrayInteger::setInteger(const int& integer)
{
  current_size_ = 0;
  int aux = integer;
  while (aux != 0 && current_size_ < maximum_size_)
  {
    data_[current_size_++] = aux % BasicInteger::MaximumNumberPlusOne();
    aux = aux / BasicInteger::MaximumNumberPlusOne();
  }
}

void ArrayInteger::setInteger(const long& integer)
{
  current_size_ = 0;
  int aux = integer;
  while (aux != 0 && current_size_ < maximum_size_)
  {
    data_[current_size_++] = aux % BasicInteger::MaximumNumberPlusOne();
    aux = aux / BasicInteger::MaximumNumberPlusOne();
  }
}

void ArrayInteger::setInteger(const std::string& string)
{
  current_size_ = 0;
  std::string aux = string;
  while (aux.size() != 0 && current_size_ < maximum_size_)
  {
    if (aux.size() > BasicInteger::DigitNumber())
    {
      data_[current_size_++] = aux.substr(aux.size() - BasicInteger::DigitNumber());
      aux = aux.substr(aux.size() - BasicInteger::DigitNumber());
    }
    else
    {
      data_[current_size_++] = aux;
      aux.clear();
    }
  }
}

short ArrayInteger::getCurrentSize() const
{
  return this->current_size_;
}

short ArrayInteger::getMaximumSize()
{
  return ArrayInteger::maximum_size_;
}

bool ArrayInteger::operator==(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator!=(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator>(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator<(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator>=(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator<=(const ArrayInteger& other) const
{
  return false;
}

ArrayInteger ArrayInteger::Addition(const ArrayInteger& other, ArrayInteger* carriage) const
{
  // TODO
}

ArrayInteger ArrayInteger::Substraction(const ArrayInteger& other, ArrayInteger* carriage) const
{
  // TODO
}

ArrayInteger ArrayInteger::Multiplication(const ArrayInteger& other, ArrayInteger* carriage) const
{
  // TODO
}

ArrayInteger ArrayInteger::Division(const ArrayInteger& other) const
{
  // TODO
}

short ArrayInteger::MaximumSize()
{
  return kBytes / sizeof(BasicInteger::Base);
}
