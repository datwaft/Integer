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

ArrayInteger ArrayInteger::Multiplication(const ArrayInteger& other, ArrayInteger* carriage) const
{
  if (this->current_size_ == 1 || other.current_size_ == 1)
  {
    BasicInteger operation_carriage;
    ArrayInteger result;
    if (this->current_size_ == 1)
      result = other.Multiplication(this->data_[0], &operation_carriage);
    if (other.current_size_ == 1)
      result = this->Multiplication(other.data_[0], &operation_carriage);
    if(carriage != nullptr)
      *carriage = carriage->Addition(operation_carriage);
    return result;
  }

  short m = this->getDigits() <= other.getDigits() ? this->getDigits() : other.getDigits();
  short m2 = m/2;

  ArrayInteger high1;
  ArrayInteger low1;
  this->Split(&high1, &low1, m2);

  ArrayInteger high2;
  ArrayInteger low2;
  this->Split(&high2, &low2, m2);
  
  ArrayInteger operation_carriage;
  ArrayInteger z0 = low1.Multiplication(low2, &operation_carriage);
  if(carriage != nullptr)
    *carriage = carriage->Addition(operation_carriage);
  ArrayInteger z1 = (low1.Addition(high1)).Multiplication(low2.Addition(high2), &operation_carriage);
  if(carriage != nullptr)
    *carriage = carriage->Addition(operation_carriage);
  ArrayInteger z2 = high1.Multiplication(high2, &operation_carriage);
  if(carriage != nullptr)
    *carriage = carriage->Addition(operation_carriage);
  
  ArrayInteger carriage_aux;
  ArrayInteger result1 = z2.AddPadding(m2 * 2, &carriage_aux);
  if(carriage != nullptr)
    *carriage = carriage->Addition(carriage_aux);
  ArrayInteger result2 = (z1.Substraction(z2.Substraction(z0))).AddPadding(m2, &carriage_aux);
  if(carriage != nullptr)
    *carriage = carriage->Addition(carriage_aux);
  
  ArrayInteger carriage1;
  ArrayInteger carriage2;
  ArrayInteger final_result = result1.Addition(result2, &carriage1).Addition(z0, &carriage2);
  if(carriage != nullptr)
    *carriage = carriage->Addition(carriage1.Addition(carriage2));
  return final_result;
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

ArrayInteger ArrayInteger::Division(const ArrayInteger& other) const
{
 
 /* if (other == 0)
  {
    throw std::exception("Division by 0");
  }
  if (other > *this)
  {
    return 0;
  }
  if (other == 1)
  {
    return *this;
  }
  if (other == *this)
  {
    return 1;
  }*/
  ArrayInteger result = 0;
  ArrayInteger carriage;
  int counter = 0;
 
  while ((result < *this))
  {

    result = result.Addition(other, &carriage);
    counter++;
  
  }
  if (result > * this)
    return counter - 1;
  return counter;
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

bool ArrayInteger::Append(const BasicInteger& data)
{
  if (current_size_ < maximum_size_)
  {
    data_[current_size_++] = data;
    return true;
  }
  return false;
}

void ArrayInteger::Split(ArrayInteger* high, ArrayInteger* low, short division) const
{
  std::string string = this->toString();
  if (division >= static_cast<short>(string.length()))
  {
    *high = 0;
    *low = *this; 
  }
  else
  {
    *high = string.substr(0, division);
    *low = string.substr(division);
  }
}

ArrayInteger ArrayInteger::AddPadding(short padding, ArrayInteger* carriage) const
{
  std::string string = this->toString();
  string += std::string(padding, '0');
  if(carriage != nullptr)
    *carriage = string.substr(0, string.size() - this->maximum_size_ * BasicInteger::DigitNumber());
  return string;
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
