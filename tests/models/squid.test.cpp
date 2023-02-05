#include <gtest/gtest.h>
#include "../../include/models/squid.hpp"

TEST(Squid, hasAWidthClassMemberOf48)
{
  Squid squid;

  EXPECT_EQ(squid.getWidth(), 48);
}
