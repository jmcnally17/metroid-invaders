#include <gtest/gtest.h>
#include "../../include/models/squid.hpp"

TEST(Squid, hasAWidthClassMemberOf48)
{
  Squid squid(200, 320);

  EXPECT_EQ(squid.getWidth(), 48);
}

TEST(Squid, hasAHeightClassMemberOf48)
{
  Squid squid(200, 320);

  EXPECT_EQ(squid.getHeight(), 48);
}

TEST(Squid, hasAPointsClassMemberOf30)
{
  Squid squid(200, 320);

  EXPECT_EQ(squid.getPoints(), 30);
}

TEST(Squid, setsOwnPositionMember)
{
  Squid squid(200, 320);

  EXPECT_EQ(squid.getPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, setPositionChangesPosition)
{
  Squid squid(200, 320);

  squid.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(500, 920));
}
