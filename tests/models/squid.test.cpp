#include "../../include/models/squid.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Squid, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getWidth(), 48);
}

TEST(Squid, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getHeight(), 48);
}

TEST(Squid, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPoints(), 30);
}

TEST(Squid, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.isAlive(), true);
}

TEST(Squid, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getDirection(), 1);
}

TEST(Squid, hasAJustMovedDownMemberSetToFalse)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.hasJustMovedDown(), false);
}

TEST(Squid, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Squid squid(200, 320, sprite);
}

TEST(Squid, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(500, 920));
}

TEST(Squid, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  squid.setPosition(sf::Vector2f(500, 920));
}

TEST(Squid, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  squid.draw(window);
}

TEST(Squid, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.die();
  EXPECT_EQ(squid.isAlive(), false);
}

TEST(Squid, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.changeDirection();
  EXPECT_EQ(squid.getDirection(), -1);
}

TEST(Squid, moveAdds14Point1ToXPositionWhenDirectionIs1AndSquidIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Squid, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndSquidIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.changeDirection();
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Squid, moveAdds14Point1ToXPositionWhenSquidIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320)); // put squid at left boundary
  squid.changeDirection();                  // squid would be moving left so need to mimic that direction
  squid.move();                             // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Squid, moveTakesAway14Point1FromXPositionWhenSquidIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320)); // put squid at right boundary
  squid.move();                              // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Squid, moveAdds42ToYPositionWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(482, 362));
}

TEST(Squid, moveChangesDirectionWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_EQ(squid.getDirection(), -1);
}

TEST(Squid, moveSetsJustMovedDownToTrueWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_EQ(squid.hasJustMovedDown(), true);
}

TEST(Squid, moveAdds42ToYPositionWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(18, 362));
}

TEST(Squid, moveChangesDirectionWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(300, 320, sprite);

  squid.changeDirection();
  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_EQ(squid.getDirection(), 1);
}

TEST(Squid, moveSetsJustMovedDownToTrueWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_EQ(squid.hasJustMovedDown(), true);
}

TEST(Squid, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  squid.move();
}
