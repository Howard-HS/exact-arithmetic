#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE rationalClass
#include <boost/test/unit_test.hpp>

#include "rational.h"

using namespace ExactArithmetic;
namespace utf = boost::unit_test;

// Test suite: arithmetic_operations
BOOST_AUTO_TEST_SUITE(arithmetic_operations)
BOOST_AUTO_TEST_CASE(addition)
{
  BOOST_CHECK_EQUAL(Rational(1, 3) + Rational(1, 3), Rational(2, 3));
}

BOOST_AUTO_TEST_CASE(subtraction)
{
  BOOST_CHECK_EQUAL(Rational(1, 3) - Rational(1, 3), Rational(0, 1));
}

BOOST_AUTO_TEST_CASE(multiplication)
{
  BOOST_CHECK_EQUAL(Rational(1, 3) * Rational(1, 3), Rational(1, 9));
}

BOOST_AUTO_TEST_CASE(division)
{
  BOOST_CHECK_EQUAL(Rational(1, 3) / Rational(1, 3), Rational(1, 1));
}
BOOST_AUTO_TEST_SUITE_END()
// End of test suite: arithmetic operations

// Test suite: constructors
BOOST_AUTO_TEST_SUITE(constructors)

BOOST_AUTO_TEST_CASE(default_constructor)
{
  // Test default constructor
  Rational defaultConstructor;
  BOOST_CHECK_EQUAL(defaultConstructor, Rational(0, 1));
}

BOOST_AUTO_TEST_CASE(two_thirds)
{
  // Test a num/denom constructor
  Rational twoThirds(2, 3);
  BOOST_CHECK_EQUAL(twoThirds, Rational(2, 3));
}

BOOST_AUTO_TEST_CASE(four_eight)
{
  // Test normalization
  Rational fourEight(4, 8);
  BOOST_CHECK_EQUAL(fourEight, Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(integer_constructor)
{
  // Test integer constructor
  Rational integerConstructor(4);
  BOOST_CHECK_EQUAL(integerConstructor, Rational(4, 1));
}

BOOST_AUTO_TEST_CASE(double_constructor)
{
  // Test double constructor
  Rational doubleConstructor(4.0);
  BOOST_CHECK_EQUAL(doubleConstructor, Rational(4, 1));
}

BOOST_AUTO_TEST_SUITE_END()
// End of test suite: constructors

// Test suite: gcd
BOOST_AUTO_TEST_SUITE(gcd)
BOOST_AUTO_TEST_CASE(obvious)
{
  Rational veryBigRationalNumber(1000000000000000000, 2000000000000000000);
  BOOST_CHECK_EQUAL(veryBigRationalNumber, Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(random)
{
  Rational veryBigRationalNumber(98822773366119922, 22773399118822);
  BOOST_CHECK_EQUAL(veryBigRationalNumber, Rational(49411386683059961, 11386699559411));
}
BOOST_AUTO_TEST_SUITE_END()
// End of test suite: gcd


BOOST_AUTO_TEST_SUITE(miscellaneous)
BOOST_AUTO_TEST_CASE(abs_function)
{
  Rational negativeOneTwo(-1, 2);
  BOOST_CHECK_EQUAL(Rational::abs(negativeOneTwo), Rational(1, 2));
}

BOOST_AUTO_TEST_CASE(negative)
{
  Rational negativeOneTwo(-1, 2);
  Rational negativeOneTwoOnDenom(1, -2);
  BOOST_CHECK_EQUAL(negativeOneTwo, Rational(-1, 2));
  BOOST_CHECK_EQUAL(negativeOneTwoOnDenom, Rational(-1, 2));
}

BOOST_AUTO_TEST_CASE(negate_function)
{
  Rational negativeOneTwo(-1, 2);
  Rational negativeOneTwoOnDenom(1, -2);

  Rational oneTwo(1, 2);

  BOOST_CHECK_EQUAL(Rational::negate(negativeOneTwo), Rational(1, 2));
  BOOST_CHECK_EQUAL(Rational::negate(negativeOneTwoOnDenom), Rational(1, 2));
  BOOST_CHECK_EQUAL(Rational::negate(oneTwo), Rational(-1, 2));
}
BOOST_AUTO_TEST_SUITE_END()
