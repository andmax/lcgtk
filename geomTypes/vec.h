/**
 *   Generic Vectors Class
 *
 * File: vec.h
 *
 * Author: Andre Maximo (andmax@gmail.com)
 *
 * Date: Jul 30, 2007
 *
 **/

/// --------------------------------------   Definitions   -----------------------------------------

#ifndef _VEC_H_
#define _VEC_H_

#include <iostream>
#include <cmath>

using namespace std;

/// ------------------------------------------   Vec   ---------------------------------------------

/// Template class for an array of values, such as vector or points,
/// where the dimension is also defined as template.
/// Ex.: vec< 3, double > p; defines a point p in R^3 with double
/// precision coordinates.
template <unsigned D, class T>
class vec {

private:

	T coord[D]; ///< D (dimension) coordinates of T type

public:

	/// Constructor
	/// @arg cN coordinate N
	vec() { clear(); }
	vec(T c0) { if (D<1) return;
		coord[0] = c0;
	}
	vec(T c0, T c1) { if (D<2) return;
		coord[0] = c0; coord[1] = c1;
	}
	vec(T c0, T c1, T c2) { if (D<3) return;
		coord[0] = c0; coord[1] = c1; coord[2] = c2;
	}
	vec(T c0, T c1, T c2, T c3) { if (D<4) return;
		coord[0] = c0; coord[1] = c1; coord[2] = c2; coord[3] = c3;
	}
	vec(T* c) { for(unsigned i=0; i<D; i++) coord[i] = c[i]; }
	vec(const vec<D,T>& v) { *this = v; }

	/// Destructor
	~vec() { }

	/// Clear values
	void clear(void) { for(unsigned i=0; i<D; i++) coord[i] = (T)0; }

	///--- Get functions ---

	/// Get (or swizzle) coordinate(s)
	/// @return coordinate(s) in any semantic
	inline T x(void) const { if (D>0) return coord[0]; }
	inline T y(void) const { if (D>1) return coord[1]; }
	inline T z(void) const { if (D>2) return coord[2]; }
	inline T w(void) const { if (D>3) return coord[3]; }
	inline T r(void) const { if (D>0) return coord[0]; }
	inline T g(void) const { if (D>1) return coord[1]; }
	inline T b(void) const { if (D>2) return coord[2]; }
	inline T a(void) const { if (D>3) return coord[3]; }
	vec<2,T> xy(void) const { if (D>1) return vec<2,T>(coord[0], coord[1]); }
	vec<2,T> rg(void) const { if (D>1) return vec<2,T>(coord[0], coord[1]); }
	vec<3,T> xyz(void) const { if (D>2) return vec<3,T>(coord[0], coord[1], coord[2]); }
	vec<3,T> rgb(void) const { if (D>2) return vec<3,T>(coord[0], coord[1], coord[2]); }
	inline const T* v(void) const { return coord; }
	inline const T* p(void) const { if (D>3) return vec<4,T>(coord[0], coord[1], coord[2], 1.0).v(); }

	///--- Math functions ---

	/// Squared length and length
	/// @return vector squared length value
	T sqrl(void) const { return (*this) ^ (*this); }
	/// @return vector length value
	T length(void) const { return sqrt( this->sqrl() ); }

	/// Apply rotation matrix (row-oriented)
	/// @arg m rotation matrix
	/// @arg d dimension of the vector to be rotated
	/// @arg nrows number of rows in matrix m
	/// @arg ncols number of cols in matrix m
	void rotate(const T *m, const unsigned& d=D, const unsigned& nrows=4, const unsigned& ncols=4) {
		vec<D,T> u;
		for (unsigned i=0; i<(nrows<d?nrows:d); i++)
			for (unsigned j=0; j<ncols; j++)
				u[i] += m[i*nrows + j] * ((j<d)?coord[j]:(T)1);
		if (d < D) for (unsigned i=d; i<D; i++) u[i] = coord[i];
		*this = u;
	}

	///--- Operators ---

	/// Normalize vector
	/// @return normalized vector
	vec<D,T> normalize(void) { return *this /= length(); }
	/// @arg l length used to normalize
	vec<D,T> normalize(const T& l) { return *this /= l; }

	/// Assign operator
	vec<D,T>& operator = (const vec<D,T>& v) {
		for(unsigned i=0; i<D; i++) this->coord[i] = v[i];
		return *this;
	}

