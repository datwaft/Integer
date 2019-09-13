// basicinteger.cpp
// Autores: David Guevara & Mario Arguello
// Descripci�n: contiene la implementaci�n de la clase m�s b�sica que compone
//              la clase Integer.

#include "basicinteger.h"
#include "arrayinteger.h"

short BasicInteger::maximum_size_ = BasicInteger::MaximumSize();

short BasicInteger::MaximumSize()
{
  switch (sizeof(Base))
  {
  case 1: return 2;
  case 2: return 4;
  case 4: return 9;
  case 8: return 19;
  default: throw std::exception("Invalid basic type.");
  }
}

BasicInteger::BasicInteger(const int& data)
{
  this->maximum_size_ = MaximumSize();
  this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
}

BasicInteger::BasicInteger(const long& data)
{
  this->maximum_size_ = MaximumSize();
  this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
}

BasicInteger::BasicInteger(const std::string& data)
{
  *this = BasicInteger(std::stol(data));
}

void BasicInteger::operator=(const int& data)
{
  this->maximum_size_ = MaximumSize();
  this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
}

void BasicInteger::operator=(const long& data)
{
  this->maximum_size_ = MaximumSize();
  this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
}

void BasicInteger::operator=(const std::string& data)
{
  *this = BasicInteger(std::stol(data));
}

short BasicInteger::getCurrentSize() const
{
  if (this->data_ != 0)
    return static_cast<short>(log10(this->data_) + 1);
  else
    return 1;
}

short BasicInteger::getMaximumSize()
{
  return BasicInteger::maximum_size_;
}

bool BasicInteger::operator==(const BasicInteger& other) const
{
  return this->data_ == other.data_;
}

bool BasicInteger::operator!=(const BasicInteger& other) const
{
  return this->data_ != other.data_;
}

bool BasicInteger::operator>(const BasicInteger& other) const
{
  return this->data_ > other.data_;
}

bool BasicInteger::operator<(const BasicInteger& other) const
{
  return this->data_ < other.data_;
}

bool BasicInteger::operator>=(const BasicInteger& other) const
{
  return this->data_ >= other.data_;
}

bool BasicInteger::operator<=(const BasicInteger& other) const
{
  return this->data_ <= other.data_;
}

BasicInteger BasicInteger::Addition(const BasicInteger& other, BasicInteger* carriage) const
{
  Base calculation = this->data_ + other.data_;
  if (carriage != nullptr)
    (*carriage) = (calculation >= pow(10, this->maximum_size_) ? 1 : 0);
  
  return calculation;
}

BasicInteger BasicInteger::Substraction(const BasicInteger& other, BasicInteger* carriage) const
{
  Base calculation = this->data_ - other.data_;
  (*carriage) = (calculation < 0 ? 1 : 0);

  return calculation;
}

BasicInteger BasicInteger::Multiplication(const BasicInteger& other, BasicInteger* carriage) const
{
	long long calculation = static_cast<long long>(this->data_) * static_cast<long long>(other.data_);
	(*carriage) = static_cast<Base>(calculation >= pow(10, this->maximum_size_) ? (calculation / (pow(10, this->maximum_size_))) : 0);
  
  return static_cast<Base>(calculation % static_cast<long long>(pow(10,this->maximum_size_)));
}

BasicInteger BasicInteger::Division(const BasicInteger& other) const
{
  return BasicInteger(this->data_ / other.data_);
}

std::string BasicInteger::toString() const
{
  return std::to_string(this->data_);
}

std::string BasicInteger::fullString() const
{
  return std::string(this->maximum_size_ - this->getCurrentSize() , '0') + this->toString();
}
