#include "nodeinteger.h"

NodeInteger::NodeInteger(const int& data): next_(nullptr), prev_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const long& data): next_(nullptr), prev_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const std::string& data): next_(nullptr), prev_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const BasicInteger& data): next_(nullptr), prev_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->setInteger(data);
}

NodeInteger::NodeInteger(const ArrayInteger& other): next_(nullptr), prev_(nullptr), ArrayInteger(other)
{

}

NodeInteger::NodeInteger(const NodeInteger& other): next_(nullptr), prev_(nullptr)
{
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = other.current_size_;
  for (short i = 0; i < other.current_size_; ++i)
    this->data_[i] = other.data_[i];
}

void NodeInteger::operator=(const NodeInteger& other)
{
  delete[] this->data_;
  this->data_ = new BasicInteger[this->maximum_size_];
  this->current_size_ = other.current_size_;
  for (short i = 0; i < other.current_size_; ++i)
    this->data_[i] = other.data_[i];
}

NodeInteger* NodeInteger::getNext()
{
  return this->next_;
}

NodeInteger* NodeInteger::getPrev()
{
  return this->prev_;
}

NodeInteger* NodeInteger::createNext(const NodeInteger& data)
{
	NodeInteger* aux = new NodeInteger(data);
	aux->next_ = this->next_;
	aux->prev_ = this;

	this->next_ = aux;
	if(aux->next_)
		aux->next_->prev_ = aux;
	return aux;
}

NodeInteger* NodeInteger::createPrev(const NodeInteger& data)
{
	NodeInteger* aux = new NodeInteger(data);
	aux->next_ = this;
	aux->prev_ = this->prev_;

	this->prev_ = aux;
	if(aux->prev_)
		aux->prev_->next_ = aux;
	return aux;
}

bool NodeInteger::deleteNext()
{
	if(!this->next_)
		return false;

	NodeInteger* aux = this->next_;
	this->next_ = aux->next_;
	if(aux->next_)
		aux->next_->prev_ = this;
	delete aux;
	return true;
}

bool NodeInteger::deletePrev()
{
	if (!this->prev_)
		return false;

	NodeInteger* aux = this->prev_;
	this->prev_ = aux->prev_;
	if (aux->prev_)
		aux->prev_->next_ = this;
	delete aux;
	return true;
}
