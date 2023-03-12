#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Alpha, hasAPointsClassMemberOf20)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getPoints(), 20);
}

TEST(Alpha, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Alpha, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, hasAJustMovedDownMemberSetToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, setsPositionOnSpriteClassMemberUponInstantiation)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Alpha alpha(200, 320, pSprite);
}

TEST(Alpha, setPositionChangesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  alpha.setPosition(sf::Vector2f(500, 920));
}

TEST(Alpha, drawCallsDrawOnTheSpriteClassMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  alpha.draw(window);
}

TEST(Alpha, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.die();
  EXPECT_FALSE(alpha.isAlive());
}

TEST(Alpha, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.changeDirection();
  EXPECT_EQ(alpha.getDirection(), -1);
}

TEST(Alpha, moveAdds14Point1ToSpriteXPositionWhenDirectionIs1AndAlphaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveTakesAway14Point1FromSpriteXPositionWhenDirectionIsMinus1AndAlphaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.changeDirection();
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(200, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveAdds14Point1ToSpriteXPositionWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  alpha.changeDirection(); // alpha would be moving left so need to mimic that direction
  alpha.move();            // call to move alpha down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(14.1, 0)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveTakesAway14Point1FromSpriteXPositionWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  alpha.move(); // call to move alpha down which sets justMovedDownToTrue

  EXPECT_CALL(sprite, move(sf::Vector2f(-14.1, 0)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));
  alpha.move(); // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));
  alpha.move(); // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToSpriteYPositionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  alpha.move();
  EXPECT_EQ(alpha.getDirection(), -1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(482, 320)));

  alpha.move();
  EXPECT_TRUE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToSpriteYPositionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  EXPECT_CALL(sprite, move(sf::Vector2f(0, 42)))
      .Times(1);
  alpha.move();
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.changeDirection();
  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  alpha.move();
  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  ON_CALL(sprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(18, 320)));

  alpha.move();
  EXPECT_TRUE(alpha.hasJustMovedDown());
}

TEST(Alpha, resurrectSetsAliveBackToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.die();

  alpha.resurrect();
  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  alpha.reset();
}

TEST(Alpha, resetSetsAliveBackToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.die();

  alpha.reset();
  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, resetSetsDirectionBackTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.changeDirection();

  alpha.reset();
  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, shootSetsPositionOfFirstMetroidLaserIfBelowBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
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
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfSecondMetroidLaserIfBelowBoardAndFirstMetroidLaserIsOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
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
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfThirdMetroidLaserIfBelowBoardAndFirstAndSecondMetroidLasersAreOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
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
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootDoesNotSetPositionOfAnyMetroidLaserIfTheyAreAllOnBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
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
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootDoesNotSetPositionOfAnyMetroidLaserIfRandomNumberIsNot0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);
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
  alpha.shoot(metroidLasers, 50);
}
