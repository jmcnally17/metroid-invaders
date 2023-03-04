#include "../../include/models/gunship.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Gunship, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(120, 1224));
}

TEST(Gunship, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_EQ(gunship.getWidth(), 78);
}

TEST(Gunship, hasAHeightClassMemberOf45)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_EQ(gunship.getHeight(), 45);
}

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

TEST(Gunship, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(205, 920));
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

TEST(Gunship, moveChangesXOfPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.move(75);
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(195, 1224));
}

TEST(Gunship, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  gunship.move(75);
}

TEST(Gunship, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);
  gunship.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  gunship.move(-50);
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(-10, 1224));
}

TEST(Gunship, moveDoesNotMovePositionRightIfPositionIsOffScreenRight)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);
  gunship.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  gunship.move(50);
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(1550, 1224));
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
  EXPECT_CALL(gunshipLaser, getHeight())
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
  ON_CALL(gunshipLaser, getHeight)
      .WillByDefault(Return(24));
  float gunshipLaserXTarget = gunship.getPosition().x + (gunship.getWidth() - gunshipLaser.getWidth()) / 2;

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
  ON_CALL(gunshipLaser, getHeight)
      .WillByDefault(Return(24));

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
  ON_CALL(gunshipLaser, getHeight)
      .WillByDefault(Return(24));

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

TEST(Gunship, resetPositionSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.setPosition(sf::Vector2f(500, 120));

  gunship.resetPosition();
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(120, 1224));
}

TEST(Gunship, resetPositionSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.setPosition(sf::Vector2f(500, 120));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  gunship.resetPosition();
}

TEST(Gunship, resetSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.setPosition(sf::Vector2f(500, 120));

  gunship.reset();
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(120, 1224));
}

TEST(Gunship, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MockLaser *gunshipLaser;
  MockSound *fireSound;
  MockSound *deathSound;
  Gunship gunship(pSprite, gunshipLaser, fireSound, deathSound);

  gunship.setPosition(sf::Vector2f(500, 120));

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
