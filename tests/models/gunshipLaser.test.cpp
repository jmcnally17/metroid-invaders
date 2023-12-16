#include "../../include/models/gunshipLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GunshipLaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  NiceMock<MockSound> sound;
  MockSound *pSound {&sound};
  GunshipLaser gunshipLaser {GunshipLaser(pSprite, pSound)};
  MockRenderWindow window;
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(800, 900), sf::Vector2f(6, 24))};
};

TEST_F(GunshipLaserTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  GunshipLaser gunshipLaser(pSprite, pSound);
}

TEST_F(GunshipLaserTest, getPositionReturnsSpritePosition)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST_F(GunshipLaserTest, setPositionChangesSpritePosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  gunshipLaser.setPosition(sf::Vector2f(530, 890));
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

TEST_F(GunshipLaserTest, moveDecreasesSpriteYPositionWhenGunshipLaserIsOnTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, -6.4)))
      .Times(1);
  gunshipLaser.move();
}

TEST_F(GunshipLaserTest, moveDoesNotDecreaseSpriteYPositionWhenGunshipLaserIsAboveTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunshipLaser.move();
}

TEST_F(GunshipLaserTest, resetSetsSpritePositionBackAboveTheBoard)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  gunshipLaser.reset();
}

TEST_F(GunshipLaserTest, playMetroidDeathCallsPlayOnTheSoundClassMember)
{
  EXPECT_CALL(sound, play())
      .Times(1);
  gunshipLaser.playMetroidDeath();
}

TEST_F(GunshipLaserTest, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(gunshipLaser.getGlobalBounds(), spriteBounds);
}

TEST_F(GunshipLaserTest, intersectsGetsTheSpriteGlobalBounds)
{
  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  gunshipLaser.intersects(rectangle);
}

TEST_F(GunshipLaserTest, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(770, 880), sf::Vector2f(72, 48));

  EXPECT_TRUE(gunshipLaser.intersects(rectangle));
}

TEST_F(GunshipLaserTest, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(72, 48));

  EXPECT_FALSE(gunshipLaser.intersects(rectangle));
}
