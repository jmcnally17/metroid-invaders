#include "../../include/models/ufo.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(UFO, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);

  EXPECT_EQ(ufo.getWidth(), 96);
}

TEST(UFO, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);

  EXPECT_EQ(ufo.getHeight(), 42);
}

TEST(UFO, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);

  EXPECT_EQ(ufo.getPoints(), 150);
}

TEST(UFO, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);

  EXPECT_EQ(ufo.getPosition(), sf::Vector2f(200, 320));
}

TEST(UFO, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  UFO ufo(200, 320, sprite);
}

TEST(UFO, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);

  ufo.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(ufo.getPosition(), sf::Vector2f(500, 920));
}

TEST(UFO, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  UFO ufo(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ufo.draw(window);
}
