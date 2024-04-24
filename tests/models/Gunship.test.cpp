#include "../../include/Constants.hpp"
#include "../../include/models/Gunship.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockGunshipLaser.hpp"
#include "../mockModels/MockSound.hpp"
#include "../mockModels/MockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GunshipTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  NiceMock<MockGunshipLaser> gunshipLaser;
  MockGunshipLaser *pGunshipLaser {&gunshipLaser};
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound {&fireSound};
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound {&deathSound};
  Gunship gunship {Gunship(pSprite, pGunshipLaser, pFireSound, pDeathSound)};
};

TEST_F(GunshipTest, setsLivesToThreeUponInstantiation)
{
  EXPECT_EQ(gunship.getLives(), 3);
}

TEST_F(GunshipTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(7.5 * Constants::lengthScale, 76.5 * Constants::lengthScale)))
      .Times(1);
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, pDeathSound);
}

TEST_F(GunshipTest, moveMovesSpriteToTheRight)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(37.5 * Constants::lengthScale, 76.5 * Constants::lengthScale)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0.2 * Constants::lengthScale, 0)))
      .Times(1);
  gunship.move(1);
}

TEST_F(GunshipTest, moveMovesSpriteToTheLeft)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(37.5 * Constants::lengthScale, 76.5 * Constants::lengthScale)));

  EXPECT_CALL(sprite, move(sf::Vector2f(-0.2 * Constants::lengthScale, 0)))
      .Times(1);
  gunship.move(-1);
}

TEST_F(GunshipTest, moveDoesNotMoveSpriteToTheRightIfAtRightSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(96.875 * Constants::lengthScale, 76.5 * Constants::lengthScale)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(1);
}

TEST_F(GunshipTest, moveDoesNotMoveSpriteToTheLeftIfAtLeftSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-0.625 * Constants::lengthScale, 76.5 * Constants::lengthScale)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(-1);
}

TEST_F(GunshipTest, fireChecksPositionOfGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, getPosition())
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireSetsPositionDownOnGunshipLaserWhenAboveBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(31.25 * Constants::lengthScale, -1.625 * Constants::lengthScale)));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(43.75 * Constants::lengthScale, 76.5 * Constants::lengthScale)));
  float gunshipLaserXTarget = gunship.getPosition().x + (2.25 * Constants::lengthScale);

  EXPECT_CALL(gunshipLaser, setPosition(sf::Vector2f(gunshipLaserXTarget, 76.5 * Constants::lengthScale)))
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireCallsPlayOnFireSoundWhenAboveBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(31.25 * Constants::lengthScale, -1.625 * Constants::lengthScale)));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotSetPositionDownOnGunshipLaserWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(31.25 * Constants::lengthScale, 31.25 * Constants::lengthScale)));

  EXPECT_CALL(gunshipLaser, setPosition)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotCallPlayOnFireSoundWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(31.25 * Constants::lengthScale, 31.25 * Constants::lengthScale)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, resetSetsSpriteBackToStartingPoint)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(7.5 * Constants::lengthScale, 76.5 * Constants::lengthScale)))
      .Times(1);
  gunship.reset();
}

TEST_F(GunshipTest, loseLifeDecreasesLivesBy1)
{
  gunship.loseLife();
  EXPECT_EQ(gunship.getLives(), 2);
}

TEST_F(GunshipTest, loseLifePlaysDeathSound)
{
  EXPECT_CALL(deathSound, play())
      .Times(1);
  gunship.loseLife();
}

TEST_F(GunshipTest, resetSetsLivesBackTo3)
{
  gunship.loseLife(); // lose a life so it is at 2

  gunship.reset();
  EXPECT_EQ(gunship.getLives(), 3);
}
