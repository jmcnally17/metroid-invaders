#include <vector>
#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockInvader.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateLaserInvaderCollision, killsInvaderThatIsAliveAndLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(invader, die())
      .Times(1);
  EXPECT_CALL(laser, reset())
      .Times(1);
  EXPECT_CALL(laser, playInvaderDeath())
      .Times(1);
  evaluateLaserInvaderCollision(collision, laser, invaders, score, scoreText);
}

TEST(evaluateLaserInvaderCollision, addsTheInvaderPointsToTheScore)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> laser;
  NiceMock<MockInvader> invader;
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
  int score = 0;
  MockText scoreText;

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));
  ON_CALL(invader, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(scoreText, setString("Score: 30"))
      .Times(1);
  evaluateLaserInvaderCollision(collision, laser, invaders, score, scoreText);
  EXPECT_EQ(score, 30);
}

TEST(evaluateLaserInvaderCollision, doesNotKillInvadersThatAreAliveAndLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  NiceMock<MockInvader> invader;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(invader, die())
      .Times(0);
  EXPECT_CALL(laser, reset())
      .Times(0);
  EXPECT_CALL(laser, playInvaderDeath())
      .Times(0);
  evaluateLaserInvaderCollision(collision, laser, invaders, score, scoreText);
}

TEST(evaluateLaserInvaderCollision, doesNotKillInvadersThatAreDeadAndLaserIsCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  NiceMock<MockInvader> invader;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(invader, die())
      .Times(0);
  EXPECT_CALL(laser, reset())
      .Times(0);
  EXPECT_CALL(laser, playInvaderDeath())
      .Times(0);
  evaluateLaserInvaderCollision(collision, laser, invaders, score, scoreText);
}

TEST(evaluateLaserInvaderCollision, doesNotKillInvadersThatAreDeadAndLaserIsNotCollidingWith)
{
  NiceMock<MockCollision> collision;
  MockLaser laser;
  NiceMock<MockInvader> invader;
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
  int score = 0;
  NiceMock<MockText> scoreText;

  ON_CALL(invader, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(invader, die())
      .Times(0);
  EXPECT_CALL(laser, reset())
      .Times(0);
  EXPECT_CALL(laser, playInvaderDeath())
      .Times(0);
  evaluateLaserInvaderCollision(collision, laser, invaders, score, scoreText);
}
