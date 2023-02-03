#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockLaser.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::InSequence;
using ::testing::NiceMock;
using ::testing::Return;

TEST(LaserCannon, setsOwnPositionMemberAndSpriteMemberPosition)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockLaser laser;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon laserCannon(sprite, laser);
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  EXPECT_EQ(laserCannon.getWidth(), 78);
}

TEST(LaserCannon, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  laserCannon.setPosition(sf::Vector2f(205, 920));
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(205, 920));
}

TEST(LaserCannon, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(205, 920)))
      .Times(1);
  laserCannon.setPosition(sf::Vector2f(205, 920));
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  laserCannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  laserCannon.move(75);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  laserCannon.move(75);
}

TEST(laserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);
  laserCannon.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laserCannon.move(-50);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(-10, 1224));
}

TEST(laserCannon, moveDoesNotMovePositionRightIfPositionIsOffScreenRight)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);
  laserCannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laserCannon.move(50);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(1550, 1224));
}

TEST(LaserCannon, fireSetsPositionDownOnLaserClassMemberWhenAboveBoard)
{
  NiceMock<MockSprite> sprite;
  MockLaser laser;
  LaserCannon laserCannon(sprite, laser);
  ON_CALL(laser, getPosition)
      .WillByDefault(Return(sf::Vector2f(-26, 500)));
  float laserXTarget = laserCannon.getPosition().x + (laserCannon.getWidth() - laser.getWidth()) / 2;

  InSequence s;

  EXPECT_CALL(laser, getPosition())
      .Times(1);
  EXPECT_CALL(laser, setPosition(sf::Vector2f(laserXTarget, 1224)))
      .Times(1);
  laserCannon.fire();
}
