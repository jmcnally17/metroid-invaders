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

TEST(bunker, hasAHealthClassMemberOf10)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Bunker bunker(900, 300, pSprite);

  EXPECT_EQ(bunker.getHealth(), 10);
}

TEST(Bunker, drawCallsDrawOnWndowWithSpriteArgumentIfHealthIsGreateThan0)
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
