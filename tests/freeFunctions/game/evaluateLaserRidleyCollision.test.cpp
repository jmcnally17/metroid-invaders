#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserRidleyCollision, killsRidleyIfCollidingWithLaser)
{
  MockRidley ridley;
  int score = 430;

  EXPECT_CALL(ridley, die())
      .Times(1);
  evaluateLaserRidleyCollision(ridley, score);
}

TEST(evaluateLaserRidleyCollision, addsTheRidleyPointsToTheScore)
{
  NiceMock<MockRidley> ridley;
  int score = 430;

  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  evaluateLaserRidleyCollision(ridley, score);
  EXPECT_EQ(score, 580);
}
