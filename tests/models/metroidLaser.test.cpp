#include "../../include/models/metroidLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(MetroidLaser, hasAPositionUponInstantiation)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);

  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST(MetroidLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  MetroidLaser metroidLaser(pSprite);
}

TEST(MetroidLaser, hasAWidthClassMemberOf18)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);

  EXPECT_EQ(metroidLaser.getWidth(), 18);
}

TEST(MetroidLaser, hasAHeightClassMemberOf36)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);

  EXPECT_EQ(metroidLaser.getHeight(), 36);
}

TEST(MetroidLaser, setPositionChangesPositionClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);

  metroidLaser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(530, 890));
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
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);
  MockRenderWindow window;
  metroidLaser.setPosition(sf::Vector2f(600, 700));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  metroidLaser.draw(window);
}

TEST(MetroidLaser, drawDoesNotCallDrawOnWindowArgumentWhenMetroidLaserIsBelowBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(0);
  metroidLaser.draw(window);
}

TEST(MetroidLaser, moveIncreasesYPositionWhenMetroidLaserIsOnTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);
  metroidLaser.setPosition(sf::Vector2f(500, 1000));

  metroidLaser.move();
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(500, 1000.5));
}

TEST(MetroidLaser, moveUpdatesSpritePositionWhenMetroidLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);
  metroidLaser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 1000.5)))
      .Times(1);
  metroidLaser.move();
}

TEST(MetroidLaser, moveDoesNotincreaseYPositionWhenMetroidLaserIsBelowTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);

  metroidLaser.move();
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST(MetroidLaser, moveDoesNotUpdateSpritePositionWhenMetroidLaserIsBelowTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  MetroidLaser metroidLaser(pSprite);

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  metroidLaser.move();
}

TEST(MetroidLaser, resetSetsPositionBackBelowTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  MetroidLaser metroidLaser(sprite);
  metroidLaser.setPosition(sf::Vector2f(400, 900));

  metroidLaser.reset();
  EXPECT_EQ(metroidLaser.getPosition(), sf::Vector2f(120, 1344));
}
