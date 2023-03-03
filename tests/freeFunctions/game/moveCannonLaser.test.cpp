#include "../../../include/game.hpp"
#include "../../mockModels/mockLaser.hpp"

TEST(moveCannonLaser, callsMoveOnCannonLaser)
{
  MockLaser cannonLaser;

  EXPECT_CALL(cannonLaser, move())
      .Times(1);
  moveCannonLaser(cannonLaser);
}
