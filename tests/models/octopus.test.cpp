#include "../../include/models/octopus.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Octopus, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getWidth(), 72);
}

TEST(Octopus, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getHeight(), 48);
}

TEST(Octopus, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPoints(), 10);
}

TEST(Octopus, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.isAlive(), true);
}

TEST(Octopus, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  Octopus Octopus(200, 320, sprite);

  EXPECT_EQ(Octopus.getDirection(), 1);
}

TEST(Octopus, hasAJustMovedDownMemberSetToFalse)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.hasJustMovedDown(), false);
}

TEST(Octopus, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Octopus octopus(200, 320, sprite);
}

TEST(Octopus, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(500, 920));
}

TEST(Octopus, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  octopus.setPosition(sf::Vector2f(500, 920));
}

TEST(Octopus, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  octopus.draw(window);
}

TEST(Octopus, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.die();
  EXPECT_EQ(octopus.isAlive(), false);
}

TEST(Octopus, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.changeDirection();
  EXPECT_EQ(octopus.getDirection(), -1);
}

TEST(Octopus, moveAdds14Point1ToXPositionWhenDirectionIs1AndOctopusIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Octopus, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndOctopusIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.changeDirection();
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Octopus, moveAdds14Point1ToXPositionWhenOctopusIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320)); // put octopus at left boundary
  octopus.changeDirection();                  // octopus would be moving left so need to mimic that direction
  octopus.move();                             // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Octopus, moveTakesAway14Point1FromXPositionWhenOctopusIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320)); // put octopus at right boundary
  octopus.move();                              // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Octopus, moveSetsJustMovedDownToFalseWhenOctopusIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320)); // put octopus at left boundary
  octopus.move();                             // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.hasJustMovedDown(), false);
}

TEST(Octopus, moveSetsJustMovedDownToFalseWhenOctopusIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320)); // put octopus at right boundary
  octopus.move();                              // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.hasJustMovedDown(), false);
}

TEST(Octopus, moveAdds42ToYPositionWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(482, 362));
}

TEST(Octopus, moveChangesDirectionWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_EQ(octopus.getDirection(), -1);
}

TEST(Octopus, moveSetsJustMovedDownToTrueWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_EQ(octopus.hasJustMovedDown(), true);
}

TEST(Octopus, moveAdds42ToYPositionWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(18, 362));
}

TEST(Octopus, moveChangesDirectionWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(300, 320, sprite);

  octopus.changeDirection();
  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_EQ(octopus.getDirection(), 1);
}

TEST(Octopus, moveSetsJustMovedDownToTrueWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_EQ(octopus.hasJustMovedDown(), true);
}

TEST(Octopus, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  octopus.move();
}

TEST(Octopus, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(900, 1100));

  octopus.reset();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  octopus.reset();
}
