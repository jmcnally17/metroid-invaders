#include <gtest/gtest.h>
#include "../../include/models/laser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Laser, hasAPositionUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);

  EXPECT_EQ(laser.getPosition(), sf::Vector2f(120, -24));
}

TEST(Laser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, -24)));
  Laser laser(sprite);
}

TEST(Laser, setPositionChangesPositionClassMember)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);

  laser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(530, 890));
}

TEST(Laser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)));
  laser.setPosition(sf::Vector2f(530, 890));
}

TEST(Laser, drawCallsDrawOnWindowArgument)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  laser.draw(window);
}

TEST(Laser, moveDecreasesYPositionWhenLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);
  laser.setPosition(sf::Vector2f(500, 1000));

  laser.move();
  EXPECT_EQ(laser.getPosition(), sf::Vector2f(500, 999.5));
}

TEST(Laser, moveUpdatesSpritePositionWhenLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  Laser laser(sprite);
  laser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 999.5)));
  laser.move();
}
