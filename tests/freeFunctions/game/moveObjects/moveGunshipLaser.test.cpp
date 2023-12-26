#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockGunshipLaser.hpp"

TEST(moveGunshipLaser, callsMoveOnGunshipLaser)
{
  MockGunshipLaser gunshipLaser;

  EXPECT_CALL(gunshipLaser, move())
      .Times(1);
  moveGunshipLaser(gunshipLaser);
}
