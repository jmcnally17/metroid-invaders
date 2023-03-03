#include "../../../include/game.hpp"
#include "../../mockModels/mockGunship.hpp"

TEST(moveGunship, callsMoveOnTheGunship)
{
  MockGunship gunship;

  EXPECT_CALL(gunship, move(150))
      .Times(1);
  moveGunship(gunship, 150);
}
