#include "../../../../include/game.hpp"
#include "../../../mockModels/mockLaser.hpp"

TEST(moveGunshipLaser, callsMoveOnGunshipLaser)
{
  MockLaser gunshipLaser;

  EXPECT_CALL(gunshipLaser, move())
      .Times(1);
  moveGunshipLaser(gunshipLaser);
}
