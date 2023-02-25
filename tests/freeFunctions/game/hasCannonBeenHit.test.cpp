#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(hasCannonBeenHit, returnsTrueWhenAnyLaserCollidesWithCannon)
{
  NiceMock<MockCollision> collisionInterface;
  MockLaserCannon cannon;
  MockLaser *metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = metroidLaser;
  }

  ON_CALL(collisionInterface, haveCollided)
      .WillByDefault(Return(true));
  EXPECT_TRUE(hasCannonBeenHit(collisionInterface, cannon, metroidLasers));
}

TEST(hasCannonBeenHit, returnsFalseWhenAnyLaserCollidesWithCannon)
{
  NiceMock<MockCollision> collisionInterface;
  MockLaserCannon cannon;
  MockLaser *metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = metroidLaser;
  }

  ON_CALL(collisionInterface, haveCollided)
      .WillByDefault(Return(false));
  EXPECT_FALSE(hasCannonBeenHit(collisionInterface, cannon, metroidLasers));
}
