/*
  Filename   : lnorm.hpp
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  Lnorm class function definitions

*/

template<class T>
T Lnorm<T>::operator()(const std::vector< Quaternion<T> >& set)
{
  T result = set.front().mag();
  for(unsigned int i=1; i < set.size(); i++)
  {
    result += (set[i]).mag();
  }
  return result;
}
