#include "../../../include/game.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserRidleyCollision, killsRidleyIfCollidingWithLaser)
{
  NiceMock<MockRidley> ridley;
  int score = 430;
  NiceMock<MockText> scoreText;

  EXPECT_CALL(ridley, die())
      .Times(1);
  evaluateLaserRidleyCollision(ridley, score, scoreText);
}

TEST(evaluateLaserRidleyCollision, addsTheRidleyPointsToTheScore)
{
  NiceMock<MockRidley> ridley;
  int score = 430;
  NiceMock<MockText> scoreText;

  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  evaluateLaserRidleyCollision(ridley, score, scoreText);
  EXPECT_EQ(score, 580);
}

TEST(evaluateLaserRidleyCollision, updatesTheScoreText)
{
  NiceMock<MockRidley> ridley;
  int score = 430;
  MockText scoreText;

  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(scoreText, setString("Score: 580"));
  evaluateLaserRidleyCollision(ridley, score, scoreText);
}
