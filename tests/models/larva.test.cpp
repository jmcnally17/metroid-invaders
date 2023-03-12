#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Larva, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getPoints(), 30);
}

TEST(Larva, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Larva, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_TRUE(larva.isAlive());
}

TEST(Larva, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getDirection(), 1);
}

TEST(Larva, hasAJustMovedDownMemberSetToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_FALSE(larva.hasJustMovedDown());
}

TEST(Larva, setsPositionOnSpriteClassMemberUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Larva larva(200, 320, pSprite);
}

TEST(Larva, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  larva.setPosition(sf::Vector2f(500, 920));
}

TEST(Larva, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  larva.draw(window);
}

TEST(Larva, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.die();
  EXPECT_FALSE(larva.isAlive());
}

TEST(Larva, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.changeDirection();
  EXPECT_EQ(larva.getDirection(), -1);
}

TEST(Larva, moveAdds14Point1ToSpriteXPositionWhenDirectionIs1AndLarvaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveTakesAway14Point1FromSpriteXPositionWhenDirectionIsMinus1AndLarvaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.changeDirection();
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveAdds14Point1ToSpriteXPositionWhenLarvaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  larva.changeDirection(); // larva would be moving left so need to mimic that direction
  larva.move();            // call to move larva down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveTakesAway14Point1FromSpriteXPositionWhenLarvaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  larva.move(); // call to move larva down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveSetsJustMovedDownToFalseWhenLarvaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  larva.move(); // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_FALSE(larva.hasJustMovedDown());
}

TEST(Larva, moveSetsJustMovedDownToFalseWhenLarvaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  larva.move(); // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_FALSE(larva.hasJustMovedDown());
}

TEST(Larva, moveAdds42ToSpriteYPositionWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveChangesDirectionWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  larva.move();
  EXPECT_EQ(larva.getDirection(), -1);
}

TEST(Larva, moveSetsJustMovedDownToTrueWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  larva.move();
  EXPECT_TRUE(larva.hasJustMovedDown());
}

TEST(Larva, moveAdds42ToSpriteYPositionWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  larva.move();
}

TEST(Larva, moveChangesDirectionWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.changeDirection();
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  larva.move();
  EXPECT_EQ(larva.getDirection(), 1);
}

TEST(Larva, moveSetsJustMovedDownToTrueWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  larva.move();
  EXPECT_TRUE(larva.hasJustMovedDown());
}

TEST(Larva, resurrectSetsAliveBackToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.die();

  larva.resurrect();
  EXPECT_TRUE(larva.isAlive());
}

TEST(Larva, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  larva.reset();
}

TEST(Larva, resetSetsAliveBackToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.die();

  larva.reset();
  EXPECT_TRUE(larva.isAlive());
}

TEST(Larva, resetSetsDirectionBackTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.changeDirection();

  larva.reset();
  EXPECT_EQ(larva.getDirection(), 1);
}

TEST(Larva, shootSetsPositionOfFirstMetroidLaserIfBelowBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> metroidLaser1;
  MockLaser *pMetroidLaser1 = &metroidLaser1;
  MockLaser metroidLaser2;
  MockLaser *pMetroidLaser2 = &metroidLaser2;
  MockLaser metroidLaser3;
  MockLaser *pMetroidLaser3 = &metroidLaser3;
  metroidLasers[0] = pMetroidLaser1;
  metroidLasers[1] = pMetroidLaser2;
  metroidLasers[2] = pMetroidLaser3;

  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser1, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootSetsPositionOfSecondMetroidLaserIfBelowBoardAndFirstMetroidLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> metroidLaser1;
  MockLaser *pMetroidLaser1 = &metroidLaser1;
  NiceMock<MockLaser> metroidLaser2;
  MockLaser *pMetroidLaser2 = &metroidLaser2;
  MockLaser metroidLaser3;
  MockLaser *pMetroidLaser3 = &metroidLaser3;
  metroidLasers[0] = pMetroidLaser1;
  metroidLasers[1] = pMetroidLaser2;
  metroidLasers[2] = pMetroidLaser3;

  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(metroidLaser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser2, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootSetsPositionOfThirdMetroidLaserIfBelowBoardAndFirstAndSecondMetroidLasersAreOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> metroidLaser1;
  MockLaser *pMetroidLaser1 = &metroidLaser1;
  NiceMock<MockLaser> metroidLaser2;
  MockLaser *pMetroidLaser2 = &metroidLaser2;
  NiceMock<MockLaser> metroidLaser3;
  MockLaser *pMetroidLaser3 = &metroidLaser3;
  metroidLasers[0] = pMetroidLaser1;
  metroidLasers[1] = pMetroidLaser2;
  metroidLasers[2] = pMetroidLaser3;

  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(metroidLaser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 600)));
  ON_CALL(metroidLaser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser3, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootDoesNotSetPositionOfAnyMetroidLaserIfTheyAreAllOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> metroidLaser1;
  MockLaser *pMetroidLaser1 = &metroidLaser1;
  NiceMock<MockLaser> metroidLaser2;
  MockLaser *pMetroidLaser2 = &metroidLaser2;
  NiceMock<MockLaser> metroidLaser3;
  MockLaser *pMetroidLaser3 = &metroidLaser3;
  metroidLasers[0] = pMetroidLaser1;
  metroidLasers[1] = pMetroidLaser2;
  metroidLasers[2] = pMetroidLaser3;

  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(metroidLaser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 600)));
  ON_CALL(metroidLaser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 300)));

  EXPECT_CALL(metroidLaser1, setPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser2, setPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser3, setPosition)
      .Times(0);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootDoesNotSetPositionOfAnyMetroidLaserIfRandomNumberIsNot0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
  std::vector<ILaser *> metroidLasers(3);
  MockLaser metroidLaser1;
  MockLaser *pMetroidLaser1 = &metroidLaser1;
  MockLaser metroidLaser2;
  MockLaser *pMetroidLaser2 = &metroidLaser2;
  MockLaser metroidLaser3;
  MockLaser *pMetroidLaser3 = &metroidLaser3;
  metroidLasers[0] = pMetroidLaser1;
  metroidLasers[1] = pMetroidLaser2;
  metroidLasers[2] = pMetroidLaser3;

  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));
  ON_CALL(metroidLaser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));
  ON_CALL(metroidLaser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser1, setPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser2, setPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser3, setPosition)
      .Times(0);
  larva.shoot(metroidLasers, 50);
}

TEST(Larva, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  sf::FloatRect spriteBounds(sf::Vector2f(200, 320), sf::Vector2f(48, 48));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(larva.getGlobalBounds(), spriteBounds);
}

TEST(Larva, intersectsGetsTheSpriteGlobalBounds)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  larva.intersects(rectangle);
}

TEST(Larva, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  sf::FloatRect spriteBounds(sf::Vector2f(200, 320), sf::Vector2f(48, 48));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(230, 350), sf::Vector2f(6, 24));

  EXPECT_TRUE(larva.intersects(rectangle));
}

TEST(Larva, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  sf::FloatRect spriteBounds(sf::Vector2f(200, 320), sf::Vector2f(48, 48));
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(6, 24));

  EXPECT_FALSE(larva.intersects(rectangle));
}
