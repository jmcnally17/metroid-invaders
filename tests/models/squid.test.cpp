#include <gtest/gtest.h>
#include "../../include/models/squid.hpp"

TEST(Squid, hasAWidthClassMemberOf48)
{
  Squid squid;

  EXPECT_EQ(squid.getWidth(), 48);
}

TEST(Squid, hasAHeightClassMemberOf48)
{
  Squid squid;

  EXPECT_EQ(squid.getHeight(), 48);
}

TEST(Squid, hasAPointsClassMemberOf30)
{
  Squid squid;

  EXPECT_EQ(squid.getPoints(), 30);
}
