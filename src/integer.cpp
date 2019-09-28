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
  DeleteLeftPadding();
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
  DeleteLeftPadding();
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
  *this = *this + other;
}

void Integer::operator-=(const Integer& other)
{
  *this = *this - other;
}

void Integer::operator*=(const Integer& other)
{
  *this = *this * other;
}

void Integer::operator/=(const Integer& other)
{
  *this = *this / other;
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

int Integer::getDigits() const
{
  return static_cast<int>(this->toString().size());
}

bool Integer::operator==(const Integer& other) const
{
  if (this->getDigits() != other.getDigits())
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
  if(this->getDigits() < other.getDigits())
    return false;
  if (this->getDigits() > other.getDigits())
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
  if(this->getDigits() > other.getDigits())
    return false;
  if (this->getDigits() < other.getDigits())
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
  if(this->getDigits() < other.getDigits())
    return false;
  if (this->getDigits() > other.getDigits())
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
  if(this->getDigits() > other.getDigits())
    return false;
  if (this->getDigits() < other.getDigits())
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
    return aux->createNext(carriage);

  return result;
}

Integer Integer::operator-(const Integer& other) const
{
  if (other == 0)
    return *this;
  Integer result = *this + other.Complement(this->current_size_) + 1;
  
  result = result.toString().substr(1);
  result.DeleteLeftPadding();

  return result;
}

Integer Integer::operator*(const Integer& other) const
{
  if (this->current_size_ == 1 && this->first_->getCurrentSize() == 1 || other.current_size_ == 1 && other.first_->getCurrentSize() == 1)
  {
    NodeInteger* actual;
    BasicInteger operand;
    if (this->current_size_ == 1 && this->first_->getCurrentSize() == 1)
    {
      actual = other.first_;
      operand = this->first_->First();
    }
    else
    {
      actual = this->first_;
      operand = other.first_->First();
    }
    NodeInteger* result = nullptr;
    NodeInteger* aux = nullptr;
    NodeInteger carriage;
    BasicInteger carriage_aux1;
    NodeInteger carriage_aux2;

    while (actual != nullptr)
    {
      if (aux == nullptr)
      {
        aux = new NodeInteger(actual->Multiplication(operand, &carriage_aux1).Addition(carriage, &carriage_aux2));
        carriage = carriage_aux2.Addition(carriage_aux1);
        result = aux;
      }
      else
      {
        aux = aux->createNext(actual->Multiplication(operand, &carriage_aux1).Addition(carriage, &carriage_aux2));
        carriage = carriage_aux2.Addition(carriage_aux1);
      }
      actual = actual->getNext();
    }
    if (carriage != 0)
    {
      if(!(carriage.getCurrentSize() == 1 && aux->Append(carriage.First())))
        aux->createNext(carriage);
    }
    Integer result_aux = result;
    result_aux.DeleteLeftPadding();
    return result_aux;
  }
 
  // std::cout << "*this = " << *this << "\tsize: " << this->getDigits() << std::endl;
  // std::cout << "other = " << other << "\tsize: " << other.getDigits() << std::endl;

  int m = this->getDigits() <= other.getDigits() ? this->getDigits() : other.getDigits();
  int m2 = m / 2;

  // std::cout << "m: " << m << std::endl;
  // std::cout << "m2: " << m2 << std::endl;

  Integer high1, low1;
  this->Split(&high1, &low1, m2);
  // std::cout << "high1: " << high1 << "\tlow1: " << low1 << std::endl;
  Integer high2, low2;
  other.Split(&high2, &low2, m2);
  // std::cout << "high2: " << high2 << "\tlow2: " << low2 << std::endl;

  Integer z0 = low1 * low2;
  std::cout << "low1, low2: " << low1 << " " << low2 << std::endl;
  std::cout << "z0: " << z0 << std::endl;
  Integer z1 = (low1 + high1) * (low2 + high2);
  Integer z2 = high1 * high2;
  
  // std::cout << "z2: " << z2 << std::endl;
  // std::cout << "z2 * 10**(m2*2): " << z2.AddRightPadding(m2 * 2) << std::endl;
  return z2.AddRightPadding(m2 * 2) + (z1 - z2 - z0).AddRightPadding(m2) + z0;
}

Integer Integer::operator/(const Integer& other) const
{
  

  std::string dividend = this->toString();
  std::string divisor = other.toString();
  long long result;

  if (dividend.size() <= 18)
    if (divisor.size() <= 18)
    {
      result  = (std::stoll(dividend) / std::stoll(divisor));
      return std::to_string(result);
    }

 /* std::string aux;*/
 
  std::string resultstring = "0";
  std::string counter = "0";
  std::string sobra = "0";
  std::string resultadoF = "0";
  
  while(dividend.size() > divisor.size())
  {
    std::string auxdividend = dividend.substr(0, divisor.length());

    while (Parse(resultstring) < Parse(auxdividend))
    {
      resultstring = (Parse(resultstring) + Parse(divisor)).toString();
      counter = (Parse(counter) + 1).toString();

    /*  std::cout << Parse(resultstring).toString() << "\n";
      system("pause");
      std::cout << Parse(auxdividend).toString() << "\n";
      system("pause");*/
    }
    resultstring = (Parse(resultstring) - Parse(divisor)).toString();
      counter = (Parse(counter) - 1).toString();

    sobra = /*resultstring =*/ (Parse(auxdividend) - Parse(resultstring)).toString();

    dividend = sobra + dividend.substr(divisor.size() + 1, dividend.size() - 1);

    resultadoF = resultadoF + counter;

    counter = "0";
    resultstring = "0";

  }
  return (resultadoF + "0");

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
  this->last_ = this->first_;
  NodeInteger* aux = node;
  while (aux != nullptr)
  {
    aux = aux->getNext();
    current_size_++;
    if (aux && aux->getNext() == nullptr)
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
      actual = actual->getNext();
    ++actual_size;
  }
  return result;
}

void Integer::Split(Integer* high, Integer* low, int pivot) const
{
  pivot += 1;
  std::string string = this->toString();
  if (pivot >= static_cast<int>(string.length()))
  {
    *high = 0;
    *low = *this; 
  }
  else
  {
    *high = string.substr(0, pivot);
    *low = string.substr(pivot);
  }
}

Integer Integer::AddRightPadding(int padding) const
{
  return this->toString() + std::string(padding, '0');
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

void Integer::DeleteLeftPadding()
{
  while (this->last_ != nullptr && *this->last_ == 0 && this->last_ != this->first_)
  {
    this->last_ = this->last_->getPrev();
    this->last_->deleteNext();
    --this->current_size_;
  }
}

Integer Integer::AppendToRight(Integer to_append) const
{
  return to_append.toString() + this->toString();
}

std::ostream& operator<<(std::ostream& out, const Integer& integer)
{
  out << integer.toString();
  return out;
}
