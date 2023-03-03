#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"

TEST(moveRidley, callsMoveOnRidley)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, move())
      .Times(1);
  moveRidley(ridley);
}
