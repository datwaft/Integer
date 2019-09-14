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

ArrayInteger::ArrayInteger(const BasicInteger& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

ArrayInteger::ArrayInteger(const ArrayInteger& other)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = other.current_size_;
  for (short i = 0; i < other.current_size_; ++i)
    this->data_[i] = other.data_[i];
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

void ArrayInteger::operator=(const BasicInteger& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const ArrayInteger& other)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = other.current_size_;
  for (short i = 0; i < other.current_size_; ++i)
    this->data_[i] = other.data_[i];
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
  long aux = integer;
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
    if (static_cast<short>(aux.size()) > BasicInteger::DigitNumber())
    {
      data_[current_size_++] = aux.substr(aux.size() - BasicInteger::DigitNumber());
      aux = aux.substr(0, aux.size() - BasicInteger::DigitNumber());
    }
    else
    {
      data_[current_size_++] = aux;
      aux.clear();
    }
  }
}

void ArrayInteger::setInteger(const BasicInteger& data)
{
  current_size_ = 1;
  data_[0] = data;
  if (data_[0] == 0)
    current_size_ = 0;
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
  if (current_size_ != other.current_size_)
    return false;
  for(short i = 0; i < current_size_; i++)
    if(data_[i] != other.data_[i])
      return false;
  return true;
}

bool ArrayInteger::operator!=(const ArrayInteger& other) const
{
  return !(*this == other);
}

bool ArrayInteger::operator>(const ArrayInteger& other) const
{
  if (current_size_ > other.current_size_)
    return true;
  if (current_size_ < other.current_size_)
    return false;
  for (short i = current_size_ - 1; i >= 0; --i)
  {
    if (data_[i] <= other.data_[i])
      return false;
  }
  return true;
}

bool ArrayInteger::operator<(const ArrayInteger& other) const
{
  if (current_size_ > other.current_size_)
    return false;
  if (current_size_ < other.current_size_)
    return true;
  for (short i = current_size_ - 1; i >= 0; --i)
  {
    if (data_[i] >= other.data_[i])
      return false;
  }
  return true;
}

bool ArrayInteger::operator>=(const ArrayInteger& other) const
{
  if (current_size_ > other.current_size_)
    return true;
  if (current_size_ < other.current_size_)
    return false;
  for (short i = current_size_ - 1; i >= 0; --i)
  {
    if (data_[i] < other.data_[i])
      return false;
  }
  return true;
}

bool ArrayInteger::operator<=(const ArrayInteger& other) const
{
  if (current_size_ > other.current_size_)
    return false;
  if (other.current_size_ > current_size_)
    return true;
  for (short i = current_size_ - 1; i >= 0; --i)
  {
    if (data_[i] > other.data_[i])
      return false;
  }
  return true;
}

ArrayInteger ArrayInteger::Addition(const ArrayInteger& other, ArrayInteger* carriage) const
{
  // TODO
  return ArrayInteger();
}

ArrayInteger ArrayInteger::Substraction(const ArrayInteger& other) const
{
  short bigger_size = (current_size_ >= other.current_size_ ? current_size_ : other.current_size_);
  ArrayInteger result;
  BasicInteger carriage_result(11);

  short i;
  for (i = 0; i < bigger_size; ++i)
  {
    result.data_[i] = data_[i].Substraction(other.data_[i]);
  }

  result.current_size_ = bigger_size;
  return result;
}

ArrayInteger ArrayInteger::Multiplication(const ArrayInteger& other, ArrayInteger* carriage) const
{
  short max = (current_size_ >= other.current_size_ ? current_size_ : other.current_size_);

  ArrayInteger result;
  (*carriage) = ArrayInteger();

  BasicInteger aux1;
  BasicInteger aux2;

  for (short i = 0; i < max; ++i)
  {
    for (short j = 0; j < max; ++j)
    {
      aux1 = data_[i].Multiplication(other.data_[j], &aux2);
    }
  }

  return result;
}

ArrayInteger ArrayInteger::Division(const ArrayInteger& other) const
{
  // TODO
  return ArrayInteger();
}

std::string ArrayInteger::toString() const
{
  if (current_size_ == 0)
    return "0";
  std::string result = data_[current_size_ - 1].toString();
   for (short i = current_size_ - 2; i >= 0; --i)
    result += data_[i].fullString();
  return result;
}

std::string ArrayInteger::fullString() const
{
  std::string result;
  for (short i = 0; i < maximum_size_ - current_size_; i++) 
    result += std::string(BasicInteger::DigitNumber(), '0'); 
  result += data_[current_size_ - 1].fullString();
  for (short i = current_size_ - 2; i >= 0; --i)
    result += data_[i].fullString();
  return result;
}

short ArrayInteger::MaximumSize()
{
  return kBytes / sizeof(BasicInteger::Base);
}

bool ArrayInteger::addBasicInteger(const BasicInteger& data)
{
  if (current_size_ < maximum_size_)
    data_[current_size_++] = data;
}

void ArrayInteger::recalculateCurrentSize()
{
  current_size_ = maximum_size_;
  while(current_size_ > 0 && data_[current_size_ - 1] == 0)
  {
    --current_size_;
  }
}
