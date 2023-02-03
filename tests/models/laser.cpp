#include <gtest/gtest.h>
#include "../../include/models/laser.hpp"

TEST(Laser, hasAPositionUponInstantiation)
{
  Laser laser;

  EXPECT_EQ(laser.getPosition().x, 120);
  EXPECT_EQ(laser.getPosition().y, -24);
}
