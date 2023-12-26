#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockGunship.hpp"

TEST(fireGunshipLaser, callsFireOnGunship)
{
  MockGunship gunship;

  EXPECT_CALL(gunship, fire())
      .Times(1);
  fireGunshipLaser(gunship);
}
