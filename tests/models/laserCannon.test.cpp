#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(LaserCannon, setsOwnPositionMemberAndSpriteMemberPosition)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);

  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(120, 1224));
}

TEST(LaserCannon, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon laserCannon(sprite);
}

TEST(LaserCannon, hasAWidthClassMemberOf78)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);

  EXPECT_EQ(laserCannon.getWidth(), 78);
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  laserCannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);

  laserCannon.move(75);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(195, 1224));
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  laserCannon.move(75);
}

TEST(laserCannon, moveDoesNotMovePositionLeftIfPositionIsOffScreenLeft)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);
  laserCannon.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laserCannon.move(-50);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(-10, 1224));
}

TEST(laserCannon, moveDoesNotMovePositionRightIfPositionIsOffScreenRight)
{
  NiceMock<MockSprite> sprite;
  LaserCannon laserCannon(sprite);
  laserCannon.setPosition(sf::Vector2f(1550, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laserCannon.move(50);
  EXPECT_EQ(laserCannon.getPosition(), sf::Vector2f(1550, 1224));
}
