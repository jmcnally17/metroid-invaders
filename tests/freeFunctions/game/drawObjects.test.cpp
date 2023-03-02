#include "../../../include/game.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockLaserCannon.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(drawObjects, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, callsDrawOnTheLaserCannon)
{
  NiceMock<MockRenderWindow> window;
  MockLaserCannon cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(cannon, draw)
      .Times(1);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, callsDrawOnTheLaser)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  MockLaser laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(laser, draw)
      .Times(1);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, callsDrawOnAllTheMetroidsIfTheyAreAlive)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IMetroid *> metroidRow(11);
    for (int j = 0; j < 11; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, draw)
      .Times(55);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, doesNotCallDrawOnAllTheMetroidsIfTheyAreDead)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(5);
  for (int i = 0; i < 5; i++)
  {
    std::vector<IMetroid *> metroidRow(11);
    for (int j = 0; j < 11; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, draw)
      .Times(0);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, drawsTheMetroidLasers)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(metroidLaser, draw)
      .Times(3);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, drawsRidley)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  MockRidley ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(ridley, draw)
      .Times(1);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, drawsTheScoreAndLivesText)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(2);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  NiceMock<MockLaserCannon> cannon;
  NiceMock<MockLaser> laser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText livesText;

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, cannon, laser, metroids, metroidLasers, ridley, scoreText, livesText);
}
