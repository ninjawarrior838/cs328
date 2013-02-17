
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
