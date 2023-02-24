#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"

using ::testing::Return;

TEST(hasCannonBeenHit, returnsTrueWhenAnyLaserCollidesWithCannon)
{
  MockCollision collisionInterface;
  MockLaserCannon cannon;
  MockLaser *invaderLaser;
  std::vector<ILaser *> invaderLasers(3);
  for (int i = 0; i < 3; i++)
  {
    invaderLasers[i] = invaderLaser;
  }

  ON_CALL(collisionInterface, haveCollided)
      .WillByDefault(Return(true));
  EXPECT_TRUE(hasCannonBeenHit(collisionInterface, cannon, invaderLasers));
}
