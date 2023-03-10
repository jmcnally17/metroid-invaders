#include "../../../../include/game.hpp"
#include "../../../mockModels/mockGunship.hpp"

TEST(fireGunshipLaser, callsFireOnGunship)
{
  MockGunship gunship;

  EXPECT_CALL(gunship, fire())
      .Times(1);
  fireGunshipLaser(gunship);
}
