#define CATCH_CONFIG_MAIN
#include <iostream>
#include <cmath>
#include "catch.hpp"
#include "Complex.hpp"

TEST_CASE( "Constructors instantiate objects correctly", "[constructor]" ) {
  Complex c1 = Complex();
  Complex c2 = Complex( 5 );
  Complex c3 = Complex( 5.5 );
  Complex c4 = Complex( 5.5, 1 );

  REQUIRE( c1.getReal() == 0 );
  REQUIRE( c1.getImg()  == 0 );

  REQUIRE( c2.getReal() == 5 );
  REQUIRE( c2.getImg()  == 0 );

  REQUIRE( c3.getReal() == 5.5 );
  REQUIRE( c3.getImg()  == 0 );

  REQUIRE( c4.getReal() == 5.5 );
  REQUIRE( c4.getImg()  == 1.0 );
}

TEST_CASE( "Copy Constructor works properly", "[copy]" ) {
  Complex c1 = Complex( 5 );
  Complex c2( c1 );

  REQUIRE( c2.getReal() == 5 );
  REQUIRE( c2.getImg()  == 0 );
}

TEST_CASE( "Copy assignment operator works properly", "[assignment]" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = c1;

  REQUIRE( c2.getReal() == 5 );
  REQUIRE( c2.getImg()  == 0 );
}

TEST_CASE( "Get r in polar form", "[getRho]" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = Complex( 3, 4 );

  REQUIRE( c1.getRho() == 5 );
  REQUIRE( c2.getRho() == 5 );
}

TEST_CASE( "Get theta from polar form", "[getTheta]" ) {
  /* TODO: Add more angle test cases */
  Complex c1 = Complex( 5.0 );

  REQUIRE( c1.getTheta() == 0 );
}

TEST_CASE( "Equality operator" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = Complex( 5 );
  Complex c3 = Complex( 1 );
  Complex c4 = Complex( 11, -5 );
  Complex c5 = Complex( 11, 5 );
  Complex c6 = Complex( 11, 5 );
  Complex c7 = Complex( 9, 5 );

  REQUIRE( ( c1 == c2 ) == true );
  REQUIRE( ( c1 == c3 ) == false );
  REQUIRE( ( c5 == c6 ) == true );
  REQUIRE( ( c4 == c5 ) == false );
  REQUIRE( ( c5 == c7 ) == false );
  REQUIRE( ( c4 == c7 ) == false );
}

TEST_CASE( "Inequality operator" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = Complex( 5 );
  Complex c3 = Complex( 1 );
  Complex c4 = Complex( 11, -5 );
  Complex c5 = Complex( 11, 5 );
  Complex c6 = Complex( 11, 5 );
  Complex c7 = Complex( 9, 5 );

  REQUIRE( ( c1 != c2 ) == false );
  REQUIRE( ( c1 != c3 ) == true );
  REQUIRE( ( c5 != c6 ) == false );
  REQUIRE( ( c4 != c5 ) == true );
  REQUIRE( ( c5 != c7 ) == true );
  REQUIRE( ( c4 != c7 ) == true );
}

TEST_CASE( "Comparison operators" ) {
  Complex c1 = Complex( 5.5, -9 );
  Complex c2 = Complex( 5, -9 );
  Complex c3 = Complex( 6, -9 );
  Complex c4 = Complex( 5.5, -8 );
  Complex c5 = Complex( 5.5, -10 );
  Complex c6 = Complex( 5.5, -9 );

  REQUIRE( ( c1 < c2 ) == false );
  REQUIRE( ( c1 <= c2 ) == false );
  REQUIRE( ( c1 > c2 ) == true );
  REQUIRE( ( c1 >= c2 ) == true );

  REQUIRE( ( c1 < c3 ) == true );
  REQUIRE( ( c1 <= c3 ) == true );
  REQUIRE( ( c1 > c3 ) == false );
  REQUIRE( ( c1 >= c3 ) == false );

  REQUIRE( ( c1 < c4 ) == false );
  REQUIRE( ( c1 <= c4 ) == false );
  REQUIRE( ( c1 > c4 ) == true );
  REQUIRE( ( c1 >= c4 ) == true );

  REQUIRE( ( c1 < c5 ) == true );
  REQUIRE( ( c1 <= c5 ) == true );
  REQUIRE( ( c1 > c5 ) == false );
  REQUIRE( ( c1 >= c5 ) == false );

  REQUIRE( ( c1 < c6 ) == false );
  REQUIRE( ( c1 <= c6 ) == true );
  REQUIRE( ( c1 > c6 ) == false );
  REQUIRE( ( c1 >= c6 ) == true );
}

