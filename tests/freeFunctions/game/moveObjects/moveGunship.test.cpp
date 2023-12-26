#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockGunship.hpp"

TEST(moveGunship, callsMoveOnTheGunship)
{
  MockGunship gunship;

  EXPECT_CALL(gunship, move(1))
      .Times(1);
  moveGunship(gunship, 1);
}
