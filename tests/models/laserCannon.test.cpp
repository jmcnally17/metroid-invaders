#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

TEST(LaserCannon, setsOwnPositionMemberAndSpriteMemberPosition)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1224)))
      .Times(1);
  LaserCannon laserCannon(sprite);
  EXPECT_EQ(laserCannon.getPosition().x, 120);
  EXPECT_EQ(laserCannon.getPosition().y, 1224);
}

TEST(LaserCannon, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  MockSprite sprite;
  LaserCannon laserCannon(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  laserCannon.draw(window);
}

TEST(LaserCannon, moveChangesXOfPositionClassMember)
{
  MockSprite sprite;
  LaserCannon laserCannon(sprite);

  laserCannon.move(75);
  EXPECT_EQ(laserCannon.getPosition().x, 195);
  EXPECT_EQ(laserCannon.getPosition().y, 1224);
}

TEST(LaserCannon, moveUpdatesXPositionOfSpriteClassMember)
{
  MockSprite sprite;
  LaserCannon laserCannon(sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(195, 1224)))
      .Times(1);
  laserCannon.move(75);
}

TEST(laserCannon, moveDoesNotMovePositionRightIfPositionIsOffScreen)
{
  MockSprite sprite;
  LaserCannon laserCannon(sprite);
  laserCannon.setPosition(sf::Vector2f(-10, 1224));

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  laserCannon.move(-50);
  EXPECT_EQ(laserCannon.getPosition().x, -10);
  EXPECT_EQ(laserCannon.getPosition().y, 1224);
}
