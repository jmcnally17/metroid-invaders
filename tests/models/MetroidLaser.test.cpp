#include "../../include/models/MetroidLaser.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MetroidLaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MetroidLaser metroidLaser {MetroidLaser(pSprite)};
  MockRenderWindow window;
};

TEST_F(MetroidLaserTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  MetroidLaser metroidLaser(pSprite);
}

TEST_F(MetroidLaserTest, drawCallsDrawOnWindowArgumentWhenMetroidLaserIsOnBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 700)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  metroidLaser.draw(window);
}

TEST_F(MetroidLaserTest, drawDoesNotCallDrawOnWindowArgumentWhenMetroidLaserIsBelowBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(window, draw)
      .Times(0);
  metroidLaser.draw(window);
}

TEST_F(MetroidLaserTest, moveCallsMoveOnSpriteWhenMetroidLaserIsOnTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 6.4)))
      .Times(1);
  metroidLaser.move();
}

TEST_F(MetroidLaserTest, moveDoesNothingWhenMetroidLaserIsBelowTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  metroidLaser.move();
}
