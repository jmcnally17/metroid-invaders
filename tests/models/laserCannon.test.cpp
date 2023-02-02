#include "../../include/models/laserCannon.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

TEST(LaserCannon, hasAPositionUponInstantiation)
{
  MockSprite sprite;
  LaserCannon laserCannon(sprite);

  EXPECT_EQ(laserCannon.getPosition().x, 1416);
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
