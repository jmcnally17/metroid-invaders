#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(LaserCannon, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_EQ(cannon.getWidth(), 78);
}

TEST(LaserCannon, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_EQ(cannon.getHeight(), 48);
}

TEST(LaserCannon, hasALivesClassMemberInitiallySetTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_EQ(cannon.getLives(), 3);
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);
}

TEST(LaserCannon, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(205, 920));
}

TEST(LaserCannon, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  cannon.setPosition(sf::Vector2f(205, 920));
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  cannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.move(75);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  cannon.move(75);
}

TEST(LaserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);
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
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);
  cannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(1550, 1224));
}

TEST(LaserCannon, fireChecksPositionOfLaserClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pLaser, pFireSound, deathSound);

  EXPECT_CALL(laser, getPosition())
      .Times(1);
  EXPECT_CALL(laser, getHeight())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireSetsPositionDownOnLaserClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pLaser, pFireSound, deathSound);

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
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pLaser, pFireSound, deathSound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(laser, getHeight)
      .WillByDefault(Return(24));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireDoesNotSetPositionDownOnLaserClassMemberWhenOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pLaser, fireSound, deathSound);

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
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> laser;
  MockLaser *pLaser = &laser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pLaser, pFireSound, deathSound);

  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, resetPositionSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.resetPosition();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetPositionSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.resetPosition();
}

TEST(LaserCannon, resetSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.reset();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.reset();
}

TEST(LaserCannon, resetSetsLivesBackTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, pDeathSound);

  cannon.loseLife();

  cannon.reset();
  EXPECT_EQ(cannon.getLives(), 3);
}

TEST(LaserCannon, loseLifeDecreasesLivesBy1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, pDeathSound);

  cannon.loseLife();
  EXPECT_EQ(cannon.getLives(), 2);
}

TEST(LaserCannon, loseLifePlaysDeathSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *laser;
  MockSound *fireSound;
  MockSound deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, laser, fireSound, pDeathSound);

  EXPECT_CALL(deathSound, play())
      .Times(1);
  cannon.loseLife();
}
