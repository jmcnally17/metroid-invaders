#include "../../include/models/invaderLaser.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(InvaderLaser, hasAPositionUponInstantiation)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);

  EXPECT_EQ(invaderLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST(InvaderLaser, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(120, 1344)))
      .Times(1);
  InvaderLaser invaderLaser(pSprite);
}

TEST(InvaderLaser, hasAWidthClassMemberOf18)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);

  EXPECT_EQ(invaderLaser.getWidth(), 18);
}

TEST(InvaderLaser, hasAHeightClassMemberOf36)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);

  EXPECT_EQ(invaderLaser.getHeight(), 36);
}

TEST(InvaderLaser, setPositionChangesPositionClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);

  invaderLaser.setPosition(sf::Vector2f(530, 890));
  EXPECT_EQ(invaderLaser.getPosition(), sf::Vector2f(530, 890));
}

TEST(InvaderLaser, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  InvaderLaser invaderLaser(pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(530, 890)))
      .Times(1);
  invaderLaser.setPosition(sf::Vector2f(530, 890));
}

TEST(InvaderLaser, drawCallsDrawOnWindowArgumentWhenInvaderLaserIsOnBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);
  MockRenderWindow window;
  invaderLaser.setPosition(sf::Vector2f(600, 700));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  invaderLaser.draw(window);
}

TEST(InvaderLaser, drawDoesNotCallDrawOnWindowArgumentWhenInvaderLaserIsBelowBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(0);
  invaderLaser.draw(window);
}

TEST(InvaderLaser, moveIncreasesYPositionWhenInvaderLaserIsOnTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);
  invaderLaser.setPosition(sf::Vector2f(500, 1000));

  invaderLaser.move();
  EXPECT_EQ(invaderLaser.getPosition(), sf::Vector2f(500, 1000.5));
}

TEST(InvaderLaser, moveUpdatesSpritePositionWhenInvaderLaserIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  InvaderLaser invaderLaser(pSprite);
  invaderLaser.setPosition(sf::Vector2f(500, 1000));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 1000.5)))
      .Times(1);
  invaderLaser.move();
}

TEST(InvaderLaser, moveDoesNotincreaseYPositionWhenInvaderLaserIsBelowTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);

  invaderLaser.move();
  EXPECT_EQ(invaderLaser.getPosition(), sf::Vector2f(120, 1344));
}

TEST(InvaderLaser, moveDoesNotUpdateSpritePositionWhenInvaderLaserIsBelowTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  InvaderLaser invaderLaser(pSprite);

  EXPECT_CALL(sprite, setPosition)
      .Times(0);
  invaderLaser.move();
}

TEST(InvaderLaser, resetSetsPositionBackBelowTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  InvaderLaser invaderLaser(sprite);
  invaderLaser.setPosition(sf::Vector2f(400, 900));

  invaderLaser.reset();
  EXPECT_EQ(invaderLaser.getPosition(), sf::Vector2f(120, 1344));
}
