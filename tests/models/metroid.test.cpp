#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class MetroidTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  Metroid metroid {Metroid(200, 320, pSprite, 50)};
  NiceMock<MockLaser> metroidLaser1;
  MockLaser *pMetroidLaser1 {&metroidLaser1};
  NiceMock<MockLaser> metroidLaser2;
  MockLaser *pMetroidLaser2 {&metroidLaser2};
  NiceMock<MockLaser> metroidLaser3;
  MockLaser *pMetroidLaser3 {&metroidLaser3};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser1, pMetroidLaser2, pMetroidLaser3};
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))};
};

TEST_F(MetroidTest, hasAPointsClassMember)
{
  EXPECT_EQ(metroid.getPoints(), 50);
}

TEST_F(MetroidTest, hasAnOriginalPositionMember)
{
  EXPECT_EQ(metroid.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST_F(MetroidTest, hasABoolClassMemberCalledAliveSetToTrue)
{
  EXPECT_TRUE(metroid.isAlive());
}

TEST_F(MetroidTest, hasADirectionClassMemberInitiallySetTo1)
{
  EXPECT_EQ(metroid.getDirection(), 1);
}

TEST_F(MetroidTest, hasAJustMovedDownMemberSetToFalse)
{
  EXPECT_FALSE(metroid.hasJustMovedDown());
}

TEST_F(MetroidTest, setsPositionOnSpriteClassMemberUponInstantiation)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Alpha metroid(200, 320, pSprite);
}

TEST_F(MetroidTest, setPositionChangesSpritePosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  metroid.setPosition(sf::Vector2f(500, 920));
}

TEST_F(MetroidTest, drawCallsDrawOnTheSpriteClassMember)
{
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  metroid.draw(window);
}

TEST_F(MetroidTest, dieChangesAliveClassMemberToFalse)
{
  metroid.die();
  EXPECT_FALSE(metroid.isAlive());
}

TEST_F(MetroidTest, changeDirectionMultipliesDirectionByMinus1)
{
  metroid.changeDirection();
  EXPECT_EQ(metroid.getDirection(), -1);
}

TEST_F(MetroidTest, moveAdds14Point1ToSpriteXPositionWhenDirectionIs1AndAlphaIsNotAtSideBoundary)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveTakesAway14Point1FromSpriteXPositionWhenDirectionIsMinus1AndAlphaIsNotAtSideBoundary)
{
  metroid.changeDirection(); // set direction to -1
  
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveAdds14Point1ToSpriteXPositionWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  Alpha metroid(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  metroid.changeDirection(); // metroid would be moving left so need to mimic that direction
  metroid.move();            // call to move metroid down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveTakesAway14Point1FromSpriteXPositionWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  metroid.move(); // call to move metroid down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveSetsJustMovedDownToFalseWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  Alpha metroid(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  metroid.move(); // call to move metroid down which sets justMovedDownToTrue

  metroid.move();
  EXPECT_FALSE(metroid.hasJustMovedDown());
}

TEST_F(MetroidTest, moveSetsJustMovedDownToFalseWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  metroid.move(); // call to move metroid down which sets justMovedDownToTrue

  metroid.move();
  EXPECT_FALSE(metroid.hasJustMovedDown());
}

TEST_F(MetroidTest, moveAdds42ToSpriteYPositionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveChangesDirectionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  metroid.move();
  EXPECT_EQ(metroid.getDirection(), -1);
}

TEST_F(MetroidTest, moveSetsJustMovedDownToTrueWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  metroid.move();
  EXPECT_TRUE(metroid.hasJustMovedDown());
}

TEST_F(MetroidTest, moveAdds42ToSpriteYPositionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  Alpha metroid(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  metroid.move();
}

TEST_F(MetroidTest, moveChangesDirectionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  Alpha metroid(300, 320, pSprite);

  metroid.changeDirection();
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  metroid.move();
  EXPECT_EQ(metroid.getDirection(), 1);
}

TEST_F(MetroidTest, moveSetsJustMovedDownToTrueWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  Alpha metroid(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  metroid.move();
  EXPECT_TRUE(metroid.hasJustMovedDown());
}

TEST_F(MetroidTest, resurrectSetsAliveBackToTrue)
{
  metroid.die();

  metroid.resurrect();
  EXPECT_TRUE(metroid.isAlive());
}

TEST_F(MetroidTest, resetSetsSpritePositionBackToOriginalPosition)
{
  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  metroid.reset();
}

TEST_F(MetroidTest, resetSetsAliveBackToTrue)
{
  metroid.die();

  metroid.reset();
  EXPECT_TRUE(metroid.isAlive());
}

TEST_F(MetroidTest, resetSetsDirectionBackTo1)
{
  metroid.changeDirection(); // set direction to -1

  metroid.reset();
  EXPECT_EQ(metroid.getDirection(), 1);
}

TEST_F(MetroidTest, shootSetsPositionOfFirstMetroidLaserIfBelowBoard)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(sf::FloatRect(sf::Vector2f(200, 320), sf::Vector2f(66, 48))));
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));
  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser1, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  metroid.shoot(metroidLasers, 0);
}

TEST_F(MetroidTest, shootSetsPositionOfSecondMetroidLaserIfBelowBoardAndFirstMetroidLaserIsOnBoard)
{
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
  metroid.shoot(metroidLasers, 0);
}

TEST_F(MetroidTest, shootSetsPositionOfThirdMetroidLaserIfBelowBoardAndFirstAndSecondMetroidLasersAreOnBoard)
{
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
  metroid.shoot(metroidLasers, 0);
}

TEST_F(MetroidTest, shootDoesNotSetPositionOfAnyMetroidLaserIfTheyAreAllOnBoard)
{
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
  metroid.shoot(metroidLasers, 0);
}

TEST_F(MetroidTest, shootDoesNotSetPositionOfAnyMetroidLaserIfRandomNumberIsNot0)
{
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
  metroid.shoot(metroidLasers, 50);
}

TEST_F(MetroidTest, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(metroid.getGlobalBounds(), spriteBounds);
}

TEST_F(MetroidTest, intersectsGetsTheSpriteGlobalBounds)
{
  sf::FloatRect rectangle;

  EXPECT_CALL(sprite, getGlobalBounds())
      .Times(1);
  metroid.intersects(rectangle);
}

TEST_F(MetroidTest, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(250, 350), sf::Vector2f(6, 24));

  EXPECT_TRUE(metroid.intersects(rectangle));
}

TEST_F(MetroidTest, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  ON_CALL(sprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(300, 500), sf::Vector2f(6, 24));

  EXPECT_FALSE(metroid.intersects(rectangle));
}
