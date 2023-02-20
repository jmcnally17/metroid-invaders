#include "../../include/models/squid.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Squid, hasAWidthClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getWidth(), 48);
}

TEST(Squid, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getHeight(), 48);
}

TEST(Squid, hasAPointsClassMemberOf30)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPoints(), 30);
}

TEST(Squid, hasAnOriginalPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, hasABoolClassMemberCalledAliveSetToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_TRUE(squid.isAlive());
}

TEST(Squid, hasADirectionClassMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getDirection(), 1);
}

TEST(Squid, hasAJustMovedDownMemberSetToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  EXPECT_FALSE(squid.hasJustMovedDown());
}

TEST(Squid, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Squid squid(200, 320, pSprite);
}

TEST(Squid, setPositionChangesPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(500, 920));
}

TEST(Squid, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Squid squid(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  squid.setPosition(sf::Vector2f(500, 920));
}

TEST(Squid, drawCallsDrawOnTheSpriteClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  squid.draw(window);
}

TEST(Squid, dieChangesAliveClassMemberToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.die();
  EXPECT_FALSE(squid.isAlive());
}

TEST(Squid, changeDirectionMultipliesDirectionByMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.changeDirection();
  EXPECT_EQ(squid.getDirection(), -1);
}

TEST(Squid, moveAdds14Point1ToXPositionWhenDirectionIs1AndSquidIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Squid, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndSquidIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.changeDirection();
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Squid, moveAdds14Point1ToXPositionWhenSquidIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320)); // put squid at left boundary
  squid.changeDirection();                  // squid would be moving left so need to mimic that direction
  squid.move();                             // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Squid, moveTakesAway14Point1FromXPositionWhenSquidIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320)); // put squid at right boundary
  squid.move();                              // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Squid, moveSetsJustMovedDownToFalseWhenSquidIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320)); // put squid at left boundary
  squid.move();                             // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_FALSE(squid.hasJustMovedDown());
}

TEST(Squid, moveSetsJustMovedDownToFalseWhenSquidIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320)); // put squid at right boundary
  squid.move();                              // call to move squid down which sets justMovedDownToTrue

  squid.move();
  EXPECT_FALSE(squid.hasJustMovedDown());
}

TEST(Squid, moveAdds42ToYPositionWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(482, 362));
}

TEST(Squid, moveChangesDirectionWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_EQ(squid.getDirection(), -1);
}

TEST(Squid, moveSetsJustMovedDownToTrueWhenSquidIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(482, 320));
  squid.move();
  EXPECT_TRUE(squid.hasJustMovedDown());
}

TEST(Squid, moveAdds42ToYPositionWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(18, 362));
}

TEST(Squid, moveChangesDirectionWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(300, 320, sprite);

  squid.changeDirection();
  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_EQ(squid.getDirection(), 1);
}

TEST(Squid, moveSetsJustMovedDownToTrueWhenSquidIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(300, 320, sprite);

  squid.setPosition(sf::Vector2f(18, 320));
  squid.move();
  EXPECT_TRUE(squid.hasJustMovedDown());
}

TEST(Squid, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Squid squid(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  squid.move();
}

TEST(Squid, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(900, 1100));

  squid.reset();
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Squid squid(200, 320, pSprite);

  squid.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  squid.reset();
}

TEST(Squid, resetSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Squid squid(200, 320, sprite);

  squid.die();

  squid.reset();
  EXPECT_TRUE(squid.isAlive());
}
