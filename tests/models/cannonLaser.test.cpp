#include "../../include/models/cannonLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(CannonLaser, hasAPositionUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  EXPECT_EQ(cannonLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(CannonLaser, hasAWidthClassMemberOf6)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  EXPECT_EQ(cannonLaser.getWidth(), 6);
}

TEST(CannonLaser, hasAHeightClassMemberOf24)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  EXPECT_EQ(cannonLaser.getHeight(), 24);
}

TEST(CannonLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  CannonLaser cannonLaser(pSprite, sound);
}

TEST(CannonLaser, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  cannonLaser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(cannonLaser.getPosition(), sf::Vector2f(530, 890));
}

TEST(CannonLaser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  cannonLaser.setPosition(sf::Vector2f(530, 890));
}

TEST(CannonLaser, drawCallsDrawOnWindowArgumentWhenCannonLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);
  MockRenderWindow window;
  cannonLaser.setPosition(sf::Vector2f(600, 700));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  cannonLaser.draw(window);
}

TEST(CannonLaser, drawDoesNotCallDrawOnWindowArgumentWhenCannonLaserIsAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(0);
  cannonLaser.draw(window);
}

TEST(CannonLaser, moveDecreasesYPositionWhenCannonLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);
  cannonLaser.setPosition(sf::Vector2f(500, 1000));

  cannonLaser.move();
  EXPECT_EQ(cannonLaser.getPosition(), sf::Vector2f(500, 999.5));
}

TEST(CannonLaser, moveUpdatesSpritePositionWhenCannonLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);
  cannonLaser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 999.5)))
      .Times(1);
  cannonLaser.move();
}

TEST(CannonLaser, moveDoesNotDecreaseYPositionWhenCannonLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  cannonLaser.move();
  EXPECT_EQ(cannonLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(CannonLaser, moveDoesNotUpdateSpritePositionWhenCannonLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannonLaser.move();
}

TEST(CannonLaser, resetSetsPositionBackAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound *sound;
  CannonLaser cannonLaser(pSprite, sound);
  cannonLaser.setPosition(sf::Vector2f(400, 900));

  cannonLaser.reset();
  EXPECT_EQ(cannonLaser.getPosition(), sf::Vector2f(120, -24));
}

TEST(CannonLaser, playMetroidDeathCallsPlayOnTheSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  MockSound *pSound = &sound;
  CannonLaser cannonLaser(pSprite, pSound);

  EXPECT_CALL(sound, play())
      .Times(1);
  cannonLaser.playMetroidDeath();
}
