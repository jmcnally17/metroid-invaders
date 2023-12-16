#include "../../include/models/metroidLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MetroidLaserTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MetroidLaser metroidLaser {MetroidLaser(pSprite)};
  MockRenderWindow window;
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(800, 900), sf::Vector2f(18, 36))};
};

TEST_F(MetroidLaserTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  MetroidLaser metroidLaser(pSprite);
}

TEST_F(MetroidLaserTest, getPositionReturnsSpritePosition)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST_F(MetroidLaserTest, setPositionChangesSpritePosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  metroidLaser.setPosition(sf::Vector2f(530, 890));
}

TEST_F(MetroidLaserTest, drawCallsDrawOnWindowArgumentWhenMetroidLaserIsOnBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 700)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  metroidLaser.draw(window);
}

TEST_F(MetroidLaserTest, drawDoesNotCallDrawOnWindowArgumentWhenMetroidLaserIsBelowBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(window, draw)
      .Times(0);
  metroidLaser.draw(window);
}

TEST_F(MetroidLaserTest, moveIncreasesSpriteYPositionWhenMetroidLaserIsOnTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 6.4)))
      .Times(1);
  metroidLaser.move();
}

TEST_F(MetroidLaserTest, moveDoesNotincreaseSpriteYPositionWhenMetroidLaserIsBelowTheBoard)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  metroidLaser.move();
}

TEST_F(MetroidLaserTest, resetSetsSpritePositionBackBelowTheBoard)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  metroidLaser.reset();
}

TEST_F(MetroidLaserTest, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(metroidLaser.getGlobalBounds(), spriteBounds);
}

TEST_F(MetroidLaserTest, intersectsGetsTheSpriteGlobalBounds)
{
  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  metroidLaser.intersects(rectangle);
}

TEST_F(MetroidLaserTest, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(770, 920), sf::Vector2f(78, 45));

  EXPECT_TRUE(metroidLaser.intersects(rectangle));
}

TEST_F(MetroidLaserTest, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(120, 1224), sf::Vector2f(78, 45));

  EXPECT_FALSE(metroidLaser.intersects(rectangle));
}
