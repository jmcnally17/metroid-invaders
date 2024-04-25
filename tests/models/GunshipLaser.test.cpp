#include "../../include/Constants.hpp"
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
};

TEST_F(GunshipLaserTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(7.5 * Constants::LENGTH_SCALE, -1.5 * Constants::LENGTH_SCALE)))
      .Times(1);
  GunshipLaser gunshipLaser(pSprite);
}

TEST_F(GunshipLaserTest, drawCallsDrawOnWindowArgumentWhenGunshipLaserIsOnBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(37.5 * Constants::LENGTH_SCALE, 43.75 * Constants::LENGTH_SCALE)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gunshipLaser.draw(window);
}

TEST_F(GunshipLaserTest, drawDoesNotCallDrawOnWindowArgumentWhenGunshipLaserIsAboveBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(7.5 * Constants::LENGTH_SCALE, -1.5 * Constants::LENGTH_SCALE)));

  EXPECT_CALL(window, draw)
      .Times(0);
  gunshipLaser.draw(window);
}

TEST_F(GunshipLaserTest, moveCallsMoveOnSpriteWhenGunshipLaserIsOnTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(31.25 * Constants::LENGTH_SCALE, 62.5 * Constants::LENGTH_SCALE)));

  float speed {0.4 * Constants::LENGTH_SCALE * Constants::FRAME_LENGTH / 6250};
  EXPECT_CALL(sprite, move(sf::Vector2f(0, -speed)))
      .Times(1);
  gunshipLaser.move();
}

TEST_F(GunshipLaserTest, moveDoesNothingWhenGunshipLaserIsAboveTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(7.5 * Constants::LENGTH_SCALE, -1.5 * Constants::LENGTH_SCALE)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunshipLaser.move();
}
