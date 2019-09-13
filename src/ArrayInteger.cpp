#include "ArrayInteger.h"

short ArrayInteger::maximum_size_ = ArrayInteger::MaximumSize();

ArrayInteger::ArrayInteger(const int& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->data_[0] = abs(data);
  this->current_size_ = 1;
}

ArrayInteger::ArrayInteger(const long& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->data_[0] = abs(data) % static_cast<BasicInteger::Base>(pow(10, this->maximum_size_));
  BasicInteger::Base carriage = abs(data) / static_cast<BasicInteger::Base>(pow(10, this->maximum_size_));
  if (carriage != 0)
  {
    this->data_[1] = carriage;
    this->current_size_ = 2;
  }
  else
  {
    this->current_size_ = 1;
  }
}

ArrayInteger::ArrayInteger(const std::string& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = 0;

  std::string aux;
  for (size_t i = data.size() - 1; i >= 0; i--)
  {
    aux += data[i];
    if (aux.size() == BasicInteger::getMaximumSize())
    {
      this->data_[this->current_size_++] = aux;
      aux = "";
    }
  }
  this->data_[this->current_size_++] = aux;
}

void ArrayInteger::operator=(const int& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->data_[0] = abs(data);
  this->current_size_ = 1;
}

void ArrayInteger::operator=(const long& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->data_[0] = abs(data) % static_cast<BasicInteger::Base>(pow(10, this->maximum_size_));
  BasicInteger::Base carriage = abs(data) / static_cast<BasicInteger::Base>(pow(10, this->maximum_size_));
  if (carriage != 0)
  {
    this->data_[1] = carriage;
    this->current_size_ = 2;
  }
  else
  {
    this->current_size_ = 1;
  }
}

void ArrayInteger::operator=(const std::string& data)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = 0;

  std::string aux;
  for (size_t i = data.size() - 1; i >= 0; i--)
  {
    aux += data[i];
    if (aux.size() == BasicInteger::getMaximumSize())
    {
      this->data_[this->current_size_++] = aux;
      aux = "";
    }
  }
  this->data_[this->current_size_++] = aux;
}

ArrayInteger::~ArrayInteger()
{
  delete[] this->data_;
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
  return false;
}

bool ArrayInteger::operator!=(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator>(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator<(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator>=(const ArrayInteger& other) const
{
  return false;
}

bool ArrayInteger::operator<=(const ArrayInteger& other) const
{
  return false;
}

Pair<ArrayInteger, ArrayInteger> ArrayInteger::Addition(const ArrayInteger& other) const
{
  return Pair<ArrayInteger, ArrayInteger>();
}

Pair<ArrayInteger, ArrayInteger> ArrayInteger::Substraction(const ArrayInteger& other) const
{
  return Pair<ArrayInteger, ArrayInteger>();
}

Pair<ArrayInteger, ArrayInteger> ArrayInteger::Multiplication(const ArrayInteger& other) const
{
  return Pair<ArrayInteger, ArrayInteger>();
}

ArrayInteger ArrayInteger::Division(const ArrayInteger& other) const
{
  return ArrayInteger();
}

ArrayInteger::operator std::string()
{
  std::string result;
  //for (int i = current_size_ - 1; i >= 0; i--)
  //  result += std::string(this->data_[i]);
  return result;
}

short ArrayInteger::MaximumSize()
{
  return 3;
}
