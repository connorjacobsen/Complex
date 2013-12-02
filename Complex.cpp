#include "Complex.hpp"
#include <cmath>

/* Constructors */
Complex Complex::complexFromPolar( double rho, double theta ) {
  // theta must be given in degrees
  double r = rho * cos( theta );
  double i = rho * sin( theta );
  return Complex( r, i );
}

/* Copy Assignment Operator */
Complex& Complex::operator=( const Complex& c ) {
  real = c.real;  // use built in double::operator=
  img  = c.img;   // use built in double::operator=
  return *this;        // return a reference to the object
}

/* Comparison Operators */
bool Complex::operator==( const Complex& c ) const {
  return getReal() == c.getReal() && getImg() == c.getImg();
}

bool Complex::operator!=( const Complex& c ) const {
  return getReal() != c.getReal() || getImg() != c.getImg();
}

bool Complex::operator<( const Complex& c ) const {
  double mag = sqrt(( getReal() * getReal() ) + ( getImg() * getImg() ));
  double magC = sqrt(( c.getReal() * c.getReal() ) + ( c.getImg() * c.getImg() ));
  if ( mag < magC )                 // compare magnitudes
    return true;
  if ( mag == magC )  // compare angles
    return getTheta() < c.getTheta();
  return false;
}

bool Complex::operator<=( const Complex& c ) const {
  double mag = sqrt( getReal() * getReal() + getImg() * getImg() );
  double magC = sqrt( c.getReal() * c.getReal() + c.getImg() * c.getImg() );
  if ( mag <= magC )                 // compare magnitudes
    return true;
  if ( mag == magC )  // compare angles
    return getTheta() <= c.getTheta();
  return false;
}

bool Complex::operator>( const Complex& c ) const {
  double mag = sqrt( getReal() * getReal() + getImg() * getImg() );
  double magC = sqrt( c.getReal() * c.getReal() + c.getImg() * c.getImg() );
  if ( mag > magC )                 // compare magnitudes
    return true;
  if ( mag == magC )  // compare angles
    return getTheta() > c.getTheta();
  return false;
}

bool Complex::operator>=( const Complex& c ) const {
  double mag = sqrt( getReal() * getReal() + getImg() * getImg() );
  double magC = sqrt( c.getReal() * c.getReal() + c.getImg() * c.getImg() );
  if ( mag >= magC )                 // compare magnitudes
    return true;
  if ( mag == magC )  // compare angles
    return getTheta() >= c.getTheta();
  return false;
}

/* Accessors */
double Complex::getReal() const {
  return real;
}

double Complex::getImg() const {
  return img;
}

double Complex::getRho() const {
  double a = real * real;
  double b = img  * img;
  double rSquared = a + b;
  return sqrt( rSquared );
}

double Complex::getTheta() const {
  double tmp = 0;
  if ( real != 0 )
    tmp = ( img / real );
  return atan( tmp );
}

/* Setters */
void Complex::setReal( double r ) {
  real = r;
}

void Complex::setImg( double i ) {
  img = i;
}

/* toString */
std::string Complex::string() const {
  std::string i = "";
  double img = getImg();
  std::string marker = " + ";
  if ( getImg() < 0 ) {
    marker = " - ";
    img *= -1;
  }
  std::string r = digitToString( getReal() );
  i = digitToString( img );
  return r + marker + i + "i";
}

std::string Complex::stringCart() {
  std::string r = digitToString( getReal() );
  std::string i = digitToString( getImg() );
  return "( " + r + ", " + i + " )";
}

std::string Complex::stringPolar() {
  double rho = getRho();
  double theta = getTheta();
  std::string r = digitToString( rho );
  std::string t = digitToString( theta );
  return "( " + r + ", " + t + " )";
}

/* Arithmetic Operators */
Complex operator+( const Complex& lhs, const Complex& rhs ) {
  Complex ans = lhs; 
  ans.setReal( lhs.getReal() + rhs.getReal() );
  ans.setImg( lhs.getImg() + rhs.getImg() );
  return ans;
}

Complex operator-( const Complex& lhs, const Complex& rhs ) {
  Complex ans = lhs;
  ans.setReal( lhs.getReal() - rhs.getReal() );
  ans.setImg( lhs.getImg() - rhs.getImg() );
  return ans;
}

Complex operator*( const Complex& lhs, const Complex& rhs ) {
  Complex ans = lhs;
  ans.setReal( lhs.getReal() * rhs.getReal() );
  ans.setImg( lhs.getImg() * rhs.getImg() );
  return ans;
}

Complex operator/( const Complex& lhs, const Complex& rhs ) {
  Complex ans = lhs;
  if ( rhs.getReal() == 0 )
    ans.setReal( 0 );
  else
    ans.setReal( lhs.getReal() / rhs.getReal() );

  if ( rhs.getImg() == 0 )
    ans.setImg( 0 );
  else
    ans.setImg( lhs.getImg() / rhs.getImg() );
  return ans;
}

Complex operator+=( Complex& lhs, const Complex& rhs ) {
  lhs.setReal( lhs.getReal() + rhs.getReal() );
  lhs.setImg( lhs.getImg() + rhs.getImg() );
}

Complex operator-=( Complex& lhs, const Complex& rhs ) {
  lhs.setReal( lhs.getReal() - rhs.getReal() );
  lhs.setImg( lhs.getImg() - rhs.getImg() );
}

Complex operator*=( Complex& lhs, const Complex& rhs ) {
  lhs.setReal( lhs.getReal() * rhs.getReal() );
  lhs.setImg( lhs.getImg() * rhs.getImg() );
}

Complex operator/=( Complex& lhs, const Complex& rhs ) {
  if ( rhs.getReal() == 0 )
    lhs.setReal( 0 );
  else
    lhs.setReal( lhs.getReal() / rhs.getReal() );

  if ( rhs.getImg() == 0 )
    lhs.setImg( 0 );
  else
    lhs.setImg( lhs.getImg() / rhs.getImg() );
}

/* Stream Operators */
std::ostream& operator<<( std::ostream& os, const Complex& c ) {
  os << c.string();
  return os;
}

std::istream& operator>>( std::istream& is, Complex& c ) {
  double r, img;
  std::string i;
  std::string m; // holder the + or - sign
  is >> r >> m >> i;
  if ( is ) {
    c.setReal( r );
    i.pop_back(); // remove last element in string, should be i
    img = stod( i ); // convert i into a double, img
    if ( m == "-" ) { img *= -1; } // img should be negative
    c.setReal( r );
    c.setImg( img );
  } else
    c = Complex();
}
