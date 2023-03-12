#include "../../include/models/gunship.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Gunship, hasALivesClassMemberInitiallySetTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_EQ(gunship.getLives(), 3);
}

TEST(Gunship, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);
}

TEST(Gunship, getPositionReturnsSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1224)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(120, 1224));
}

TEST(Gunship, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  gunship.setPosition(sf::Vector2f(205, 920));
}

TEST(Gunship, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gunship.draw(window);
}

TEST(Gunship, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 1224)));

  EXPECT_CALL(sprite, move(sf::Vector2f(75, 0)))
      .Times(1);
  gunship.move(75);
}

TEST(Gunship, moveDoesNotMoveSpritePositionLeftIfPositionIsAtLeftSideOfWindow)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-10, 1224)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(-50);
}

TEST(Gunship, moveDoesNotMoveSpritePositionRightIfPositionIsAtRightSideOfWindow)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1550, 1224)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(50);
}

TEST(Gunship, fireChecksPositionOfGunshipLaserClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser = &gunshipLaser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, deathSound);

  EXPECT_CALL(gunshipLaser, getPosition())
      .Times(1);
  gunship.fire();
}

TEST(Gunship, fireSetsPositionDownOnGunshipLaserClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser = &gunshipLaser;
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, deathSound);

  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(700, 1224)));
  float gunshipLaserXTarget = gunship.getPosition().x + (78 - 6) / 2;

  EXPECT_CALL(gunshipLaser, setPosition(sf::Vector2f(gunshipLaserXTarget, 1224)))
      .Times(1);
  gunship.fire();
}

TEST(Gunship, fireCallsPlayOnSoundClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser = &gunshipLaser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, deathSound);

  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  gunship.fire();
}

TEST(Gunship, fireDoesNotSetPositionDownOnGunshipLaserClassMemberWhenOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser = &gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, pGunshipLaser, fireSound, deathSound);

  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(gunshipLaser, setPosition)
      .Times(0);
  gunship.fire();
}

TEST(Gunship, fireDoesNotCallPlayOnSoundClassMemberWhenOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser = &gunshipLaser;
  MockSound fireSound;
  MockSound *pFireSound = &fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, deathSound);

  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  gunship.fire();
}

TEST(Gunship, resetPositionSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  gunship.resetPosition();
}

TEST(Gunship, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  gunship.reset();
}

TEST(Gunship, resetSetsLivesBackTo3)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, pDeathSound);

  gunship.loseLife();

  gunship.reset();
  EXPECT_EQ(gunship.getLives(), 3);
}

TEST(Gunship, loseLifeDecreasesLivesBy1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, pDeathSound);

  gunship.loseLife();
  EXPECT_EQ(gunship.getLives(), 2);
}

TEST(Gunship, loseLifePlaysDeathSoundClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound deathSound;
  MockSound *pDeathSound = &deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, pDeathSound);

  EXPECT_CALL(deathSound, play())
      .Times(1);
  gunship.loseLife();
}

TEST(Gunship, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  sf::FloatRect spriteBounds(sf::Vector2f(120, 1224), sf::Vector2f(78, 45));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(gunship.getGlobalBounds(), spriteBounds);
}

TEST(Gunship, intersectsGetsTheSpriteGlobalBounds)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  gunship.intersects(rectangle);
}

TEST(Gunship, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  sf::FloatRect spriteBounds(sf::Vector2f(120, 1224), sf::Vector2f(78, 45));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(130, 1210), sf::Vector2f(18, 36));

  EXPECT_TRUE(gunship.intersects(rectangle));
}

TEST(Gunship, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  sf::FloatRect spriteBounds(sf::Vector2f(120, 1224), sf::Vector2f(78, 45));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(18, 36));

  EXPECT_FALSE(gunship.intersects(rectangle));
}
