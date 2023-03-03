#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserRidleyCollision, killsRidleyIfCollidingWithLaser)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> laser;
  NiceMock<MockRidley> ridley;
  int score = 430;
  NiceMock<MockText> scoreText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(ridley, die())
      .Times(1);
  evaluateLaserRidleyCollision(collision, laser, ridley, score, scoreText);
}

TEST(evaluateLaserRidleyCollision, addsTheRidleyPointsToTheScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> laser;
  NiceMock<MockRidley> ridley;
  int score = 430;
  NiceMock<MockText> scoreText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  evaluateLaserRidleyCollision(collision, laser, ridley, score, scoreText);
  EXPECT_EQ(score, 580);
}

TEST(evaluateLaserRidleyCollision, updatesTheScoreText)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> laser;
  NiceMock<MockRidley> ridley;
  int score = 430;
  MockText scoreText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(scoreText, setString("Score: 580"))
      .Times(1);
  evaluateLaserRidleyCollision(collision, laser, ridley, score, scoreText);
}

TEST(evaluateLaserRidleyCollision, resetsTheLaser)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  NiceMock<MockRidley> ridley;
  int score = 430;
  NiceMock<MockText> scoreText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(laser, reset())
      .Times(1);
  evaluateLaserRidleyCollision(collision, laser, ridley, score, scoreText);
}

TEST(evaluateLaserRidleyCollision, doesNotModifyAnythingIfRidleyAndLaserAreNotColliding)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  MockRidley ridley;
  int score = 430;
  MockText scoreText;

  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(ridley, die())
      .Times(0);
  EXPECT_CALL(scoreText, setString)
      .Times(0);
  EXPECT_CALL(laser, reset())
      .Times(0);
  evaluateLaserRidleyCollision(collision, laser, ridley, score, scoreText);
  EXPECT_EQ(score, 430);
}
