#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Alpha, hasAWidthClassMemberOf66)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getWidth(), 66);
}

TEST(Alpha, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getHeight(), 48);
}

TEST(Alpha, hasAPointsClassMemberOf20)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getPoints(), 20);
}

TEST(Alpha, hasAnOriginalPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Alpha, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(200, 320));
}

TEST(Alpha, hasABoolClassMemberCalledAliveSetToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, hasADirectionClassMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, hasAJustMovedDownMemberSetToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

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
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

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
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  alpha.draw(window);
}

TEST(Alpha, dieChangesAliveClassMemberToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.die();
  EXPECT_FALSE(alpha.isAlive());
}

TEST(Alpha, changeDirectionMultipliesDirectionByMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.changeDirection();
  EXPECT_EQ(alpha.getDirection(), -1);
}

TEST(Alpha, moveAdds14Point1ToXPositionWhenDirectionIs1AndAlphaIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Alpha, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndAlphaIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.changeDirection();
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Alpha, moveAdds14Point1ToXPositionWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(300, 320, sprite);

  alpha.setPosition(sf::Vector2f(18, 320)); // put alpha at left boundary
  alpha.changeDirection();                  // alpha would be moving left so need to mimic that direction
  alpha.move();                             // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Alpha, moveTakesAway14Point1FromXPositionWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.setPosition(sf::Vector2f(482, 320)); // put alpha at right boundary
  alpha.move();                              // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(300, 320, sprite);

  alpha.setPosition(sf::Vector2f(18, 320)); // put alpha at left boundary
  alpha.move();                             // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveSetsJustMovedDownToFalseWhenAlphaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.setPosition(sf::Vector2f(482, 320)); // put alpha at right boundary
  alpha.move();                              // call to move alpha down which sets justMovedDownToTrue

  alpha.move();
  EXPECT_FALSE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToYPositionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(482, 362));
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_EQ(alpha.getDirection(), -1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.setPosition(sf::Vector2f(482, 320));
  alpha.move();
  EXPECT_TRUE(alpha.hasJustMovedDown());
}

TEST(Alpha, moveAdds42ToYPositionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(300, 320, sprite);

  alpha.setPosition(sf::Vector2f(18, 320));
  alpha.move();
  EXPECT_EQ(alpha.getPosition(), sf::Vector2f(18, 362));
}

TEST(Alpha, moveChangesDirectionWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(300, 320, sprite);

  alpha.changeDirection();
  alpha.setPosition(sf::Vector2f(18, 320));
  alpha.move();
  EXPECT_EQ(alpha.getDirection(), 1);
}

TEST(Alpha, moveSetsJustMovedDownToTrueWhenAlphaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(300, 320, sprite);

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
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.die();

  alpha.resurrect();
  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

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
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);

  alpha.die();

  alpha.reset();
  EXPECT_TRUE(alpha.isAlive());
}

TEST(Alpha, shootSetsPositionOfFirstLaserIfBelowBoardAndAlphaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  MockLaser laser2;
  MockLaser *pLaser2 = &laser2;
  MockLaser laser3;
  MockLaser *pLaser3 = &laser3;
  metroidLasers[0] = pLaser1;
  metroidLasers[1] = pLaser2;
  metroidLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser1, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfSecondLaserIfBelowBoardAndFirstLaserIsOnBoardAndAlphaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  MockLaser laser3;
  MockLaser *pLaser3 = &laser3;
  metroidLasers[0] = pLaser1;
  metroidLasers[1] = pLaser2;
  metroidLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser2, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootSetsPositionOfThirdLaserIfBelowBoardAndFirstAndSecondLasersAreOnBoardAndAlphaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  NiceMock<MockLaser> laser3;
  MockLaser *pLaser3 = &laser3;
  metroidLasers[0] = pLaser1;
  metroidLasers[1] = pLaser2;
  metroidLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 600)));
  ON_CALL(laser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser3, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootDoesNotSetPositionOfAnyLaserIfTheyAreAllOnBoardAndAlphaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  std::vector<ILaser *> metroidLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  NiceMock<MockLaser> laser3;
  MockLaser *pLaser3 = &laser3;
  metroidLasers[0] = pLaser1;
  metroidLasers[1] = pLaser2;
  metroidLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 600)));
  ON_CALL(laser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 300)));

  EXPECT_CALL(laser1, setPosition)
      .Times(0);
  EXPECT_CALL(laser2, setPosition)
      .Times(0);
  EXPECT_CALL(laser3, setPosition)
      .Times(0);
  alpha.shoot(metroidLasers, 0);
}

TEST(Alpha, shootDoesNotSetPositionOfAnyLaserIfRandomNumberIsNot0)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Alpha alpha(200, 320, sprite);
  std::vector<ILaser *> metroidLasers(3);
  MockLaser laser1;
  MockLaser *pLaser1 = &laser1;
  MockLaser laser2;
  MockLaser *pLaser2 = &laser2;
  MockLaser laser3;
  MockLaser *pLaser3 = &laser3;
  metroidLasers[0] = pLaser1;
  metroidLasers[1] = pLaser2;
  metroidLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));
  ON_CALL(laser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser1, setPosition)
      .Times(0);
  EXPECT_CALL(laser2, setPosition)
      .Times(0);
  EXPECT_CALL(laser3, setPosition)
      .Times(0);
  alpha.shoot(metroidLasers, 50);
}
