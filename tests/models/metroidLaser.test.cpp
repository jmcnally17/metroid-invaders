#include "../../include/models/metroidLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(MetroidLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  MetroidLaser metroidLaser(pSprite);
}

TEST(MetroidLaser, getPositionReturnsSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(sprite, getPosition())
      .Times(1);
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST(MetroidLaser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  metroidLaser.setPosition(sf::Vector2f(530, 890));
}

TEST(MetroidLaser, drawCallsDrawOnWindowArgumentWhenMetroidLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);
  MockRenderWindow window;

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(600, 700)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  metroidLaser.draw(window);
}

TEST(MetroidLaser, drawDoesNotCallDrawOnWindowArgumentWhenMetroidLaserIsBelowBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);
  MockRenderWindow window;

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(window, draw)
      .Times(0);
  metroidLaser.draw(window);
}

TEST(MetroidLaser, moveIncreasesSpriteYPositionWhenMetroidLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 1000)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 6.4)))
      .Times(1);
  metroidLaser.move();
}

TEST(MetroidLaser, moveDoesNotincreaseSpriteYPositionWhenMetroidLaserIsBelowTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(sprite, move)
      .Times(0);
  metroidLaser.move();
}

TEST(MetroidLaser, resetSetsSpritePositionBackBelowTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  metroidLaser.reset();
}
