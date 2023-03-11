#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Alpha, hasAWidthClassMemberOf66)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getWidth(), 66);
}

TEST(Alpha, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getHeight(), 48);
}

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

TEST(Alpha, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(200, 320));
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

TEST(Alpha, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Alpha alpha(200, 320, pSprite);
}

TEST(Alpha, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(500, 920));
}

TEST(Alpha, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
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

TEST(Alpha, moveAdds14Point1ToXPositionWhenDirectionIs1AndAlphaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Alpha, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndAlphaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.changeDirection();
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Alpha, moveAdds14Point1ToXPositionWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.setPosition(sf::Vector2f(18, 320)); // put alpha at left boundary
  alpha.changeDirection();                  // alpha would be moving left so need to mimic that direction
  alpha.move();                             // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Alpha, moveTakesAway14Point1FromXPositionWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(482, 320)); // put alpha at right boundary
  alpha.move();                              // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.setPosition(sf::Vector2f(18, 320)); // put alpha at left boundary
  alpha.move();                             // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(482, 320)); // put alpha at right boundary
  alpha.move();                              // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToYPositionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(482, 362));
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_EQ(alpha.getDirection(), -1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_TRUE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToYPositionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.setPosition(sf::Vector2f(18, 320));
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(18, 362));
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.changeDirection();
  alpha.setPosition(sf::Vector2f(18, 320));
  alpha.move();
  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(300, 320, pSprite);

  alpha.setPosition(sf::Vector2f(18, 320));
  alpha.move();
  EXPECT_TRUE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)))
      .Times(1);
  alpha.move();
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

TEST(Alpha, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(900, 1100));

  alpha.reset();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(200, 320));
}

TEST(Alpha, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Alpha alpha(200, 320, pSprite);

  alpha.setPosition(sf::Vector2f(900, 1100));

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

TEST(Alpha, shootSetsPositionOfFirstMetroidLaserIfBelowBoardAndAlphaIsAlive)
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

  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser1, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfSecondMetroidLaserIfBelowBoardAndFirstMetroidLaserIsOnBoardAndAlphaIsAlive)
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

  ON_CALL(metroidLaser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(metroidLaser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(metroidLaser2, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfThirdMetroidLaserIfBelowBoardAndFirstAndSecondMetroidLasersAreOnBoardAndAlphaIsAlive)
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

TEST(Alpha, shootDoesNotSetPositionOfAnyMetroidLaserIfTheyAreAllOnBoardAndAlphaIsAlive)
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
