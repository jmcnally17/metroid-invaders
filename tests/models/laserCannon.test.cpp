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
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_EQ(cannon.getWidth(), 78);
}

TEST(LaserCannon, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_EQ(cannon.getHeight(), 48);
}

TEST(LaserCannon, hasALivesClassMemberInitiallySetTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_EQ(cannon.getLives(), 3);
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);
}

TEST(LaserCannon, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(205, 920));
}

TEST(LaserCannon, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  cannon.setPosition(sf::Vector2f(205, 920));
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);
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
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.move(75);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  cannon.move(75);
}

TEST(LaserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);
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
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);
  cannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(1550, 1224));
}

TEST(LaserCannon, fireChecksPositionOfCannonLaserClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> cannonLaser;
  MockLaser *pCannonLaser = &cannonLaser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pCannonLaser, pFireSound, deathSound);

  EXPECT_CALL(cannonLaser, getPosition())
      .Times(1);
  EXPECT_CALL(cannonLaser, getHeight())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireSetsPositionDownOnCannonLaserClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> cannonLaser;
  MockLaser *pCannonLaser = &cannonLaser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pCannonLaser, pFireSound, deathSound);

  ON_CALL(cannonLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(cannonLaser, getHeight)
      .WillByDefault(Return(24));
  float cannonLaserXTarget = cannon.getPosition().x + (cannon.getWidth() - cannonLaser.getWidth()) / 2;

  EXPECT_CALL(cannonLaser, setPosition(sf::Vector2f(cannonLaserXTarget, 1224)))
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireCallsPlayOnSoundClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> cannonLaser;
  MockLaser *pCannonLaser = &cannonLaser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pCannonLaser, pFireSound, deathSound);

  ON_CALL(cannonLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(cannonLaser, getHeight)
      .WillByDefault(Return(24));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireDoesNotSetPositionDownOnCannonLaserClassMemberWhenOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> cannonLaser;
  MockLaser *pCannonLaser = &cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pCannonLaser, fireSound, deathSound);

  ON_CALL(cannonLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));
  ON_CALL(cannonLaser, getHeight)
      .WillByDefault(Return(24));

  EXPECT_CALL(cannonLaser, setPosition)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, fireDoesNotCallPlayOnSoundClassMemberWhenOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> cannonLaser;
  MockLaser *pCannonLaser = &cannonLaser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, pCannonLaser, pFireSound, deathSound);

  ON_CALL(cannonLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, resetPositionSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.resetPosition();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetPositionSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.resetPosition();
}

TEST(LaserCannon, resetSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  cannon.reset();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, deathSound);

  cannon.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  cannon.reset();
}

TEST(LaserCannon, resetSetsLivesBackTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, pDeathSound);

  cannon.loseLife();

  cannon.reset();
  EXPECT_EQ(cannon.getLives(), 3);
}

TEST(LaserCannon, loseLifeDecreasesLivesBy1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, pDeathSound);

  cannon.loseLife();
  EXPECT_EQ(cannon.getLives(), 2);
}

TEST(LaserCannon, loseLifePlaysDeathSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *cannonLaser;
  MockSound *fireSound;
  MockSound deathSound;
  MockSound *pDeathSound = &deathSound;
  LaserCannon cannon(pSprite, cannonLaser, fireSound, pDeathSound);

  EXPECT_CALL(deathSound, play())
      .Times(1);
  cannon.loseLife();
}
