#include "../../include/models/GameObject.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockRenderWindow.hpp"
#include "../mockModels/MockGameObject.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class GameObjectTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  GameObject gameObject {GameObject(900, 300, pSprite)};
  NiceMock<MockGameObject> mockGameObject;
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(900, 300), sf::Vector2f(144, 108))};
};

TEST_F(GameObjectTest, setsSpritePositionUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(900, 300)))
    .Times(1);
  GameObject gameObject(900, 300, pSprite);
}

TEST_F(GameObjectTest, getPositionReturnsSpritePosition)
{
  ON_CALL(sprite, getPosition())
    .WillByDefault(Return(sf::Vector2f(900, 300)));
  
  EXPECT_CALL(sprite, getPosition())
    .Times(1);
  EXPECT_EQ(gameObject.getPosition(), sf::Vector2f(900, 300));
}

TEST_F(GameObjectTest, setPositionSetsTheSpritePosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 750)))
    .Times(1);
  gameObject.setPosition(sf::Vector2f(500, 750));
}

TEST_F(GameObjectTest, drawCallsDrawOnTheWindowWithSpriteArgument)
{
  MockRenderWindow window;
  
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
    .Times(1);
  gameObject.draw(window);
}

TEST_F(GameObjectTest, getGlobalBoundsReturnsTheSpriteBounds)
{
  ON_CALL(sprite, getGlobalBounds())
    .WillByDefault(Return(spriteBounds));
  
  EXPECT_CALL(sprite, getGlobalBounds())
    .Times(1);
  EXPECT_EQ(gameObject.getGlobalBounds(), spriteBounds);
}

TEST_F(GameObjectTest, intersectsGetsTheGlobalBounds)
{
  EXPECT_CALL(sprite, getGlobalBounds())
    .Times(1);
  EXPECT_CALL(mockGameObject, getGlobalBounds())
    .Times(1);
  gameObject.intersects(mockGameObject);
}

TEST_F(GameObjectTest, intersectsReturnsTrueWhenCollidingWithAnotherGameObject)
{
  ON_CALL(sprite, getGlobalBounds())
    .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(910, 290), sf::Vector2f(6, 24));
  ON_CALL(mockGameObject, getGlobalBounds())
    .WillByDefault(Return(rectangle));

  EXPECT_TRUE(gameObject.intersects(mockGameObject));
}

TEST_F(GameObjectTest, intersectsReturnsFalseWhenNotCollidingWithAnotherGameObject)
{
  ON_CALL(sprite, getGlobalBounds())
    .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(6, 24));
  ON_CALL(mockGameObject, getGlobalBounds())
    .WillByDefault(Return(rectangle));

  EXPECT_FALSE(gameObject.intersects(mockGameObject));
}
