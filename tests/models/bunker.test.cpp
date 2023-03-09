#include "../../include/models/bunker.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Bunker, hasAWidthClassMemberOf144)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  EXPECT_EQ(bunker.getWidth(), 144);
}

TEST(Bunker, hasAHeightClassMemberOf108)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  EXPECT_EQ(bunker.getHeight(), 108);
}

TEST(Bunker, setsOwnPositionWithConstructor)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  EXPECT_EQ(bunker.getPosition(), sf::Vector2f(900, 300));
}

TEST(Bunker, setsSpritePositionsUponInstantiation)
{
  MockSprite sprite1;
  MockSprite *pSprite1 = &sprite1;
  MockSprite sprite2;
  MockSprite *pSprite2 = &sprite2;
  MockSprite sprite3;
  MockSprite *pSprite3 = &sprite3;
  MockSprite sprite4;
  MockSprite *pSprite4 = &sprite4;
  MockSprite sprite5;
  MockSprite *pSprite5 = &sprite5;

  EXPECT_CALL(sprite1, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  EXPECT_CALL(sprite2, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  EXPECT_CALL(sprite3, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  EXPECT_CALL(sprite4, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  EXPECT_CALL(sprite5, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
}

TEST(Bunker, hasAHealthClassMemberOf10)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  EXPECT_EQ(bunker.getHealth(), 10);
}

TEST(Bunker, decreaseHealthDecreasesHealthBy1)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  bunker.decreaseHealth();
  EXPECT_EQ(bunker.getHealth(), 9);
}

TEST(Bunker, drawCallsDrawOnWindowWithFirstSpriteIfHealthIs9or10)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawCallsDrawOnWindowWithSecondSpriteIfHealthIs7or8)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  for (int i = 0; i < 2; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawCallsDrawOnWindowWithThirdSpriteIfHealthIs5or6)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  for (int i = 0; i < 4; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawCallsDrawOnWindowWithFourthSpriteIfHealthIsAt3or4)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  for (int i = 0; i < 6; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawCallsDrawOnWindowWithFifthSpriteIfHealthIs1or2)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  for (int i = 0; i < 8; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawDoesNotCallDrawOnWindowIfHealthIs0)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);
  MockRenderWindow window;

  for (int i = 0; i < 10; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw)
      .Times(0);
  bunker.draw(window);
}

TEST(Bunker, resetSetsHealthBackTo10)
{
  NiceMock<MockSprite> sprite1;
  MockSprite *pSprite1 = &sprite1;
  NiceMock<MockSprite> sprite2;
  MockSprite *pSprite2 = &sprite2;
  NiceMock<MockSprite> sprite3;
  MockSprite *pSprite3 = &sprite3;
  NiceMock<MockSprite> sprite4;
  MockSprite *pSprite4 = &sprite4;
  NiceMock<MockSprite> sprite5;
  MockSprite *pSprite5 = &sprite5;
  Bunker bunker(900, 300, pSprite1, pSprite2, pSprite3, pSprite4, pSprite5);

  for (int i = 0; i < 5; i++)
  {
    bunker.decreaseHealth();
  }

  bunker.reset();
  EXPECT_EQ(bunker.getHealth(), 10);
}
