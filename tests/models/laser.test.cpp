#include <gtest/gtest.h>
#include "../../include/models/laser.hpp"

TEST(Laser, hasAPositionUponInstantiation)
{
  Laser laser;

  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, setPositionChangesLaserPosition)
{
  Laser laser;

  laser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(530, 890));
}
