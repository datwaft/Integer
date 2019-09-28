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
  this->last_ = this->first_;
  current_size_ = 1;
}

void Integer::setInteger(const long& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
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
        last_ = actual->createNext(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
        actual = actual->getNext();
      }
      else
      {
        first_ = new NodeInteger(aux.substr(aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber()));
        actual = first_;
        last_ = first_;
      }
      aux = aux.substr(0, aux.size() - NodeInteger::getMaximumSize() * BasicInteger::DigitNumber());
    }
    else
    {
      if (actual)
      {
        last_ = actual->createNext(aux);
      }
      else
      {
        first_ = new NodeInteger(aux);
        last_ = first_;
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
  this->last_ = this->first_;
  current_size_ = 1;
}

void Integer::setInteger(const ArrayInteger& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;
}

void Integer::setInteger(const NodeInteger& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;
}

void Integer::setInteger(const Integer& other)
{
  NodeInteger* aux = this->first_;
  NodeInteger* otheraux = other.first_;

  if (!(this->first_))
  {
    this->first_ = new NodeInteger((*otheraux));
    this->last_ = this->first_;
    aux = first_;
    otheraux = otheraux->getNext();
  }
  while (otheraux)
  {
    this->last_ = aux->createNext(*otheraux);
    otheraux = otheraux->getNext();
    aux = aux->getNext();
    current_size_++;
  }
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
    actual_this = actual_this->getNext();
    actual_other = actual_other->getNext();
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
    actual_this = actual_this->getNext();
    actual_other = actual_other->getNext();
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
    actual_this = actual_this->getNext();
    actual_other = actual_other->getNext();
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
    actual_this = actual_this->getNext();
    actual_other = actual_other->getNext();
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
    actual_this = actual_this->getNext();
    actual_other = actual_other->getNext();
  }
  return true;
}

Integer Integer::operator+(const Integer& other) const
{
  if (other == 0)
    return *this;
  NodeInteger* this_actual = this->first_;
  NodeInteger* other_actual = other.first_;
  NodeInteger* result = nullptr;
  NodeInteger* aux = nullptr;
  NodeInteger carriage;
  NodeInteger carriage1;
  NodeInteger carriage2;

  while (this_actual != nullptr || other_actual != nullptr)
  {
    if (this_actual == nullptr)
    {
      if (aux == nullptr)
      {
        aux = new NodeInteger(other_actual->Addition(carriage, &carriage));
        result = aux;
      }
      else
      {
        aux->createNext(other_actual->Addition(carriage, &carriage));
        aux = aux->getNext();
      }
      other_actual = other_actual->getNext();
    }
    else if (other_actual == nullptr)
    {
      if (aux == nullptr)
      {
        aux = new NodeInteger(this_actual->Addition(carriage, &carriage));
        result = aux;
      }
      else
      {
        aux->createNext(this_actual->Addition(carriage, &carriage));
        aux = aux->getNext();
      }
      this_actual = this_actual->getNext();
    }
    else
    {
      if (aux == nullptr)
      {
        aux = new NodeInteger(this_actual->Addition(*other_actual, &carriage1).Addition(carriage, &carriage2));
        carriage = carriage1.Addition(carriage2);
        result = aux;
      }
      else
      {
        aux->createNext(this_actual->Addition(*other_actual, &carriage1).Addition(carriage, &carriage2));
        carriage = carriage1.Addition(carriage2);
        aux = aux->getNext();
      }
      this_actual = this_actual->getNext();
      other_actual = other_actual->getNext();
    }
  }
  if (carriage != 0)
    aux->createNext(carriage);

  return result;
}

Integer Integer::operator-(const Integer& other) const
{
  if (other == 0)
    return *this;
  if (other > * this)
    return other - *this;
  Integer result = *this + other.Complement(this->current_size_) + 1;
  
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
    if (actual->getNext() != nullptr)
      result = actual->fullString() + result;
    else
      result = actual->toString() + result;
    actual = actual->getNext();
  }
  return result;
}

Integer Integer::Parse(const std::string& string)
{
  return Integer(string);
}

Integer::Integer(NodeInteger* node)
{
  this->current_size_ = 0;
  this->first_ = node;
  NodeInteger* aux = node;
  while (aux != nullptr)
  {
    aux = aux->getNext();
    current_size_++;
    if (aux->getNext() == nullptr)
      this->last_ = aux;
  }
}

Integer Integer::Complement() const
{
  NodeInteger* actual = this->first_;
  NodeInteger* result = nullptr;
  NodeInteger* aux = nullptr;
  while (actual != nullptr)
  {
    if (aux == nullptr)
    {
      aux = new NodeInteger(actual->Complement());
      result = aux;
    }
    else
    {
      aux->createNext(actual->Complement());
      aux = aux->getNext();
    }
    actual = actual->getNext();
  }
  return result;
}

Integer Integer::Complement(int required_size) const
{
  NodeInteger* actual = this->first_;
  NodeInteger* result = nullptr;
  NodeInteger* aux = nullptr;
  int actual_size = 0;
  while (actual != nullptr || actual_size < required_size)
  {
    if (aux == nullptr)
    {
      if(actual == nullptr)
        aux = new NodeInteger(std::string(NodeInteger::getMaximumSize() * BasicInteger::DigitNumber(), '9'));
      else
        aux = new NodeInteger(actual->Complement());
      result = aux;
    }
    else
    {
      if(actual == nullptr)
        aux->createNext(std::string(NodeInteger::getMaximumSize() * BasicInteger::DigitNumber(), '9'));
      else
        aux->createNext(actual->Complement());
      aux = aux->getNext();
    }
    if(actual != nullptr)
      actual = actual->getNext;
    ++actual_size;
  }
  return result;
}

void Integer::Clear()
{
  NodeInteger* aux;
  while (this->first_ != nullptr)
  {
    aux = this->first_;
    this->first_ = this->first_->getNext();
    delete aux;
  }
  this->last_ = nullptr;
  this->current_size_ = 0;
}

void Integer::Clear(NodeInteger* node)
{ 
  NodeInteger* aux;
  while (node != nullptr)
  {
    aux = node;
    node = node->getNext();
    delete aux;
  }
}

std::ostream& operator<<(std::ostream& out, const Integer& integer)
{
  out << integer.toString();
  return out;
}
