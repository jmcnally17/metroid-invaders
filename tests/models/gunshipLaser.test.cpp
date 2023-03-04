#include "../../include/models/gunshipLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(GunshipLaser, hasAPositionUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(GunshipLaser, hasAWidthClassMemberOf6)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_EQ(gunshipLaser.getWidth(), 6);
}

TEST(GunshipLaser, hasAHeightClassMemberOf24)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_EQ(gunshipLaser.getHeight(), 24);
}

TEST(GunshipLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  GunshipLaser gunshipLaser(pSprite, sound);
}

TEST(GunshipLaser, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  gunshipLaser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(530, 890));
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
  gunshipLaser.setPosition(sf::Vector2f(600, 700));

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

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(0);
  gunshipLaser.draw(window);
}

TEST(GunshipLaser, moveDecreasesYPositionWhenGunshipLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);
  gunshipLaser.setPosition(sf::Vector2f(500, 1000));

  gunshipLaser.move();
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(500, 999.5));
}

TEST(GunshipLaser, moveUpdatesSpritePositionWhenGunshipLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);
  gunshipLaser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 999.5)))
      .Times(1);
  gunshipLaser.move();
}

TEST(GunshipLaser, moveDoesNotDecreaseYPositionWhenGunshipLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  gunshipLaser.move();
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(GunshipLaser, moveDoesNotUpdateSpritePositionWhenGunshipLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  gunshipLaser.move();
}

TEST(GunshipLaser, resetSetsPositionBackAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  GunshipLaser gunshipLaser(pSprite, sound);
  gunshipLaser.setPosition(sf::Vector2f(400, 900));

  gunshipLaser.reset();
  EXPECT_EQ(gunshipLaser.getPosition(), sf::Vector2f(120, -24));
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