TEST_CASE( "string() method", "[string]" ) {
  Complex c1 = Complex( 5, 5 );
  Complex c2 = Complex( 5, -5 );
  Complex c3 = Complex( -5, 5 );
  Complex c4 = Complex( -5, -5 );

  REQUIRE( c1.string() == "5 + 5i" );
  REQUIRE( c2.string() == "5 - 5i" );
  REQUIRE( c3.string() == "-5 + 5i" );
  REQUIRE( c4.string() == "-5 - 5i" );
}

TEST_CASE( "addition operator", "[+]" ) {
  Complex c1 = Complex( 5, 5 );
  Complex c2 = Complex( 3, 3 );
  Complex c3 = Complex( 5, 0 );
  Complex c4 = Complex( 0, 5 );

  Complex c5 = c1 + c2;
  Complex c6 = c1 + c3;
  Complex c7 = c1 + c4;
  Complex c8 = c3 + c4;

  REQUIRE( c5.getReal() == 8 );
  REQUIRE( c5.getImg()  == 8 );
  REQUIRE( c6.getReal() == 10 );
  REQUIRE( c6.getImg()  == 5 );
  REQUIRE( c7.getReal() == 5 );
  REQUIRE( c7.getImg()  == 10 );
  REQUIRE( c8.getReal() == 5 );
  REQUIRE( c8.getImg()  == 5 );
}

TEST_CASE( "subtraction operator", "[-]" ) {
  Complex c1 = Complex( 5, 5 );
  Complex c2 = Complex( 4, 4 );

  Complex c3 = c1 - c2;
  Complex c4 = c2 - c1;

  REQUIRE( c3.getReal() == 1 );
  REQUIRE( c3.getImg()  == 1 );
  REQUIRE( c4.getReal() == -1 );
  REQUIRE( c4.getImg()  == -1 );
}

TEST_CASE( "multiplication operator", "[*]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -1, -1 );
  Complex c4 = Complex( 4, 4 );
  Complex c5 = Complex( 4, -4 );
  Complex c6 = Complex( -4, 4 );

  Complex c7 = c1 * c2;
  Complex c8 = c1 * c3;
  Complex c9 = c1 * c5;
  Complex c10 = c5 * c6;
  Complex c11 = c6 * c4;

  REQUIRE( c7.getReal() == 2 );
  REQUIRE( c7.getImg()  == 2 );
  REQUIRE( c8.getReal() == -1 );
  REQUIRE( c8.getImg()  == -1 );
  REQUIRE( c9.getReal() == 4 );
  REQUIRE( c9.getImg()  == -4 );
  REQUIRE( c10.getReal() == -16 );
  REQUIRE( c10.getImg()  == -16 );
  REQUIRE( c11.getReal() == -16 );
  REQUIRE( c11.getImg()  == 16 );
}

TEST_CASE( "division operator", "[/]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -1, -1 );
  Complex c4 = Complex( 4, 4 );
  Complex c5 = Complex( 4, -4 );
  Complex c6 = Complex( -4, 4 );

  Complex c7 = c2 / c1;
  Complex c8 = c5 / c2;
  Complex c9 = c6 / c4;
  Complex c10 = c4 / c3;

  REQUIRE( c7.getReal() == 2 );
  REQUIRE( c7.getImg()  == 2 );
  REQUIRE( c8.getReal() == 2 );
  REQUIRE( c8.getImg()  == -2 );
  REQUIRE( c9.getReal() == -1 );
  REQUIRE( c9.getImg()  == 1 );
  REQUIRE( c10.getReal() == -4 );
  REQUIRE( c10.getImg()  == -4 );
}

