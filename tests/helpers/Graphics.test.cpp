#include "../../include/helpers/Graphics.hpp"
#include "../mockModels/MockBunker.hpp"
#include "../mockModels/MockGunship.hpp"
#include "../mockModels/MockGunshipLaser.hpp"
#include "../mockModels/MockMetroid.hpp"
#include "../mockModels/MockMetroidLaser.hpp"
#include "../mockModels/MockRenderWindow.hpp"
#include "../mockModels/MockRidley.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GraphicsTest : public testing::Test
{
protected:
  Graphics graphics;
  NiceMock<MockRenderWindow> window;
  MockSprite background;
  MockSprite *pBackground {&background};
  std::unordered_map<std::string, ISprite*> backgrounds {
    {"title", pBackground},
    {"game", pBackground},
  };
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
  MockText text;
  MockText *pText {&text};
  std::unordered_map<std::string, IText*> textObjects {
    {"title", pText},
    {"instructions", pText},
    {"score", pText},
    {"highScore", pText},
    {"lives", pText},
    {"gameOver", pText},
    {"playAgain", pText},
  };
  sf::RectangleShape rectangle;
  std::array<sf::RectangleShape, 2> rectangles {rectangle, rectangle};
};

TEST_F(GraphicsTest, displayTitleScreenClearsTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  graphics.displayTitleScreen(window, backgrounds, textObjects);
}

TEST_F(GraphicsTest, displayTitleScreenDrawsTheBackgroundImageAndTitleTextAndInstructionsText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  graphics.displayTitleScreen(window, backgrounds, textObjects);
}

TEST_F(GraphicsTest, displayTitleScreenDisplaysTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  graphics.displayTitleScreen(window, backgrounds, textObjects);
}

TEST_F(GraphicsTest, drawObjectsCallsClearOnTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsCallsDrawOnTheBunkers)
{
  EXPECT_CALL(bunker, draw)
      .Times(4);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsCallsDrawOnTheGunship)
{
  EXPECT_CALL(gunship, draw)
      .Times(1);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsCallsDrawOnTheGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, draw)
      .Times(1);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsCallsDrawOnAllTheMetroidsIfTheyAreAlive)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, draw)
      .Times(55);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsDoesNotCallDrawOnAllTheMetroidsIfTheyAreDead)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, draw)
      .Times(0);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsDrawsTheMetroidLasers)
{
  EXPECT_CALL(metroidLaser, draw)
      .Times(3);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsDrawsRidley)
{
  EXPECT_CALL(ridley, draw)
      .Times(1);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsDrawsTheBackgroundAndScoreAndHighScoreAndLivesTextAndRectangles)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(6);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, drawObjectsCallsDisplayOnTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
}

TEST_F(GraphicsTest, displayGameOverScreenCallsClearOnTheWindow)
{
  EXPECT_CALL(window, clear())
      .Times(1);
  graphics.displayGameOverScreen(window, textObjects);
}

TEST_F(GraphicsTest, displayGameOverScreenDrawsTheGameOverTextAndScoreTextAndPlayAgainText)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(3);
  graphics.displayGameOverScreen(window, textObjects);
}

TEST_F(GraphicsTest, displayGameOverScreenCallsDisplayOnTheWindow)
{
  EXPECT_CALL(window, display())
      .Times(1);
  graphics.displayGameOverScreen(window, textObjects);
}
