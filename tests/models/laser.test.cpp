#include "../../include/models/laser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Laser, hasAPositionUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)))
      .Times(1);
  Laser laser(pSprite, sound);
}

TEST(Laser, hasAWidthClassMemberOf6)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_EQ(laser.getWidth(), 6);
}

TEST(Laser, hasAHeightClassMemberOf24)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_EQ(laser.getHeight(), 24);
}

TEST(Laser, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  laser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(530, 890));
}

TEST(Laser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  laser.setPosition(sf::Vector2f(530, 890));
}

TEST(Laser, drawCallsDrawOnWindowArgumentWhenLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);
  MockRenderWindow window;
  laser.setPosition(sf::Vector2f(600, 700));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  laser.draw(window);
}

TEST(Laser, drawDoesNotCallDrawOnWindowArgumentWhenLaserIsAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(0);
  laser.draw(window);
}

TEST(Laser, moveDecreasesYPositionWhenLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);
  laser.setPosition(sf::Vector2f(500, 1000));

  laser.move();
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(500, 999.5));
}

TEST(Laser, moveUpdatesSpritePositionWhenLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);
  laser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 999.5)))
      .Times(1);
  laser.move();
}

TEST(Laser, moveDoesNotDecreaseYPositionWhenLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  laser.move();
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, moveDoesNotUpdateSpritePositionWhenLaserIsAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laser.move();
}

TEST(Laser, resetSetsPositionBackAboveTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);
  laser.setPosition(sf::Vector2f(400, 900));

  laser.reset();
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, playInvaderDeathCallsPlayOnTheSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockSound sound;
  Laser laser(pSprite, sound);

  EXPECT_CALL(sound, play())
      .Times(1);
  laser.playInvaderDeath();
}
