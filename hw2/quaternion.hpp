/*
  Filename   : quaternion.hpp
  Class      : CS328 Spring 2013
  Assignment : Program 2
  Programmer : Kyle jamison
  Date       : 2/17/2013

  Quaternion class function definitions

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
  *this += -(rhs);
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
Quaternion<T> Quaternion<T>::operator*(const T& rhs) const
{
  Quaternion<T> result = *this;
  result.m_a *= rhs;
  result.m_b *= rhs;
  result.m_c *= rhs;
  result.m_d *= rhs;
  return result;
}

template<class T>
Quaternion<T> Quaternion<T>::operator/(const Quaternion<T>& rhs) const
{
  //disvision is the same as h1 * inverse h2
  return (*this * rhs.inverse());
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
  try
  {
    switch(index)
    {
     case(0):
        result = m_a;
        break;
     case(1):
        result = m_b;
        break;
     case(2):
        result = m_c;
        break;
     case(3):
        result = m_d;
        break;
      default:
        throw RangeErr(index);
    }
  }
  catch(RangeErr e)
  {
    std::cerr << "Subscript is out of range: " << e.badSubscript();
  }
  return result;
}

template<class T>
Quaternion<T> Quaternion<T>::operator!() const
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

template<class T>
Quaternion<T> Quaternion<T>::inverse() const
{
  Quaternion<T> result = *this;
  T denom = ~result * ~result;
  try
  {
    if( denom == 0 )
      throw DivByZeroErr();
  }
  catch(DivByZeroErr e)
  {
    std::cerr << "Division by zero error!" << std::endl;
  }
  return ( !result * (1 / denom));
}

template<class T>
bool Quaternion<T>::operator==(const Quaternion<T>& rhs) const
{
  bool result;
  if(m_a==rhs.m_a && m_b==rhs.m_b && m_c==rhs.m_c && m_d==rhs.m_d)
    result = true;
  else
    result = false;
  return result;
}

template<class T>
bool Quaternion<T>::operator!=(const Quaternion<T>& rhs) const
{
  return !(*this==rhs);
}

template<class U>
std::istream& operator>>(std::istream& is, Quaternion<U>& h)
{
  is >> (h.m_a);
  is >> (h.m_b);
  is >> (h.m_c);
  is >> (h.m_d);
  return is;
}

template<class U>
std::ostream& operator<<(std::ostream& os, const Quaternion<U>& h)
{
  os << h.m_a << (h.m_b>=0 ? "+" : "-" );
  os << fabs(h.m_b) << "i" << (h.m_c>=0? "+" : "-" );
  os << fabs(h.m_c) << "j" << (h.m_d>=0? "+" : "-" );
  os << fabs(h.m_d) << "k";
  return os;
}
