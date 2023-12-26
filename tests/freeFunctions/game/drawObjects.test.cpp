#include "../../../include/Game.hpp"
#include "../../mockModels/MockSprite.hpp"
#include "../../mockModels/MockRenderWindow.hpp"
#include "../../mockModels/MockBunker.hpp"
#include "../../mockModels/MockGunship.hpp"
#include "../../mockModels/MockGunshipLaser.hpp"
#include "../../mockModels/MockMetroidLaser.hpp"
#include "../../mockModels/MockMetroid.hpp"
#include "../../mockModels/MockRidley.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class DrawObjectsTest : public testing::Test
{
protected:
  NiceMock<MockRenderWindow> window;
  MockSprite gameBackground;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
  NiceMock<MockGunship> gunship;
  NiceMock<MockGunshipLaser> gunshipLaser;
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  NiceMock<MockMetroidLaser> metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockRidley> ridley;
  MockText scoreText;
  MockText highScoreText;
  MockText livesText;
  sf::RectangleShape rectangle;
  std::array<sf::RectangleShape, 2> rectangles {rectangle, rectangle};
};

TEST_F(DrawObjectsTest, callsClearOnTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, callsDrawOnTheBunkers)
{
  EXPECT_CALL(bunker, draw)
      .Times(4);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, callsDrawOnTheGunship)
{
  EXPECT_CALL(gunship, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, callsDrawOnTheGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, callsDrawOnAllTheMetroidsIfTheyAreAlive)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, draw)
      .Times(55);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, doesNotCallDrawOnAllTheMetroidsIfTheyAreDead)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, draw)
      .Times(0);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, drawsTheMetroidLasers)
{
  EXPECT_CALL(metroidLaser, draw)
      .Times(3);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, drawsRidley)
{
  EXPECT_CALL(ridley, draw)
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, drawsTheBackgroundAndScoreAndHighScoreAndLivesTextAndRectangles)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(6);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}

TEST_F(DrawObjectsTest, callsDisplayOnTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
}
