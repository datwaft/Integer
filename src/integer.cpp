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
  this->setInteger(data);
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
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const long& data)
{
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const std::string& data)
{
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const BasicInteger& data)
{
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const ArrayInteger& data)
{
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const NodeInteger& data)
{
  this->Clear();
  this->setInteger(data);
}

void Integer::operator=(const Integer& other)
{
  this->Clear();
  this->setInteger(other);
}

void Integer::operator+=(const Integer& other)
{
  auto aux = this->first_;
  *this = *this + other;
  this->Clear(aux);
}

void Integer::operator-=(const Integer& other)
{
  auto aux = this->first_;
  *this = *this - other;
  this->Clear(aux);
}

void Integer::operator*=(const Integer& other)
{
  auto aux = this->first_;
  *this = *this * other;
  this->Clear(aux);
}

void Integer::operator/=(const Integer& other)
{
  auto aux = this->first_;
  *this = *this / other;
  this->Clear(aux);
}

Integer::~Integer()
{
  this->Clear();
}

void Integer::setInteger(const int& data)
{
  this->first_ = new NodeInteger(data);
  current_size_ = 1;
}

void Integer::setInteger(const long& data)
{
  this->first_ = new NodeInteger(data);
  current_size_ = 1;
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
        first_ = new NodeInteger(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
        actual = first_;
      }
      aux = aux.substr(0, aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber());
    }
    else
    {
      if (actual)
      {
        actual->next_ = new NodeInteger(aux);
      }
      else
      {
        first_ = new NodeInteger(aux);
        actual = first_;
      }
      aux.clear();
    }
    this->current_size_ += 1;
  }
}

void Integer::setInteger(const BasicInteger& data)
{
  this->first_ = new NodeInteger(data);
  current_size_ = 1;
}

void Integer::setInteger(const ArrayInteger& data)
{
  this->first_ = new NodeInteger(data);
  current_size_ = 1;
}

void Integer::setInteger(const NodeInteger& data)
{
  this->first_ = new NodeInteger(data);
  current_size_ = 1;
}

void Integer::setInteger(const Integer& other)
{
  NodeInteger* aux = this->first_;
  NodeInteger* otheraux = other.first_;
  
  while (otheraux)
  {
    if (!(this->first_))
    {
      this->first_ = new NodeInteger((*otheraux));
      aux = first_;
    }
    else
    {
      if (otheraux->next_)
      {
        aux->next_ = new NodeInteger(*(otheraux->next_));
        aux = aux->next_;
      }
    }
    otheraux = otheraux->next_;
    current_size_++;
  }
}

int Integer::getCurrentSize() const
{
  return (this->current_size_);
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
  if(this->current_size_ > other.current_size_)
    return false;
  if (this->current_size_ < other.current_size_)
    return true;

  NodeInteger* actual_this = this->first_;
  NodeInteger* actual_other = other.first_;
  while (actual_this != nullptr)
  {
    if (*actual_this >= *actual_other)
      return false;
    actual_this = actual_this->next_;
    actual_other = actual_other->next_;
  }
  return true;
}

bool Integer::operator>=(const Integer& other) const
{
  if(this->current_size_ < other.current_size_)
    return false;
  if (this->current_size_ > other.current_size_)
    return true;

  NodeInteger* actual_this = this->first_;
  NodeInteger* actual_other = other.first_;
  while (actual_this != nullptr)
  {
    if (*actual_this < *actual_other)
      return false;
    actual_this = actual_this->next_;
    actual_other = actual_other->next_;
  }
  return true;
}

bool Integer::operator<=(const Integer& other) const
{
  if(this->current_size_ > other.current_size_)
    return false;
  if (this->current_size_ < other.current_size_)
    return true;

  NodeInteger* actual_this = this->first_;
  NodeInteger* actual_other = other.first_;
  while (actual_this != nullptr)
  {
    if (*actual_this > *actual_other)
      return false;
    actual_this = actual_this->next_;
    actual_other = actual_other->next_;
  }
  return true;
}

Integer Integer::operator+(const Integer& other) const
{
  NodeInteger* this_actual = this->first_;
  NodeInteger* other_actual = other.first_;
  return Integer();
}

Integer Integer::operator-(const Integer& other) const
{
  return Integer();
}

Integer Integer::operator*(const Integer& other) const
{
  return Integer();
}

Integer Integer::operator/(const Integer& other) const
{
  return Integer();
}

std::string Integer::toString() const
{
  std::string result;
  NodeInteger* actual = this->first_;
  while (actual != nullptr)
  {
    if (actual->next_ != nullptr)
      result += actual->fullString();
    else
      result += actual->toString();
    actual = actual->next_;
  }
  return result;
}

Integer Integer::Parse(const std::string& string)
{
  return Integer(string);
}

Integer::Integer(NodeInteger* )
{
}

void Integer::Clear()
{
  NodeInteger* aux;
  while (this->first_ != nullptr)
  {
    aux = this->first_;
    this->first_ = this->first_->next_;
    delete aux;
  }
  this->current_size_ = 0;
}

void Integer::Clear(NodeInteger* node)
{ 
  NodeInteger* aux;
  while (node != nullptr)
  {
    aux = node;
    node = node->next_;
    delete aux;
  }
}

std::ostream& operator<<(std::ostream& out, const Integer& integer)
{
  out << integer.toString();
  return out;
}
