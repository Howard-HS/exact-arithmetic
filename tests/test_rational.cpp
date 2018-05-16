#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE rationalClass
#include <boost/test/unit_test.hpp>

#include "rational.h"

BOOST_AUTO_TEST_SUITE(multiplication)

BOOST_AUTO_TEST_CASE(checkEqual)
{
  BOOST_CHECK_EQUAL(ExactArithmetic::Rational(1, 3) * ExactArithmetic::Rational(1, 3), ExactArithmetic::Rational(1, 9));
}

BOOST_AUTO_TEST_SUITE_END()