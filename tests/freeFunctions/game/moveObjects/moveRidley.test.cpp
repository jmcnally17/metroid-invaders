#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockRidley.hpp"

TEST(moveRidley, callsMoveOnRidley)
{
  MockRidley ridley;

  EXPECT_CALL(ridley, move())
      .Times(1);
  moveRidley(ridley);
}
