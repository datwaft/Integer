// arrayinteger.cpp
// Autores: David Guevara & Mario Arguello
// Descripci�n: contiene la implementaci�n del array que amplia el almacenamiento.

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
  delete[] this->data_;
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const long& data)
{
  delete[] this->data_;
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const std::string& data)
{
  delete[] this->data_;
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const BasicInteger& data)
{
  delete[] this->data_;
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

void ArrayInteger::operator=(const ArrayInteger& other)
{
  delete[] this->data_;
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
  recalculateCurrentSize();
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
  recalculateCurrentSize();
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
  recalculateCurrentSize();
}

void ArrayInteger::setInteger(const BasicInteger& data)
{
  current_size_ = 1;
  data_[0] = data;
}

short ArrayInteger::getCurrentSize() const
{
  return this->current_size_;
}

short ArrayInteger::getMaximumSize()
{
  return ArrayInteger::maximum_size_;
}

short ArrayInteger::getDigits() const
{
  return BasicInteger::DigitNumber() * (current_size_ - 1) + data_[current_size_ - 1].CurrentSize();
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
    if (data_[i] < other.data_[i])
      return false;
    else if (data_[i] > other.data_[i])
      return true;
  }
  return false;
}

bool ArrayInteger::operator<(const ArrayInteger& other) const
{
  if (current_size_ > other.current_size_)
    return false;
  if (current_size_ < other.current_size_)
    return true;
  for (short i = current_size_ - 1; i >= 0; --i)
  {
    if (data_[i] > other.data_[i])
      return false;
    else if (data_[i] < other.data_[i])
      return true;
  }
  return false;
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
    else if (data_[i] > other.data_[i])
      return true;
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
    else if (data_[i] < other.data_[i])
      return true;
  }
  return true;
}

ArrayInteger ArrayInteger::Addition(const ArrayInteger& other, ArrayInteger* carriage) const
{
  if (other == 0)
    return *this;
	ArrayInteger result;
  BasicInteger operation_carriage;
	BasicInteger operation_carriage1;
	BasicInteger operation_carriage2;

	short i;
	for (i = 0; i < MaximumSize(); ++i)
	{
		result.data_[i] = data_[i].Addition(operation_carriage, &operation_carriage1).Addition(other.data_[i], &operation_carriage2);
    operation_carriage = operation_carriage1.Addition(operation_carriage2);
	}
  result.recalculateCurrentSize();
  if(carriage != nullptr)
    (*carriage) = operation_carriage;
	return result;
}

ArrayInteger ArrayInteger::Substraction(const ArrayInteger& other) const
{
  if (other == 0)
    return *this;
  ArrayInteger result;
  BasicInteger carriage;
  
  for (short i = 0; i < maximum_size_; ++i)
  {
    if (*this > other)
      result.data_[i] = data_[i].Addition(carriage).Addition(other.data_[i].Complement().Addition(i == 0 ? 1 : 0), &carriage);
    else
      result.data_[i] = other.data_[i].Addition(carriage).Addition(data_[i].Complement().Addition(i == 0 ? 1 : 0), &carriage);
  }
  result.recalculateCurrentSize();

  return result;
}

ArrayInteger ArrayInteger::Multiplication(const BasicInteger& number, BasicInteger* carriage) const
{
  ArrayInteger result;
  BasicInteger operation_carriage1;
  BasicInteger operation_carriage2;
  BasicInteger operation_carriage;
  for (short i = 0; i < this->maximum_size_; ++i)
  {
    result.data_[i] = this->data_[i].Multiplication(number, &operation_carriage1);
    result.data_[i] = result.data_[i].Addition(operation_carriage, &operation_carriage2);
    operation_carriage = operation_carriage1.Addition(operation_carriage2);
  }
  *carriage = operation_carriage;
  result.recalculateCurrentSize();
  return result;
}

ArrayInteger ArrayInteger::Complement() const
{
  ArrayInteger result;
  for (short i = 0; i < this->maximum_size_; ++i)
  {
    result.data_[i] = this->data_[i].Complement();
  }
  result.recalculateCurrentSize();
  return result;
}

std::string ArrayInteger::toString() const
{
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

BasicInteger ArrayInteger::First()
{
  return data_[0];
}

short ArrayInteger::MaximumSize()
{
  return kBytes / sizeof(BasicInteger::Base);
}

void ArrayInteger::recalculateCurrentSize()
{
  current_size_ = maximum_size_;
  while(current_size_ > 0 && data_[current_size_ - 1] == 0)
  {
    --current_size_;
  }
  if (current_size_ == 0)
  {
    current_size_ = 1;
  }
}
