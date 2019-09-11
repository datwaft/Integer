// basicinteger.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la implementación de la clase más básica que compone
//              la clase Integer.

#include "basicinteger.h"

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
  if (data == 0)
  {
    this->data_ = 0;
    this->current_size_ = 1;
  }
  else
  {
    this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
    this->current_size_ = static_cast<short>(log10(this->data_) + 1);
  }
}

BasicInteger::BasicInteger(const long& data)
{
  this->maximum_size_ = MaximumSize();
  if (data == 0)
  {
    this->data_ = 0;
    this->current_size_ = 1;
  }
  else
  {
    this->data_ = abs(data) % static_cast<Base>(pow(10, this->maximum_size_));
    this->current_size_ = static_cast<short>(log10(this->data_) + 1);
  }
}

BasicInteger::Base BasicInteger::getDigit(int digit) const
{
  return (this->data_ / static_cast<Base>(pow(10, this->maximum_size_))) % 10;
}

short BasicInteger::getCurrentSize() const
{
  return this->current_size_;
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

Pair<BasicInteger, BasicInteger> BasicInteger::Addition(const BasicInteger& other) const
{
  Pair<BasicInteger, BasicInteger> result;

  Base calculation = this->data_ + other.data_;
  result.one = calculation;
  result.two = (calculation >= pow(10, this->maximum_size_) ? 1 : 0);

  return result;
}

Pair<BasicInteger, BasicInteger> BasicInteger::Substraction(const BasicInteger& other) const
{
  Pair<BasicInteger, BasicInteger> result;

  Base calculation = this->data_ - other.data_;
  result.one = calculation;
  result.two = (calculation < 0 ? 1 : 0);

  return result;
}

Pair<BasicInteger, BasicInteger> BasicInteger::Multiplication(const BasicInteger& other) const
{
  return Pair<BasicInteger, BasicInteger>();
}

BasicInteger BasicInteger::Division(const BasicInteger& other) const
{
  return BasicInteger();
}

BasicInteger::operator std::string()
{
  return std::to_string(this->data_);
}

BasicInteger BasicInteger::Parse(std::string string)
{
  return BasicInteger(std::stol(string));
}
