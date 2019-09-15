// basicinteger.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la implementación de la clase más básica que compone
//              la clase Integer.

#include "basicinteger.h"
#include "arrayinteger.h"

short BasicInteger::digitnumber_ = BasicInteger::CalculateDigitNumber();

short BasicInteger::CalculateDigitNumber()
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
  this->digitnumber_ = CalculateDigitNumber();
  this->data_ = abs(data) % MaximumNumberPlusOne();
}

BasicInteger::BasicInteger(const long& data)
{
  this->digitnumber_ = CalculateDigitNumber();
  this->data_ = abs(data) % MaximumNumberPlusOne();
}

BasicInteger::BasicInteger(const std::string& data)
{
  *this = BasicInteger(std::stol(data));
}

void BasicInteger::operator=(const int& data)
{
  this->digitnumber_ = CalculateDigitNumber();
  this->data_ = abs(data) % MaximumNumberPlusOne();
}

void BasicInteger::operator=(const long& data)
{
  this->digitnumber_ = CalculateDigitNumber();
  this->data_ = abs(data) % MaximumNumberPlusOne();
}

void BasicInteger::operator=(const std::string& data)
{
  *this = BasicInteger(std::stol(data));
}

short BasicInteger::CurrentSize() const
{
  if (this->data_ != 0)
    return static_cast<short>(log10(this->data_) + 1);
  else
    return 0;
}

short BasicInteger::DigitNumber()
{
  return BasicInteger::digitnumber_;
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
    (*carriage) = (calculation >= MaximumNumberPlusOne() ? 1 : 0);
  
  return calculation;
}

BasicInteger BasicInteger::Substraction(const BasicInteger& other) const
{
  Base calculation = this->data_ - other.data_;
  return calculation;
}

BasicInteger BasicInteger::Multiplication(const BasicInteger& other, BasicInteger* carriage) const
{
	long long calculation = static_cast<long long>(this->data_) * static_cast<long long>(other.data_);
  if (carriage != nullptr)
    (*carriage) = static_cast<Base>(calculation >= MaximumNumberPlusOne() ? calculation / MaximumNumberPlusOne() : 0);
 
  return static_cast<Base>(calculation % static_cast<long long>(MaximumNumberPlusOne()));
}

BasicInteger BasicInteger::Division(const BasicInteger& other) const
{
  if (other == 0)
  {
    throw std::exception("Division by 0");
  }
  return this->data_ / other.data_;
}

BasicInteger::Base BasicInteger::MaximumNumberPlusOne() 
{
  return static_cast<Base>(pow(10, digitnumber_));
}

BasicInteger BasicInteger::NineComplement() const
{
  return MaximumNumberPlusOne() - 1 - this->data_;
}

std::string BasicInteger::toString() const
{
  return std::to_string(this->data_);
}

std::string BasicInteger::fullString() const
{
  return std::string(this->digitnumber_ - this->CurrentSize() , '0') + this->toString();
}
