#include "../../include/models/bunker.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Bunker, hasAWidthClassMemberOf144)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  EXPECT_EQ(bunker.getWidth(), 144);
}

TEST(Bunker, hasAHeightClassMemberOf108)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  EXPECT_EQ(bunker.getHeight(), 108);
}

TEST(Bunker, setsOwnPositionWithConstructor)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  EXPECT_EQ(bunker.getPosition(), sf::Vector2f(900, 300));
}

TEST(Bunker, setsSpritePositionUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(900, 300)))
      .Times(1);
  Bunker bunker(900, 300, pSprite);
}

TEST(Bunker, hasAHealthClassMemberOf10)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  EXPECT_EQ(bunker.getHealth(), 10);
}

TEST(Bunker, decreaseHealthDecreasesHealthBy1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  bunker.decreaseHealth();
  EXPECT_EQ(bunker.getHealth(), 9);
}

TEST(Bunker, drawCallsDrawOnWindowWithSpriteArgumentIfHealthIsGreaterThan0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  bunker.draw(window);
}

TEST(Bunker, drawDoesNotCallDrawOnWindowWithSpriteArgumentIfHealthIs0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);
  MockRenderWindow window;

  for (int i = 0; i < 10; i++)
  {
    bunker.decreaseHealth();
  }

  EXPECT_CALL(window, draw)
      .Times(0);
  bunker.draw(window);
}
