#include "../../include/models/crab.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Crab, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getWidth(), 66);
}

TEST(Crab, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getHeight(), 48);
}

TEST(Crab, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getPoints(), 20);
}

TEST(Crab, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Crab, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getPosition(), sf::Vector2f(200, 320));
}

TEST(Crab, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.isAlive(), true);
}

TEST(Crab, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getDirection(), 1);
}

TEST(Crab, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Crab crab(200, 320, sprite);
}

TEST(Crab, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(500, 920));
}

TEST(Crab, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  crab.setPosition(sf::Vector2f(500, 920));
}

TEST(Crab, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  crab.draw(window);
}

TEST(Crab, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.die();
  EXPECT_EQ(crab.isAlive(), false);
}

TEST(Crab, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.changeDirection();
  EXPECT_EQ(crab.getDirection(), -1);
}

TEST(Crab, moveAdds14Point1ToXPositionWhenDirectionIs1AndCrabIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Crab, moveTakesAway14Point1ToXPositionWhenDirectionIsMinus1AndCrabIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.changeDirection();
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Crab, moveAdds42ToYPositionWhenCrabIsAtRightSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320));
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(482, 362));
}

TEST(Crab, moveAdds42ToYPositionWhenCrabIsAtLeftSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Crab crab(300, 320, sprite);

  crab.setPosition(sf::Vector2f(18, 320));
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(18, 362));
}

TEST(Crab, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  Crab crab(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  crab.move();
}
