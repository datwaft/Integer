// integer.cpp
// Autores: David Guevara & Mario Arguello
// Descripción: contiene la implementación de la clase Integer.

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
  if (data < 0)
    this->sign_ = Sign::NEGATIVE;
  else if (data == 0)
    this->sign_ = Sign::NEUTRAL;
  else
    this->sign_ = Sign::POSITIVE;
}

void Integer::setInteger(const long& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;
  if (data < 0)
    this->sign_ = Sign::NEGATIVE;
  else if (data == 0)
    this->sign_ = Sign::NEUTRAL;
  else
    this->sign_ = Sign::POSITIVE;
}

void Integer::setInteger(const std::string& data)
{
  std::string aux = data;
  if (aux.empty())
    setInteger(0);
  if (!aux.empty() && aux[0] == '-')
  {
    this->sign_ = NEGATIVE;
    aux = aux.substr(1);
  }
  else
    this->sign_ = POSITIVE;
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
  if (*this == 0)
    this->sign_ = NEUTRAL;
}

void Integer::setInteger(const BasicInteger& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;
  if (data == 0)
    this->sign_ = Sign::NEUTRAL;
  else
    this->sign_ = Sign::POSITIVE;
}

void Integer::setInteger(const ArrayInteger& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;

  if (data == 0)
    this->sign_ = Sign::NEUTRAL;
  else
    this->sign_ = Sign::POSITIVE;
}

void Integer::setInteger(const NodeInteger& data)
{
  this->first_ = new NodeInteger(data);
  this->last_ = this->first_;
  current_size_ = 1;

  if (data == 0)
    this->sign_ = Sign::NEUTRAL;
  else
    this->sign_ = Sign::POSITIVE;
}

