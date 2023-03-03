#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserRidleyCollision, killsRidleyIfCollidingWithLaser)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, die())
      .Times(1);
  evaluateLaserRidleyCollision(ridley);
}
