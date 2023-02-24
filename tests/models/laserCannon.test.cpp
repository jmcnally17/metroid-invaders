#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(LaserCannon, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getWidth(), 78);
}

TEST(LaserCannon, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getHeight(), 48);
}

TEST(LaserCannon, hasALivesClassMemberInitiallySetTo3)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getLives(), 3);
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon cannon(pSprite, laser, sound);
}

TEST(LaserCannon, setPositionChangesPositionClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(205, 920));
}

TEST(LaserCannon, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  cannon.setPosition(sf::Vector2f(205, 920));
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  cannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.move(75);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  cannon.move(75);
}

TEST(LaserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);
  cannon.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(-50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(-10, 1224));
}

TEST(LaserCannon, moveDoesNotMovePositionRightIfPositionIsOffScreenRight)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);
  cannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(1550, 1224));
}

TEST(LaserCannon, fireChecksPositionOfLaserClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound *sound = new NiceMock<MockSound>();
  LaserCannon cannon(sprite, pLaser, sound);

  EXPECT_CALL(laser, getPosition())
      .Times(1);
  EXPECT_CALL(laser, getHeight())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireSetsPositionDownOnLaserClassMemberWhenAboveBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound *sound = new NiceMock<MockSound>();
  LaserCannon cannon(sprite, pLaser, sound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(laser, getHeight)
      .WillByDefault(Return(24));
  float laserXTarget = cannon.getPosition().x + (cannon.getWidth() - laser.getWidth()) / 2;

  EXPECT_CALL(laser, setPosition(sf::Vector2f(laserXTarget, 1224)))
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireCallsPlayOnSoundClassMemberWhenAboveBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound sound;
  MockSound *pSound = &sound;
  LaserCannon cannon(sprite, pLaser, pSound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(laser, getHeight)
      .WillByDefault(Return(24));

  EXPECT_CALL(sound, play())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireDoesNotSetPositionDownOnLaserClassMemberWhenOnBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound *sound;
  LaserCannon cannon(sprite, pLaser, sound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));
  ON_CALL(laser, getHeight)
      .WillByDefault(Return(24));

  EXPECT_CALL(laser, setPosition)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, fireDoesNotCallPlayOnSoundClassMemberWhenOnBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound sound;
  MockSound *pSound = &sound;
  LaserCannon cannon(sprite, pLaser, pSound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(sound, play)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, resetPositionSetsPositionBackToStartingPoint)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.resetPosition();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetPositionSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.resetPosition();
}

TEST(LaserCannon, resetSetsPositionBackToStartingPoint)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.reset();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(pSprite, laser, sound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.reset();
}

TEST(LaserCannon, loseLifeDecreasesLivesBy1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MockLaser *laser;
  MockSound *sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.loseLife();
  EXPECT_EQ(cannon.getLives(), 2);
}
