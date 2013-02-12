#ifndef QUATERNION_H
#define QUARTERION_H

#include <iostream>
using std::istream;
using std::ostream;

template<class T>
class Quaternion
{
public:
	Quaternion(): m_a(0), m_b(0), m_c(0), m_d(0) {}
	Quaternion( const T& a, const T& b, const T& c, const T& d): m_a(a), m_b(b), m_c(c), m_d(d) {}
	~Quaternion() {}
	
	Quaternion<T>& operator=(const Quaternion<T>& source); //good
	Quaternion<T>& operator+=(const Quaternion<T>& rhs); //good
	Quaternion<T>& operator-=(const Quaternion<T>& rhs); //good
	Quaternion<T> operator+(const Quaternion<T>& rhs) const; //reuse above code
	Quaternion<T> operator-(const Quaternion<T>& rhs) const; //reuse above code
	Quaternion<T> operator*(const Quaternion<T>& rhs) const; //good
	Quaternion<T> operator/(const Quaternion<T>& rhs) const; //good
	const Quaternion<T>& operator[](const int index) const; //might not be an int
	Quaternion<T> operator-() const; //good
	T operator!();
	T operator~() const;
	T mag() const;
	bool operator==(const Quaternion<T>& rhs) const;
	bool operator!=(const Quaternion<T>& rhs) const;

	//friend istream& operator>> <>(istream& is, Quaternion<T> &b);
	//friend ostream& operator<< <>(ostream& os, const Quaternion<T> &b);

private:
	T m_a;
	T m_b;
	T m_c;
	T m_d;
};

#include "quaternion.hpp"
#endif

