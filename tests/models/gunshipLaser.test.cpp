#include "../../include/models/gunshipLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(GunshipLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  GunshipLaser gunshipLaser(pSprite, sound);
}

TEST(GunshipLaser, getPositionReturnsSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(GunshipLaser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  gunshipLaser.setPosition(sf::Vector2f(530, 890));
}

TEST(GunshipLaser, drawCallsDrawOnWindowArgumentWhenGunshipLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);
  MockRenderWindow window;

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 700)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gunshipLaser.draw(window);
}

TEST(GunshipLaser, drawDoesNotCallDrawOnWindowArgumentWhenGunshipLaserIsAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);
  MockRenderWindow window;

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(window, draw)
      .Times(0);
  gunshipLaser.draw(window);
}

TEST(GunshipLaser, moveDecreasesSpriteYPositionWhenGunshipLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, -6.4)))
      .Times(1);
  gunshipLaser.move();
}

TEST(GunshipLaser, moveDoesNotDecreaseSpriteYPositionWhenGunshipLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, -24)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunshipLaser.move();
}

TEST(GunshipLaser, resetSetsSpritePositionBackAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  gunshipLaser.reset();
}

TEST(GunshipLaser, playMetroidDeathCallsPlayOnTheSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  MockSound *pSound = &sound;
  GunshipLaser gunshipLaser(pSprite, pSound);

  EXPECT_CALL(sound, play())
      .Times(1);
  gunshipLaser.playMetroidDeath();
}
