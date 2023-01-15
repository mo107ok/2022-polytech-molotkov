#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "MyComplex.h"

TEST_CASE("sum of MyComplex numbers")
{
  CHECK_EQ(MyComplex(1, 0)+MyComplex(2, 0), MyComplex(3, 0));
  CHECK_EQ(MyComplex(-1, 0)+MyComplex(2, 0), MyComplex(1, 0));
  CHECK_EQ(MyComplex(1, 1)+MyComplex(0, 2), MyComplex(1, 3));
  CHECK_EQ(MyComplex(0, -2)+MyComplex(0, 3), MyComplex(0, 1));
}

TEST_CASE("sub of MyComplex numbers")
{
  CHECK_EQ(MyComplex(1, 0)-MyComplex(2, 0), MyComplex(-1, 0));
  CHECK_EQ(MyComplex(-1, 0)-MyComplex(2, 0), MyComplex(-3, 0));
  CHECK_EQ(MyComplex(1, 1)-MyComplex(0, 2), MyComplex(1, -1));
  CHECK_EQ(MyComplex(0, -2)-MyComplex(0, 3), MyComplex(0, -5));
}

TEST_CASE("abs of MyComplex numbers")
{
  CHECK_EQ(MyComplex(1, 0).abs(), 1);
  CHECK_EQ(MyComplex(-1, 0).abs(), 1);
  CHECK_EQ(MyComplex(1, 1).abs(), doctest::Approx(1.41421).epsilon(0.01));
  CHECK_EQ(MyComplex(0, -2).abs(), 2);
}