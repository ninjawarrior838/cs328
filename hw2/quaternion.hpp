/*
  File: quaternion.hpp
*/

template<class T>
Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& source)
{
  m_a = source.m_a;
  m_b = source.m_b;
  m_c = source.m_c;
  m_d = source.m_d;
  return *this;
}


template<class T>
Quaternion<T>& Quaternion<T>::operator+=(const Quaternion<T>& rhs)
{
  m_a += rhs.m_a;
  m_b += rhs.m_b;
  m_c += rhs.m_c;
  m_d += rhs.m_d;
  return *this;
}


template<class T>
Quaternion<T>& Quaternion<T>::operator-=(const Quaternion<T>& rhs)
{
  m_a -= rhs.m_a;
  m_b -= rhs.m_b;
  m_c -= rhs.m_c;
  m_d -= rhs.m_d;
  return *this;
}


template<class T>
Quaternion<T> Quaternion<T>::operator+(const Quaternion<T>& rhs) const
{
  Quaternion<T> result = *this;
  result += rhs;
  return result;
}

template<class T>
Quaternion<T> Quaternion<T>::operator-(const Quaternion<T>& rhs) const
{
  Quaternion<T> result = *this;
  result -= rhs;
  return result;
}

template<class T>
Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& rhs) const
{
  Quaternion<T> result;
  result.m_a = (m_a*rhs.m_a)-(m_b*rhs.m_b)-(m_c*rhs.m_c)-(m_d*rhs.m_d);
  result.m_b = (m_a*rhs.m_b)+(m_b*rhs.m_a)+(m_c*rhs.m_d)-(m_d*rhs.m_c);
  result.m_c = (m_a*rhs.m_c)-(m_b*rhs.m_d)+(m_c*rhs.m_a)+(m_d*rhs.m_b);
  result.m_d = (m_a*rhs.m_d)+(m_b*rhs.m_c)-(m_c*rhs.m_b)+(m_d*rhs.m_a);
  return result;
}

template<class T>
Quaternion<T> Quaternion<T>::operator/(const Quaternion<T>& rhs) const
{
  //Quaternion<T> result = *this
  //disvision is the same as h1 * inverse h2
  //inverse in the average of the coeff over the square of the norm
}

template<class T>
Quaternion<T> Quaternion<T>::operator-() const
{
  Quaternion<T> result;
  result.m_a = -m_a;
  result.m_b = -m_b;
  result.m_c = -m_c;
  result.m_d = -m_d;
  return result;
}

template<class T>
T Quaternion<T>::operator[](const int index) const
{
  T result;
  switch(index)
  {
    case(0)
      result = m_a;
      break;
    case(1)
      result = m_b;
      break;
    case(2)
      result = m_c;
      break;
    case(3)
      result = m_d;
      break;
    default
      break;
  }
  return result;
}

template<class T>
T Quaternion<T>::operator!() const
{
  Quaternion<T> result;
  result.m_a = m_a;
  result.m_b = -m_b;
  result.m_c = -m_c;
  result.m_d = -m_d;
  return result; 
}

template<class T>
T Quaternion<T>::operator~() const
{
  T result;
  result = sqrt((m_a*m_a)+(m_b*m_b)+(m_c*m_c)+(m_d*m_d));
  return result;
}

template<class T>
T Quaternion<T>::mag() const
{
  return ~(*this);
}
