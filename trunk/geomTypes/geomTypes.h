/// Alvaro Cuno, Mar2008
/// Geometric types definition file

#ifndef _GEOMTYPES_H_
#define _GEOMTYPES_H_

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/// Defines a vector in the D-dimensional space
template <unsigned Dim, class Number>
class Vector {
public:
  /// Default constructor
  Vector() {
     for (int i=0; i<Dim; ++i) c[i] = 0;
  }
  /// Copy constructor
  Vector(const Vector &v) {
     *this = v;
  }
  /// 2D constructor
  Vector(Number x, Number y) {
     assert(Dim==2);
     c[0] = x; c[1] = y;
  }
  /// 3D constructor
  Vector(Number x, Number y, Number z) {
     assert(Dim==3);
     c[0] = x; c[1] = y; c[2] = z;
  }
  /// 4D constructor
  Vector(Number x, Number y, Number z, Number w) {
     assert(Dim==4);
     c[0] = x; c[1] = y; c[2] = z; c[3] = w;
  }
  /// Assignment operator
  const Vector& operator=(const Vector &v) {
     for (int i=0; i<Dim; ++i) c[i] = v.c[i];
     return *this;
  }
  /// read-only specific field operator
  const Number operator[](unsigned int i) const {
     assert(i<Dim);
     return c[i];
  }
  /// Vector + Vector operator
  Vector operator+(const Vector &u) {
     Vector v(*this);
     for (int i=0; i<Dim; ++i) v.c[i] += u[i];
     return v;
  }
  /// Vector - Vector operator
  Vector operator-(const Vector &u) {
     Vector v(*this);
     for (int i=0; i<Dim; ++i) v.c[i] -= u[i];
     return v;
  }
  Number operator*(const Vector &u) {
     Number dotp = 0.0;
     for (int i=0; i<Dim; ++i) dotp += c[i]*u[i];
     return dotp;
  }
  /// vector x scalar product
  Vector operator*(Number k) {
     Vector v(*this);
     for (int i=0; i<Dim; ++i) v.c[i] *= k;
     return v;
  }
  /// vector / scalar division
  Vector operator/(Number k) {
     Vector v(*this);
     for (int i=0; i<Dim; ++i) v.c[i] /= k;
     return v;
  }
  /// scalar x vector product
  template <unsigned D, class T>
  friend Vector<D,T> operator*(T, const Vector<D,T> &);
  /// output operator
  template <unsigned D, class T>
  friend ostream &operator<<(ostream &, const Vector<D,T> &);
  /// input operator
  template <unsigned D, class T>
  friend istream &operator>>(istream &, const Vector<D,T> &);

private:
  Number c[Dim]; // The vector's coordinates
};

/// Defines a point in the D-dimensional space
template <unsigned Dim, class Number>
class Point {
public:
  /// Default constructor
  Point() {
     for (int i=0; i<Dim; ++i) c[i] = 0;
  }
  /// Copy constructor
  Point(const Point &p) {
     *this = p;
  }
  /// 2D constructor
  Point(Number x, Number y) {
     assert(Dim==2);
     c[0] = x; c[1] = y;
  }
  /// 3D constructor
  Point(Number x, Number y, Number z) {
     assert(Dim==3);
     c[0] = x; c[1] = y; c[2] = z;
  }
  /// 4D constructor
  Point(Number x, Number y, Number z, Number w) {
     assert(Dim==4);
     c[0] = x; c[1] = y; c[2] = z; c[3] = w;
  }
  /// Assignment operator
  const Point& operator=(const Point &p) {
     for (int i=0; i<Dim; ++i) c[i] = p.c[i];
     return *this;
  }
  /// read-only specific field operator
  const Number operator[](unsigned int i) const {
     assert(i<Dim);
     return c[i];
  }
  /// Point + Vector operator
  Point operator+(const Vector<Dim, Number> &u) {
     Point p(*this);
     for (int i=0; i<Dim; ++i) p.c[i] += u[i];
     return p;
  }

  /// output operator
  template <unsigned D, class T>
  friend ostream &operator<<(ostream &, const Point<D,T> &);
  /// input operator
  template <unsigned D, class T>
  friend istream &operator>>(istream &, const Point<D,T> &);

private:
  Number c[Dim]; // The point's coordinates
};

/// Point output operator
template <unsigned Dim, class Number>
ostream &operator<<(ostream &out, const Point<Dim,Number> &p) {
  for (int i=0; i<Dim; ++i) out<<p.c[i]<<" ";
  return out;
}

/// Point input operator
template <unsigned Dim, class Number>
istream &operator>>(istream &in, const Point<Dim,Number> &p) {
  for (int i=0; i<Dim; ++i) in>>p.c[i];
  return in;
}

/// Vector output operator
template <unsigned Dim, class Number>
ostream &operator<<(ostream &out, const Vector<Dim,Number> &v) {
  for (int i=0; i<Dim; ++i) out<<v.c[i]<<" ";
  return out;
}

/// Vector input operator
template <unsigned Dim, class Number>
istream &operator>>(istream &in, const Vector<Dim,Number> &v) {
  for (int i=0; i<Dim; ++i) in>>v.c[i];
  return in;
}

/// scalar x Vector product
template <unsigned Dim, class Number>
Vector<Dim,Number> operator*(Number k, const Vector<Dim,Number> &v) {
  Vector<Dim, Number> u(v);
  for (int i=0; i<Dim; ++i) u.c[i] *= k;
  return u;
}

/// Returns the squared length of a vector
template <unsigned Dim, class Number>
Number squared_length(const Vector<Dim,Number> &v) {
  Vector<Dim, Number> u(v);
  return u*u;
}

/// Returns the length of a vector
template <unsigned Dim, class Number>
Number length(const Vector<Dim,Number> &v) {
  Vector<Dim, Number> u(v);
  return sqrt(u*u);
}

/// Returns a normalize vector
template <unsigned Dim, class Number>
Vector<Dim,Number> normalize(const Vector<Dim,Number> &v) {
  Vector<Dim, Number> u(v);
  Number n = sqrt(u*u);
  if (n==0) return u;
  else      return u/n;
}


/// cross product of two vector in 3D
template <unsigned Dim, class Number>
Vector<Dim,Number> cross_product(const Vector<Dim,Number> &u, const Vector<Dim,Number> &v) {

  assert(Dim==3);
  Number x = u[1]*v[2] - u[2]*v[1];
  Number y = u[2]*v[0] - u[0]*v[2];
  Number z = u[0]*v[1] - u[1]*v[0];
  return Vector<Dim,Number>(x,y,z);
}

#endif
