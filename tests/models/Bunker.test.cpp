#include "../../include/Constants.hpp"
#include "../../include/models/Bunker.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class BunkerTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 {&sprite1};
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 {&sprite2};
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 {&sprite3};
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 {&sprite4};
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 {&sprite5};
  Bunker bunker {Bunker(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5)};
  MockRenderWindow window;
};

TEST_F(BunkerTest, setsSpritePositionsUponInstantiation)
{
  EXPECT_CALL(sprite1, setPosition(sf::Vector2f(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE)))
      .Times(1);
  EXPECT_CALL(sprite2, setPosition(sf::Vector2f(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE)))
      .Times(1);
  EXPECT_CALL(sprite3, setPosition(sf::Vector2f(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE)))
      .Times(1);
  EXPECT_CALL(sprite4, setPosition(sf::Vector2f(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE)))
      .Times(1);
  EXPECT_CALL(sprite5, setPosition(sf::Vector2f(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE)))
      .Times(1);
  Bunker bunker(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
}

TEST_F(BunkerTest, setsSpriteScalesUponInstantiation)
{
  EXPECT_CALL(sprite1, setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16)))
      .Times(1);
  EXPECT_CALL(sprite2, setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16)))
      .Times(1);
  EXPECT_CALL(sprite3, setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16)))
      .Times(1);
  EXPECT_CALL(sprite4, setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16)))
      .Times(1);
  EXPECT_CALL(sprite5, setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16)))
      .Times(1);
  Bunker bunker(56.25 * Constants::LENGTH_SCALE, 18.75 * Constants::LENGTH_SCALE, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
}

TEST_F(BunkerTest, hasAHealthClassMemberOf10)
{
  EXPECT_EQ(bunker.getHealth(), 10);
}

TEST_F(BunkerTest, decreaseHealthDecreasesHealthBy1)
{
  bunker.decreaseHealth();
  EXPECT_EQ(bunker.getHealth(), 9);
}

TEST_F(BunkerTest, drawCallsDrawOnWindowWithFirstSpriteIfHealthIs9or10)
{
  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST_F(BunkerTest, drawCallsDrawOnWindowWithSecondSpriteIfHealthIs7or8)
{
  for (int i = 0; i < 2; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST_F(BunkerTest, drawCallsDrawOnWindowWithThirdSpriteIfHealthIs5or6)
{
  for (int i = 0; i < 4; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST_F(BunkerTest, drawCallsDrawOnWindowWithFourthSpriteIfHealthIsAt3or4)
{
  for (int i = 0; i < 6; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST_F(BunkerTest, drawCallsDrawOnWindowWithFifthSpriteIfHealthIs1or2)
{
  for (int i = 0; i < 8; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST_F(BunkerTest, drawDoesNotCallDrawOnWindowIfHealthIs0)
{
  for (int i = 0; i < 10; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw)
      .Times(0);
  bunker.draw(window);
}

TEST_F(BunkerTest, resetSetsHealthBackTo10)
{
  for (int i = 0; i < 5; i++)
  {
    bunker.decreaseHealth();
  }

  bunker.reset();
  EXPECT_EQ(bunker.getHealth(), 10);
}
