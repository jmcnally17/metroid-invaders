#include "../../../include/game.hpp"
#include "../../mockModels/mockSprite.hpp"
#include "../../mockModels/mockRenderWindow.hpp"
#include "../../mockModels/mockBunker.hpp"
#include "../../mockModels/mockGunship.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(drawObjects, callsClearOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, callsDrawOnTheBunkers)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  MockBunker bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(bunker, draw)
      .Times(4);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, callsDrawOnTheGunship)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  MockGunship gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(gunship, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, callsDrawOnTheGunshipLaser)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  MockLaser gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(gunshipLaser, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, callsDrawOnAllTheMetroidsIfTheyAreAlive)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
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
  MockText highScoreText;
  MockText livesText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, draw)
      .Times(55);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, doesNotCallDrawOnAllTheMetroidsIfTheyAreDead)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
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
  MockText highScoreText;
  MockText livesText;

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, draw)
      .Times(0);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, drawsTheMetroidLasers)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
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
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(metroidLaser, draw)
      .Times(3);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, drawsRidley)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  MockRidley ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(ridley, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, drawsTheBackgroundAndScoreAndHighScoreAndLivesText)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(4);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}

TEST(drawObjects, callsDisplayOnTheWindow)
{
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  std::vector<IBunker *> bunkers;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;

  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
}