TEST_CASE( "addition assign operator", "[+=]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -2, -2 );
  Complex c4 = Complex();
  
  c1 += c2;
  c2 += c3;
  c3 += c4;

  REQUIRE( c1.getReal() == 3 );
  REQUIRE( c1.getImg()  == 3 );
  REQUIRE( c2.getReal() == 0 );
  REQUIRE( c2.getImg()  == 0 );
  REQUIRE( c3.getReal() == -2 );
  REQUIRE( c3.getImg()  == -2 );
}

TEST_CASE( "subtraction assign operator", "[-=]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -2, -2 );
  Complex c4 = Complex();

  c1 -= c4;
  REQUIRE( c1.getReal() == 1 );
  REQUIRE( c1.getImg()  == 1 );
  c1 -= c2;
  REQUIRE( c1.getReal() == -1 );
  REQUIRE( c1.getImg()  == -1 );
  c2 -= c3;
  REQUIRE( c2.getReal() == 4 );
  REQUIRE( c2.getImg()  == 4 );
}

TEST_CASE( "multiplication assign operator", "[*=]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -2, -2 );
  Complex c4 = Complex();

  c2 *= c1;
  REQUIRE( c2.getReal() == 2 );
  REQUIRE( c2.getImg()  == 2 );
  c3 *= c1;
  REQUIRE( c3.getReal() == -2 );
  REQUIRE( c3.getImg()  == -2 );
  c3 *= c2;
  REQUIRE( c3.getReal() == -4 );
  REQUIRE( c3.getImg()  == -4 );

  c1 *= c4;
  REQUIRE( c1.getReal() == 0 );
  REQUIRE( c1.getImg()  == 0 );
}

TEST_CASE( "division assign operator", "[/=]" ) {
  Complex c1 = Complex( 1, 1 );
  Complex c2 = Complex( 2, 2 );
  Complex c3 = Complex( -2, -2 );
  Complex c4 = Complex();

  c2 /= c1;
  c3 /= c1;
  REQUIRE( c2.getReal() == 2 );
  REQUIRE( c2.getImg()  == 2 );
  REQUIRE( c3.getReal() == -2 );
  REQUIRE( c3.getImg()  == -2 );
  c2 /= c4;
  REQUIRE( c2.getReal() == 0 );
  REQUIRE( c2.getImg()  == 0 );
}

TEST_CASE( "Cartesian to_string", "[stringCart]" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = Complex( 5, 5 );
  Complex c3 = Complex( 5, -5 );
  Complex c4 = Complex( -5, 5 );
  Complex c5 = Complex( -5, -5 );

  REQUIRE( c1.stringCart() == "( 5, 0 )" );
  REQUIRE( c2.stringCart() == "( 5, 5 )" );
  REQUIRE( c3.stringCart() == "( 5, -5 )" );
  REQUIRE( c4.stringCart() == "( -5, 5 )" );
  REQUIRE( c5.stringCart() == "( -5, -5 )" );
}

TEST_CASE( "Polar to_string", "[stringPolar]" ) {
  Complex c1 = Complex( 5 );
  Complex c2 = Complex( 5, 5 );
  Complex c3 = Complex( 5, -5 );
  Complex c4 = Complex( -5, 5 );
  Complex c5 = Complex( -5, -5 );

  REQUIRE( c1.stringPolar() == "( 5, 0 )" );
  REQUIRE( c2.stringPolar() == "( 7.07107, 0.785398 )" );
  REQUIRE( c3.stringPolar() == "( 7.07107, -0.785398 )" );
  REQUIRE( c4.stringPolar() == "( 7.07107, -0.785398 )" );
  REQUIRE( c5.stringPolar() == "( 7.07107, 0.785398 )" );
}

/*TEST_CASE( "complex from polar constructor" ) {
  Complex c1 = complexFromPolar( sqrt(2), 45 );
  REQUIRE( c1.getReal() == 1 );
  REQUIRE( c1.getImg()  == 1 );
  } 

TEST_CASE( "istream", "[istream]") {
}

TEST_CASE( "ostream", "[ostream]") {
  Complex c1 = Complex(); // real = 0, img = 0
  ostream os1, os2;
  os1 << c1;
  os2 << "0 + 0i";
  
  REQUIRE( os1 == os2 );
  } */
