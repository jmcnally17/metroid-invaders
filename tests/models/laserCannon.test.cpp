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
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockLaser laser;
  MockSound sound;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon cannon(sprite, laser, sound);
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getWidth(), 78);
}

TEST(LaserCannon, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_EQ(cannon.getHeight(), 48);
}

TEST(LaserCannon, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(205, 920));
}

TEST(LaserCannon, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  cannon.setPosition(sf::Vector2f(205, 920));
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  cannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.move(75);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  cannon.move(75);
}

TEST(LaserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
  cannon.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(-50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(-10, 1224));
}

TEST(LaserCannon, moveDoesNotMovePositionRightIfPositionIsOffScreenRight)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
  cannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  cannon.move(50);
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(1550, 1224));
}

TEST(LaserCannon, fireChecksPositionOfLaserClassMember)
{
  NiceMock<MockSprite> sprite;
  NiceMock<MockLaser> laser;
  NiceMock<MockSound> sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_CALL(laser, getPosition())
      .Times(1);
  EXPECT_CALL(laser, getHeight())
      .Times(1);
  cannon.fire();
}

TEST(LaserCannon, fireSetsPositionDownOnLaserClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  NiceMock<MockLaser> laser;
  NiceMock<MockSound> sound;
  LaserCannon cannon(sprite, laser, sound);
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
  NiceMock<MockLaser> laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
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
  NiceMock<MockSprite> sprite;
  NiceMock<MockLaser> laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
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
  NiceMock<MockLaser> laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);
  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(500, 500)));

  EXPECT_CALL(sound, play)
      .Times(0);
  cannon.fire();
}

TEST(LaserCannon, resetSetsPositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  NiceMock<MockLaser> laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  cannon.reset();
  EXPECT_EQ(cannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, resetSetsSpritePositionBackToStartingPoint)
{
  NiceMock<MockSprite> sprite;
  NiceMock<MockLaser> laser;
  MockSound sound;
  LaserCannon cannon(sprite, laser, sound);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(2); // needs to be 2 times because of the initial call in the constructor!
  cannon.reset();
}
