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
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(120, 1224), sf::Vector2f(78, 45))};
};

TEST_F(GunshipTest, setsLivesToThreeUponInstantiation)
{
  EXPECT_EQ(gunship.getLives(), 3);
}

TEST_F(GunshipTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, pDeathSound);
}

TEST_F(GunshipTest, moveMovesSpriteToTheRight)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 1224)));

  EXPECT_CALL(sprite, move(sf::Vector2f(3.2, 0)))
      .Times(1);
  gunship.move(1);
}

TEST_F(GunshipTest, moveMovesSpriteToTheLeft)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 1224)));

  EXPECT_CALL(sprite, move(sf::Vector2f(-3.2, 0)))
      .Times(1);
  gunship.move(-1);
}

TEST_F(GunshipTest, moveDoesNotMoveSpriteToTheRightIfAtRightSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1550, 1224)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(1);
}

TEST_F(GunshipTest, moveDoesNotMoveSpriteToTheLeftIfAtLeftSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-10, 1224)));

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
      .WillByDefault(Return(sf::Vector2f(500, -26)));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(700, 1224)));
  float gunshipLaserXTarget = gunship.getPosition().x + (78 - 6) / 2;

  EXPECT_CALL(gunshipLaser, setPosition(sf::Vector2f(gunshipLaserXTarget, 1224)))
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireCallsPlayOnFireSoundWhenAboveBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotSetPositionDownOnGunshipLaserWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(gunshipLaser, setPosition)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotCallPlayOnFireSoundWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, resetSetsSpriteBackToStartingPoint)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
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
