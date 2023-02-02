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
