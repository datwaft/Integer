#ifndef INTEGER_SRC_INTEGER_H_
#define INTEGER_SRC_INTEGER_H_

#include <iostream>

#include "basicinteger.h"
#include "arrayinteger.h"
#include "nodeinteger.h"
#include "sign.h"

#define ZERO Integer(0);
#define ONE Integer(0);

class Integer
{
public:
  Integer(const int& = 0);
  Integer(const long&);
  Integer(const std::string&);
  Integer(const BasicInteger&);
  Integer(const ArrayInteger&);
  Integer(const NodeInteger&);
  Integer(const Integer&);
  void operator = (const int&);
  void operator = (const long&);
  void operator = (const std::string&);
  void operator = (const BasicInteger&);
  void operator = (const ArrayInteger&);
  void operator = (const NodeInteger&);
  void operator = (const Integer&);
  void operator += (const Integer&);
  void operator -= (const Integer&);
  void operator *= (const Integer&);
  void operator /= (const Integer&);
  ~Integer();
  void setInteger(const int&);
  void setInteger(const long&);
  void setInteger(const std::string&);
  void setInteger(const BasicInteger&);
  void setInteger(const ArrayInteger&);
  void setInteger(const NodeInteger&);
  void setInteger(const Integer&);
  int getCurrentSize() const;
  int getDigits() const;
  bool operator == (const Integer&) const;
  bool operator != (const Integer&) const;
  bool operator > (const Integer&) const;
  bool operator < (const Integer&) const;
  bool operator >= (const Integer&) const;
  bool operator <= (const Integer&) const;
  Integer operator + (const Integer&) const;
  Integer operator - (const Integer&) const;
  Integer operator * (const Integer&) const;
  Integer operator / (const Integer&) const;
  friend std::ostream& operator<<(std::ostream&, const Integer&);
  Integer Complement() const;
  Integer Complement(int) const;
  std::string toString() const;
  static Integer Parse(const std::string&);
private:
  Integer(NodeInteger*, Sign = POSITIVE);
  void Clear();
  void Clear(NodeInteger*);
  Integer AddRightPadding(int) const;
  void Split(Integer*, Integer*, int) const;
  void DeleteLeftPadding();
  Integer AppendToRight(Integer) const;
  Integer Neutral() const;
  int current_size_;
  NodeInteger* first_;
  NodeInteger* last_;
  Sign sign_;
};

#endif // INTEGER_SRC_INTEGER_H_
