#include <gtest/gtest.h>
#include "../../include/models/laserCannon.hpp"

TEST(LaserCannon, hasAPositionUponInstantiation)
{
  LaserCannon laserCannon;

  EXPECT_EQ(laserCannon.getPosition().x, 1416);
  EXPECT_EQ(laserCannon.getPosition().y, 1224);
}
