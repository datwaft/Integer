#include "integer.h"

Integer::Integer(const int& data)
{
}

Integer::Integer(const long& data)
{
}

Integer::Integer(const std::string& data)
{
}

Integer::Integer(const BasicInteger& data)
{
}

Integer::Integer(const ArrayInteger& data)
{
}

Integer::Integer(const NodeInteger& data)
{
}

Integer::Integer(const Integer& other)
{
}

void Integer::operator=(const int& data)
{
}

void Integer::operator=(const long& data)
{
}

void Integer::operator=(const std::string& data)
{
}

void Integer::operator=(const BasicInteger& data)
{
}

void Integer::operator=(const ArrayInteger& data)
{
}

void Integer::operator=(const NodeInteger& data)
{
}

void Integer::operator=(const Integer& other)
{
}

Integer::~Integer()
{
}

void Integer::setInteger(const int& data)
{
}

void Integer::setInteger(const long& data)
{
}

void Integer::setInteger(const std::string& data)
{
}

void Integer::setInteger(const BasicInteger& data)
{
}

void Integer::setInteger(const ArrayInteger& data)
{
}

void Integer::setInteger(const NodeInteger& data)
{
}

void Integer::setInteger(const Integer& other)
{
}

int Integer::getCurrentSize() const
{
  return this->current_size_;
}

bool Integer::operator==(const Integer& other) const
{
  return false;
}

bool Integer::operator!=(const Integer& other) const
{
  return false;
}

bool Integer::operator>(const Integer& other) const
{
  return false;
}

bool Integer::operator<(const Integer& other) const
{
  return false;
}

bool Integer::operator>=(const Integer& other) const
{
  return false;
}

bool Integer::operator<=(const Integer& other) const
{
  return false;
}

Integer Integer::Addition(const Integer& other) const
{
  return Integer();
}

Integer Integer::Substraction(const Integer& other) const
{
  return Integer();
}

Integer Integer::Multiplication(const Integer& other) const
{
  return Integer();
}

Integer Integer::Division(const Integer& other) const
{
  return Integer();
}

std::string Integer::toString() const
{
  return std::string();
}

std::string Integer::fullString() const
{
  return std::string();
}
