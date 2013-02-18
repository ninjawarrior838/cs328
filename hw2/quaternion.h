/*
  Filename   : quaternion.h
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  Class: Quaternion
  An implementation of a mathmatical quaternion.

  Constructor: Quaternion()
  Initializes a new quaternion with 0 for every coefficient.

  Constructor: Quaternion( const T& a, const T& b, const T& c, const T& d)
  Initializes a new quaternion with a, b, c, and d as the real number,
  the i coefficient, the j coefficient, and the k coefficent respecfully.

  Operator: Quaternion<T>& operator=(const Quaternion<T>& source)
  Duplicates the contents of source

  Operator: Quaternion<T>& operator+=(const Quaternion<T>& rhs)
  Adds the coefficents of rhs to the calling objects coefficients

  Operator: Quaternion<T>& operator-=(const Quaternion<T>& rhs)
  Subtracts the coefficents of rhs from the calling objects coefficients

  Operator: Quaternion<T> operator+(const Quaternion<T>& rhs) const
  Returns a new Quaternion with the coefficients values as the sum of the
  calling object and rhs

  Operator: Quaternion<T> operator-(const Quaternion<T>& rhs) const
  Returns a new Quaternion with the coefficients values as the difference of
  the calling object and rhs
  
  Operator: Quaternion<T> operator*(const Quaternion<T>& rhs) const
  Returns a new Quaternion with the coefficent values of the product of the 
  calling object and rhs

  Operator: Quaternion<T> operator*(const T& rhs) const
  Returns a new Quaternion with the coefficents multiplied by the scaller rhs

  Operator: Quaternion<T> operator/(const Quaternion<T>& rhs) const
  Returns a new Quaternion whos coefficient values are the calling object
  divided by rhs

  Operator: Quaternion<T> operator-() const
  Returns a new Quaternion whos coefficients are inverted from the calling
  object

  Operator: Quaternion<T> operator!() const
  Returns a new Quaternion that represents the conjugate of the calling object

  Operator: T operator[](const int index) const
  Returns the value of the coefficient asked for with index starting at 0.
  If an index is out of range, it will throw a RangeErr

  Operator: T operator~() const
  Returns the magnitude of the calling object

  Function: T mag() const
  Returns the magnitude of the calling object
  
  Function: Quaternion<T> inverse() const
  Returns a new Quaternion that is the inverse of the calling object

  Operator: bool operator==(const Quaternion<T>& rhs) const
  Returns True if the calling object and rhs are equivalant, else false

  Operator: bool operator!=(const Quaternion<T>& rhs) const
  Returns True if the calling object and rhs are not equivalant, else false

  Operator: friend std::istream& operator>> (std::istream& is, Quaternion<U> &h)
  Overloaded istream used to take in 4 coefficients and create a Quaternion

  Operator: friend std::ostream& operator<< (std::ostream& os, const Quaternion<U> &h)
  Overloaded ostream used to properly format output of a quaternion

*/

#ifndef QUATERNION_H
#define QUARTERION_H

#include <iostream>
#include <math.h>
#include "rangeErr.h"
#include "divByZeroErr.h"

template<class T>
class Quaternion
{
public:
  Quaternion(): m_a(0), m_b(0), m_c(0), m_d(0) {}
  Quaternion( const T& a, const T& b, const T& c, const T& d): m_a(a), m_b(b), m_c(c), m_d(d) {}
  ~Quaternion() {}
  
  Quaternion<T>& operator=(const Quaternion<T>& source);
  Quaternion<T>& operator+=(const Quaternion<T>& rhs);
  Quaternion<T>& operator-=(const Quaternion<T>& rhs);
  Quaternion<T> operator+(const Quaternion<T>& rhs) const;
  Quaternion<T> operator-(const Quaternion<T>& rhs) const;
  Quaternion<T> operator*(const Quaternion<T>& rhs) const;
  Quaternion<T> operator*(const T& rhs) const;
  Quaternion<T> operator/(const Quaternion<T>& rhs) const;
  Quaternion<T> operator-() const;
  Quaternion<T> operator!() const;
  T operator[](const int index) const;
  T operator~() const; 
  T mag() const;
  Quaternion<T> inverse() const;
  bool operator==(const Quaternion<T>& rhs) const;
  bool operator!=(const Quaternion<T>& rhs) const;

  template<class U>
  friend std::istream& operator>> (std::istream& is, Quaternion<U> &h);
  template<class U>
  friend std::ostream& operator<< (std::ostream& os, const Quaternion<U> &h);

private:
  T m_a;
  T m_b;
  T m_c;
  T m_d;
};

#include "quaternion.hpp"
#endif

