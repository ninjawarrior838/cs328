#ifndef LNORM_H
#define LNORM_H

template<class T>
class Lnorm
{
  public:
    T operator()(const std::vector< Quaternion<T> >& set);
};

#include "lnorm.hpp"
#endif
