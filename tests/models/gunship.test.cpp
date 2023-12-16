#include "../../include/models/gunship.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GunshipTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  NiceMock<MockLaser> gunshipLaser;
  MockLaser *pGunshipLaser {&gunshipLaser};
  NiceMock<MockSound> fireSound;
  MockSound *pFireSound {&fireSound};
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound {&deathSound};
  Gunship gunship {Gunship(pSprite, pGunshipLaser, pFireSound, pDeathSound)};
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(120, 1224), sf::Vector2f(78, 45))};
};

TEST_F(GunshipTest, hasALivesClassMemberInitiallySetTo3)
{
  EXPECT_EQ(gunship.getLives(), 3);
}

TEST_F(GunshipTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  Gunship gunship(pSprite, pGunshipLaser, pFireSound, pDeathSound);
}

TEST_F(GunshipTest, getPositionReturnsSpritePosition)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1224)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(gunship.getPosition(), sf::Vector2f(120, 1224));
}

TEST_F(GunshipTest, setPositionChangesSpritePosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  gunship.setPosition(sf::Vector2f(205, 920));
}

TEST_F(GunshipTest, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gunship.draw(window);
}

TEST_F(GunshipTest, moveUpdatesXPositionOfSpriteClassMember)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 1224)));

  EXPECT_CALL(sprite, move(sf::Vector2f(75, 0)))
      .Times(1);
  gunship.move(75);
}

TEST_F(GunshipTest, moveDoesNotMoveSpritePositionLeftIfPositionIsAtLeftSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-10, 1224)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(-50);
}

TEST_F(GunshipTest, moveDoesNotMoveSpritePositionRightIfPositionIsAtRightSideOfWindow)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1550, 1224)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  gunship.move(50);
}

TEST_F(GunshipTest, fireChecksPositionOfGunshipLaserClassMember)
{
  EXPECT_CALL(gunshipLaser, getPosition())
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireSetsPositionDownOnGunshipLaserClassMemberWhenAboveBoard)
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

TEST_F(GunshipTest, fireCallsPlayOnSoundClassMemberWhenAboveBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, -26)));

  EXPECT_CALL(fireSound, play())
      .Times(1);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotSetPositionDownOnGunshipLaserClassMemberWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(gunshipLaser, setPosition)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, fireDoesNotCallPlayOnSoundClassMemberWhenOnBoard)
{
  ON_CALL(gunshipLaser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(fireSound, play)
      .Times(0);
  gunship.fire();
}

TEST_F(GunshipTest, resetPositionSetsSpritePositionBackToStartingPoint)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  gunship.resetPosition();
}

TEST_F(GunshipTest, resetSetsSpritePositionBackToStartingPoint)
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

TEST_F(GunshipTest, loseLifePlaysDeathSoundClassMember)
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

TEST_F(GunshipTest, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(gunship.getGlobalBounds(), spriteBounds);
}

TEST_F(GunshipTest, intersectsGetsTheSpriteGlobalBounds)
{
  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  gunship.intersects(rectangle);
}

TEST_F(GunshipTest, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(130, 1210), sf::Vector2f(18, 36));

  EXPECT_TRUE(gunship.intersects(rectangle));
}

TEST_F(GunshipTest, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(18, 36));

  EXPECT_FALSE(gunship.intersects(rectangle));
}
