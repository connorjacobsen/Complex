#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>

class Complex {
  double real;
  double img;
public:
  /* Constructors */
  Complex() : real( 0 ), img( 0 ) {}
  Complex( int r ) : real( r ), img( 0 ) {}
  Complex( double r ) : real( r ), img( 0 ) {}
  Complex( double r, double i ) : real( r ), img( i ) {}
  /* Copy Constructor */
  Complex( const Complex& c ) : real( c.real ), img( c.img ) {}
  /* Copy Assignment Operator */
  Complex& operator=( const Complex& c );
  /* Move Constructor */
  Complex( Complex&& c ) : real( std::move( c.getReal() ) ), img( std::move( c.getImg() ) ) {}

  /* Comparison Operators */
  bool operator==( const Complex& c ) const;
  bool operator!=( const Complex& c ) const;
  bool operator<( const Complex& c ) const;
  bool operator<=( const Complex& c ) const;
  bool operator>( const Complex& c ) const;
  bool operator>=( const Complex& c ) const;

  /* Accessors */
  double getReal() const;
  double getImg() const;
  double getRho() const;
  double getTheta() const;

  /* Setters */
  void setReal( double r );
  void setImg( double i );

  /* Complex From Polar function */
  Complex complexFromPolar( double rho, double theta );

  /* toString */
  std::string string() const;
  std::string stringCart();
  std::string stringPolar();
};

/* Digit-to-string template function */
template <typename T>
std::string digitToString( T digit ) {
  std::ostringstream os;
  os << digit;
  return os.str();
}

/* Arithmetic Operators */
Complex operator+( const Complex& lhs, const Complex& rhs );
Complex operator-( const Complex& lhs, const Complex& rhs );
Complex operator*( const Complex& lhs, const Complex& rhs );
Complex operator/( const Complex& lhs, const Complex& rhs );
Complex operator+=( Complex& lhs, const Complex& rhs );
Complex operator-=( Complex& lhs, const Complex& rhs );
Complex operator*=( Complex& lhs, const Complex& rhs );
Complex operator/=( Complex& lhs, const Complex& rhs );

/* Stream Operators */
std::ostream& operator<<( std::ostream& os, const Complex& c );
std::istream& operator>>( std::istream& is, Complex& c );
