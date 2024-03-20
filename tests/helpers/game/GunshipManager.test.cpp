#include "../../../include/helpers/game/GunshipManager.hpp"
#include "../../mockModels/MockGunship.hpp"
#include "../../mockModels/MockGunshipLaser.hpp"

class GunshipManagerTest : public testing::Test
{
protected:
  GunshipManager gunshipManager;
  MockGunship gunship;
  MockGunshipLaser gunshipLaser;
};

TEST_F(GunshipManagerTest, moveGunshipCallsMoveOnTheGunship)
{
  EXPECT_CALL(gunship, move(1))
      .Times(1);
  gunshipManager.moveGunship(gunship, 1);
}

TEST_F(GunshipManagerTest, moveGunshipLaserCallsMoveOnGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, move())
      .Times(1);
  gunshipManager.moveGunshipLaser(gunshipLaser);
}

TEST_F(GunshipManagerTest, fireGunshipLaserCallsFireOnGunship)
{
  EXPECT_CALL(gunship, fire())
      .Times(1);
  gunshipManager.fireGunshipLaser(gunship);
}