	/// Negation operator
	vec<D,T>& operator - (void) {
		for(unsigned i=0; i<D; i++) this->coord[i] = -this->coord[i];
		return *this;
	}

	/// Subtraction operators
	vec<D,T> operator - (const T& s) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] - s;
		return u;
	}
	vec<D,T> operator - (const vec<D,T>& v) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] - v[i];
		return u;
	}
	vec<D,T>& operator -= (const vec<D,T>& v) {
		for(unsigned i=0; i<D; i++) this->coord[i] -= v[i];
		return *this;
	}

	/// Sum operators
	vec<D,T> operator + (const T& s) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] + s;
		return u;
	}
	vec<D,T> operator + (const vec<D,T>& v) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] + v[i];
		return u;
	}
	vec<D,T>& operator += (const vec<D,T>& v) {
		for(unsigned i=0; i<D; i++) this->coord[i] += v[i];
		return *this;
	}

	/// Multiply operators
	vec<D,T> operator * (const T& s) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] * s;
		return u;
	}
	vec<D,T> operator * (const vec<D,T>& v) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] * v[i];
		return u;
	}
	vec<D,T>& operator *= (const vec<D,T>& v) {
		for(unsigned i=0; i<D; i++) this->coord[i] *= v[i];
		return *this;
	}
	friend vec<D,T> operator * (const T& s, const vec<D,T>& v) {
		return v*s;
	}

	/// Division operators
	vec<D,T> operator / (const T& s) const {
		if (s == (T)0) return *this;
		vec<D,T> u;
		for(unsigned i=0; i<D; i++) u[i] = this->coord[i] / s;
		return u;
	}
	vec<D,T> operator / (const vec<D,T>& v) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++)
			if (v[i] != (T)0)
				u[i] = this->coord[i] / v[i];
		return u;
	}
	vec<D,T>& operator /= (const T& s) {
		if (s == (T)0) return *this;
		for(unsigned i=0; i<D; i++) this->coord[i] /= s;
		return *this;
	}

	/// Dot product operator
	T operator ^ (const vec<D,T>& v) const {
		T s = (T)0;
		for(unsigned i=0; i<D; i++)
			s += this->coord[i] * v[i];
		return s;
	}

	/// Cross product operator
	vec<D,T> operator % (const vec<D,T>& v) const {
		vec<D,T> u;
		for(unsigned i=0; i<D; i++)
			for(unsigned j=0; j<D-1; j++)
				u[i] += ((j%2)==0?+1:-1) * this->coord[(((i+1)%D)+1*j)%D] * v[(((i+2)%D)+2*j)%D];
		return u;
	}

        /// Comparison operators

	/// Equality
	friend bool operator == ( const vec<D,T>& v1, const vec<D,T>& v2 ) {
		bool b = true;
		for(unsigned i=0; i<D; ++i) b = b && (v1[i] == v2[i]);
		return b;
	}  
	friend bool operator == ( const vec<D,T>& v1, T& v2 ) {
		bool b = true;
		for(unsigned i=0; i<D; ++i) b = b && (v1[i] == v2);
		return b;
	}  

	/// I/O operator
	inline friend ostream& operator << (ostream& out, const vec<D,T>& v) {
		if (D==0) return out;
		for(unsigned i=0; i<D-1; ++i)
			out << v.coord[i] << " ";
		out << v.coord[D-1];
		return out;
	}
	inline friend istream& operator >> (istream& in, vec<D,T>& v) {
		for(unsigned i=0; i<D; ++i)
			in >> v.coord[i];
		return in;
	}

	/// Operator to grant read/write access to coordinate values
	inline T& operator [] (const uint& i) { return this->coord[i]; }
	inline const T& operator [] (const uint& i) const { return this->coord[i]; }
	inline const T* operator &(void) const { return coord; }

};

/// Template function to copy vec values with
/// different dimensions.
/// Ex.: vec< 4, int > b(1, 2, 3);
///      vec< 3, int > a;
///      copyVec( a, b ); /// a = (1, 2, 3, 0)
///
/// @arg v1 receive values from v2
/// @arg v2 copy values
template <unsigned D, unsigned D_, class T>
void copyVec( vec< D, T >& v1, const vec< D_, T >& v2 ) {

	for(unsigned i = 0; i < ((D_<D)?D_:D); ++i)
		v1[i] = v2[i];

}

#endif

/// ---------------------------------------------------------------------------------------------
