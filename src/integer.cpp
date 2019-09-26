#include "integer.h"

Integer::Integer(const int& data): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(data);
}

Integer::Integer(const long& data): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(data);
}

Integer::Integer(const std::string& data): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(data);
}

Integer::Integer(const BasicInteger& data): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(data);
}

Integer::Integer(const ArrayInteger& data): first_(nullptr)
{
  current_size_ = 0;
}

Integer::Integer(const NodeInteger& data): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(data);
}

Integer::Integer(const Integer& other): first_(nullptr)
{
  current_size_ = 0;
  this->setInteger(other);
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

void Integer::operator+=(const Integer&)
{
}

void Integer::operator-=(const Integer&)
{
}

void Integer::operator*=(const Integer&)
{
}

void Integer::operator/=(const Integer&)
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
  std::string aux = data;
  NodeInteger* actual = this->first_;
  while (aux.size() != 0)
  {
    if (static_cast<short>(aux.size()) > NodeInteger::getMaximumSize() * BasicInteger::DigitNumber())
    {
      if (actual)
      {
        actual->next_ = new NodeInteger(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
        actual = actual->next_;
      }
      else
      {
        actual = new NodeInteger(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
      }
      aux = aux.substr(0, aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber());
    }
    else
    {
      actual->next_ = new NodeInteger(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
    }
    this->current_size_ += 1;
  }
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
  if (this->current_size_ != other.current_size_)
    return false;
  NodeInteger* actual_this = this->first_;
  NodeInteger* actual_other = other.first_;
  while (actual_this != nullptr)
  {
    if (*actual_this != *actual_other)
      return false;
    actual_this = actual_this->next_;
    actual_other = actual_other->next_;
  }
  return true;
}

bool Integer::operator!=(const Integer& other) const
{
  return !(*this == other);
}

bool Integer::operator>(const Integer& other) const
{
  if(this->current_size_ < other.current_size_)
    return false;
  if (this->current_size_ > other.current_size_)
    return true;

  NodeInteger* actual_this = this->first_;
  NodeInteger* actual_other = other.first_;
  while (actual_this != nullptr)
  {
    if (*actual_this <= *actual_other)
      return false;
    actual_this = actual_this->next_;
    actual_other = actual_other->next_;
  }
  return true;
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

Integer Integer::operator+(const Integer&) const
{
  return Integer();
}

Integer Integer::operator-(const Integer&) const
{
  return Integer();
}

Integer Integer::operator*(const Integer&) const
{
  return Integer();
}

Integer Integer::operator/(const Integer&) const
{
  return Integer();
}

std::string Integer::toString() const
{
  std::string result;
  NodeInteger* actual = this->first_;
  while (actual->next_ != nullptr)
  {
    result += actual->fullString();
    actual = actual->next_;
  }
  result += actual->toString();
  return result;
}

Integer Integer::Parse(std::string string)
{
  return Integer(string);
}

std::ostream& operator<<(std::ostream& out, const Integer& integer)
{
  out << integer.toString();
  return out;
}