void Integer::setInteger(const Integer& other)
{
  NodeInteger* aux = this->first_;
  NodeInteger* otheraux = other.first_;
  this->sign_ = other.sign_;

  if (!(this->first_))
  {
    this->first_ = new NodeInteger((*otheraux));
    this->last_ = this->first_;
    aux = first_;
    otheraux = otheraux->getNext();
    current_size_++;
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
  return static_cast<int>(this->toString().size()) - (this->sign_ == NEGATIVE ? 1 : 0);
}

bool Integer::operator==(const Integer& other) const
{
  if (this->sign_ != other.sign_)
    return false;
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
  if (this->sign_ != NEGATIVE && other.sign_ != NEGATIVE)
  {
    if (this->getDigits() < other.getDigits())
      return false;
    if (this->getDigits() > other.getDigits())
      return true;

    NodeInteger* actual_this = this->last_;
    NodeInteger* actual_other = other.last_;

    while (actual_this != nullptr)
    {
      if (*actual_this < *actual_other)
        return false;
      if (*actual_this > *actual_other)
        return true;
      actual_this = actual_this->getPrev();
      actual_other = actual_other->getPrev();
    }
    return false;
  }
  if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
    return false;
  if (other.sign_ == NEGATIVE && this->sign_ != NEGATIVE)
    return true;
  return this->Neutral() < other.Neutral();
}

bool Integer::operator<(const Integer& other) const
{
  if (this->sign_ != NEGATIVE && other.sign_ != NEGATIVE)
  {
    if (this->getDigits() < other.getDigits())
      return true;
    if (this->getDigits() > other.getDigits())
      return false;

    NodeInteger* actual_this = this->last_;
    NodeInteger* actual_other = other.last_;
    while (actual_this != nullptr)
    {
      if (*actual_this > *actual_other)
        return false;
      if (*actual_this < *actual_other)
        return true;
      actual_this = actual_this->getPrev();
      actual_other = actual_other->getPrev();
    }
    return false;
  }
  if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
    return true;
  if (other.sign_ == NEGATIVE && this->sign_ != NEGATIVE)
    return false;
  return this->Neutral() < other.Neutral();
}

bool Integer::operator>=(const Integer& other) const
{
  if (this->sign_ != NEGATIVE && other.sign_ != NEGATIVE)
  {
    if (this->getDigits() < other.getDigits())
      return false;
    if (this->getDigits() > other.getDigits())
      return true;

    NodeInteger* actual_this = this->last_;
    NodeInteger* actual_other = other.last_;
    while (actual_this != nullptr)
    {
      if (*actual_this < *actual_other)
        return false;
      if (*actual_this > *actual_other)
        return true;
      actual_this = actual_this->getPrev();
      actual_other = actual_other->getPrev();
    }
    return true;
  }
  if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
    return false;
  if (other.sign_ == NEGATIVE && this->sign_ != NEGATIVE)
    return true;
  return this->Neutral() <= other.Neutral();
}

bool Integer::operator<=(const Integer& other) const
{
  if (this->sign_ != NEGATIVE && other.sign_ != NEGATIVE)
  {
    if (this->getDigits() < other.getDigits())
      return true;
    if (this->getDigits() > other.getDigits())
      return false;

    NodeInteger* actual_this = this->last_;
    NodeInteger* actual_other = other.last_;
    while (actual_this != nullptr)
    {
      if (*actual_this > *actual_other)
        return false;
      if (*actual_this < *actual_other)
        return true;
      actual_this = actual_this->getPrev();
      actual_other = actual_other->getPrev();
    }
    return true;
  }
  if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
    return true;
  if (other.sign_ == NEGATIVE && this->sign_ != NEGATIVE)
    return false;
  return this->Neutral() >= other.Neutral();
}

bool Integer::checkForCero(const std::string& s) const
{
  for (char i : s)
  {
    if (i != '0')
      return false;
  }
    return true;
}

Integer Integer::operator+(const Integer& other) const
{
  if (other == 0)
    return *this;

  if (this->sign_ == NEGATIVE)
  {
    if (other.sign_ == NEGATIVE)
    {
      Integer result = this->Neutral() + other.Neutral();
      result.sign_ = NEGATIVE;
      return result;
    }
    else
    {
      return other - this->Neutral();
    }
  }
  else
  {
    if (other.sign_ == NEGATIVE)
    {
      return *this - other.Neutral();
    }
    else
    {
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
  }
}

Integer Integer::operator-(const Integer& other) const
{
  if (other == 0)
    return *this;

  if (this->sign_ == NEGATIVE)
  {
    if (other.sign_ == NEGATIVE)
    {
      return *this - other.Neutral();
    }
    else
    {
      Integer result = this->Neutral() + other.Neutral();
      result.sign_ = NEGATIVE;
      return result;
    }
  }
  else
  {
    if (other.sign_ == NEGATIVE)
    {
      return *this + other.Neutral();
    }
    else
    {
      Integer result;
      if (*this > other)
      {
        result = *this + other.Complement(this->current_size_) + 1;
        result.sign_ = POSITIVE;
      }
      else
      {
        result = other + this->Complement(this->current_size_) + 1;
        result.sign_ = NEGATIVE;
      }

      if (result.sign_ != NEGATIVE)
      {
        result = result.toString().substr(1);
      }
      else
      {
        result = "-" + result.toString().substr(2); 
      }
      result.DeleteLeftPadding();
      
      if (result == 0)
        result.sign_ = NEUTRAL;

      return result;
    }
  }
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
      aux->createNext(carriage);
    Integer result_aux = result;
    result_aux.DeleteLeftPadding();

    if (this->sign_ != NEGATIVE && other.sign_ == NEGATIVE)
      result_aux.sign_ = NEGATIVE;
    else if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
      result_aux.sign_ = NEGATIVE;

    return result_aux;
  }

  int m = this->getDigits() <= other.getDigits() ? this->getDigits() : other.getDigits();
  int m2 = static_cast<int>(floor((double)(m) / 2));

  Integer high1, low1;
  this->Split(&high1, &low1, m2);
  Integer high2, low2;
  other.Split(&high2, &low2, m2);

  Integer z0 = low1 * low2;
  Integer z1 = (low1 + high1) * (low2 + high2);
  Integer z2 = high1 * high2;

  Integer result_aux = z2.AddRightPadding(m2 * 2) + (z1 - z2 - z0).AddRightPadding(m2) + z0;

  if (this->sign_ != NEGATIVE && other.sign_ == NEGATIVE)
    result_aux.sign_ = NEGATIVE;
  else if (this->sign_ == NEGATIVE && other.sign_ != NEGATIVE)
    result_aux.sign_ = NEGATIVE;

  return result_aux;
}

Integer Integer::operator/(const Integer& divisor) const
{
  Integer quotient;
  Integer remainder;
  Division(divisor, &quotient, &remainder);
  return quotient;
}

Integer Integer::operator%(const Integer& divisor) const
{
  Integer quotient;
  Integer remainder;
  Division(divisor, &quotient, &remainder);
  return remainder;
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
  if (this->sign_ == NEGATIVE)
    result = "-" + result;
  return result;
}

Integer Integer::Parse(const std::string& string)
{
  return Integer(string);
}

Integer Integer::Factorial(Integer number)
{
  Integer result = 1;
  for (Integer i = 2; i <= number; i += 1)
  {
    result *= i;
  }
  return result;
}

Integer Integer::Fibonacci(Integer number)
{
  if (number < 2)
    return number;
  Integer prev = 1;
  Integer current = 1;
  Integer next = 1;

  for (Integer i = 3; i <= number; i += 1) 
  {
    next = current + prev;
    prev = current;
    current = next;
  }

  return next;
}

Integer Integer::Combinations(Integer n, Integer k)
{
  Integer res = 1;

  if (k > n - k)
    k = n - k;

  for (Integer i = 0; i < k; i += 1)
  {
    res *= (n - i);
    res /= (i + 1);
    std::cout << res << std::endl;
    std::cout << i << std::endl << std::endl;
  }

  return res;
}

void Integer::Division(const Integer& other, Integer* out_quotient, Integer* out_remainder) const
{
  if (other == 0)
    throw std::exception("Division by 0");
  Integer divisor = other;
  divisor.sign_ = POSITIVE;
  if (*this < divisor)
  {
    *out_quotient = 0;
    *out_remainder = *this;
    if (*this == 0)
      out_remainder->sign_ = NEUTRAL;
    else
      out_remainder->sign_ = POSITIVE;
    return;
  }
  if (this->getDigits() <= 19 && divisor.getDigits() <= 19)
  {
    unsigned long long dividend_aux = std::stoll(this->toString());
    unsigned long long divisor_aux = std::stoll(divisor.toString());
    *out_quotient = std::to_string(dividend_aux / divisor_aux);
    *out_remainder = std::to_string(dividend_aux % divisor_aux);

    if (this->sign_ != NEGATIVE && divisor.sign_ == NEGATIVE)
      out_quotient->sign_ = NEGATIVE;
    else if (this->sign_ == NEGATIVE && divisor.sign_ != NEGATIVE)
      out_quotient->sign_ = NEGATIVE;
    return;
  }
  if (this->getDigits() == divisor.getDigits() || this->getDigits() == divisor.getDigits() + 1)
  {
    Integer aux;
    Integer quotient;
    while (aux < *this)
    {
      aux += divisor;
      quotient += 1;
    }
    *out_quotient = quotient - 1;
    *out_remainder = aux - divisor - *this;
    if(out_remainder != 0)
      out_remainder->sign_ = POSITIVE;
    if (this->sign_ != NEGATIVE && divisor.sign_ == NEGATIVE)
      out_quotient->sign_ = NEGATIVE;
    else if (this->sign_ == NEGATIVE && divisor.sign_ != NEGATIVE)
      out_quotient->sign_ = NEGATIVE;
    return;
  }
  std::string quotient;
  std::string aux = this->toString();
  if (this->sign_ == NEGATIVE)
    aux = aux.substr(1);

  Integer dividend;
  Integer remainder;
  Integer aux_quotient;
  while (!aux.empty() && aux != "0")
  {
    if (divisor.getDigits() >= 19)
    {
      dividend = aux.substr(0, divisor.getDigits());
      if (dividend < divisor)
        dividend = aux.substr(0, divisor.getDigits() + 1);
    }
    else
    {
      dividend = aux.substr(0, 19);
    }
    aux = aux.substr(dividend.getDigits());
    dividend.Division(divisor, &aux_quotient, &remainder);

    if(remainder != 0 && !aux.empty())
      aux = remainder.toString() + aux;
    quotient += aux_quotient.toString();
  }

  Integer result_aux(quotient);

  if (this->sign_ != NEGATIVE && divisor.sign_ == NEGATIVE)
    result_aux.sign_ = NEGATIVE;
  else if (this->sign_ == NEGATIVE && divisor.sign_ != NEGATIVE)
    result_aux.sign_ = NEGATIVE;

  *out_quotient = result_aux;
  *out_remainder = remainder;
}

Integer::Integer(NodeInteger* node, Sign sign)
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
  if (*this == 0)
    this->sign_ = NEUTRAL;
  else if (sign != NEUTRAL)
    this->sign_ = sign;
  else
    this->sign_ = POSITIVE;
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
  std::string string = this->toString();
  if (string[0] == '-')
    string = string.substr(1);
  if (pivot >= static_cast<int>(string.length()))
  {
    *high = 0;
    *low = *this;
  }
  else
  {
    *high = string.substr(0, string.size() - pivot);
    *low = string.substr(string.size() - pivot);
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

Integer Integer::Neutral() const
{
  Integer aux = *this;
  aux.sign_ = NEUTRAL;
  return aux;
}

std::ostream& operator<<(std::ostream& out, const Integer& integer)
{
  out << integer.toString();
  return out;
}
