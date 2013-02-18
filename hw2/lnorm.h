/*
  Filename   : lnorm.h
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  Class: Lnorm
  A functor class used to find the L1 norm of a vector of templated Quaternions

  Operator: T operator()(const std::vector< Quaternion<T> >& set)
  Returns the sum  of the magnatudes of every quaternion in the vector

*/

#ifndef LNORM_H
#define LNORM_H

#include <vector>

template<class T>
class Lnorm
{
  public:
    T operator()(const std::vector< Quaternion<T> >& set);
};

#include "lnorm.hpp"
#endif
