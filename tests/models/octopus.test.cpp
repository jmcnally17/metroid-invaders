#include "../../include/models/octopus.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Octopus, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getWidth(), 72);
}

TEST(Octopus, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getHeight(), 48);
}

TEST(Octopus, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPoints(), 10);
}

TEST(Octopus, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Octopus octopus(200, 320, sprite);
}

TEST(Octopus, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(500, 920));
}

TEST(Octopus, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  octopus.draw(window);
}
