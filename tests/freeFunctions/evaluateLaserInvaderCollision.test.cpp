#include <vector>
#include "../../include/spaceInvaders.hpp"
#include "../mockInterfaces/mockCollision.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockInvader.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserInvaderCollision, killsInvadersThatLaserHasCollidedWith)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  MockInvader invader;
  MockInvader *pInvader = &invader;
  std::vector<std::vector<IInvader *>> invaders(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IInvader *> invaderRow(10);
    for (int j = 0; j < 10; j++)
    {
      invaderRow[j] = pInvader;
    }
    invaders[i] = invaderRow;
  }

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(invader, die())
      .Times(20);
  evaluateLaserInvaderCollision(collision, laser, invaders);
}
