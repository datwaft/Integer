#include "nodeinteger.h"

NodeInteger::NodeInteger(const int& data): next_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const long& data): next_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const std::string& data): next_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const BasicInteger& data): next_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const ArrayInteger& other): next_(nullptr), ArrayInteger(other)
{

}

NodeInteger::NodeInteger(const NodeInteger& other): next_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = other.current_size_;
  for (short i = 0; i < other.current_size_; ++i)
    this->data_[i] = other.data_[i];
}
