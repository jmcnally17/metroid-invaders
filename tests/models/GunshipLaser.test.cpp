#include "../../include/models/GunshipLaser.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GunshipLaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  GunshipLaser gunshipLaser {GunshipLaser(pSprite)};
  MockRenderWindow window;
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(800, 900), sf::Vector2f(6, 24))};
};

TEST_F(GunshipLaserTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  GunshipLaser gunshipLaser(pSprite);
}

TEST_F(GunshipLaserTest, drawCallsDrawOnWindowArgumentWhenGunshipLaserIsOnBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 700)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gunshipLaser.draw(window);
}

TEST_F(GunshipLaserTest, drawDoesNotCallDrawOnWindowArgumentWhenGunshipLaserIsAboveBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(window, draw)
      .Times(0);
  gunshipLaser.draw(window);
}

TEST_F(GunshipLaserTest, moveCallsMoveOnSpriteWhenGunshipLaserIsOnTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, -6.4)))
      .Times(1);
  gunshipLaser.move();
}

TEST_F(GunshipLaserTest, moveDoesNothingWhenGunshipLaserIsAboveTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunshipLaser.move();
}
