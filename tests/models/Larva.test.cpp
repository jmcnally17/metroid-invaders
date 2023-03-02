#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Larva, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getWidth(), 48);
}

TEST(Larva, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getHeight(), 48);
}

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

TEST(Larva, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getPosition(), sf::Vector2f(200, 320));
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

TEST(Larva, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Larva larva(200, 320, pSprite);
}

TEST(Larva, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(500, 920));
}

TEST(Larva, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
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

TEST(Larva, moveAdds14Point1ToXPositionWhenDirectionIs1AndLarvaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Larva, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndLarvaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.changeDirection();
  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Larva, moveAdds14Point1ToXPositionWhenLarvaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.setPosition(sf::Vector2f(18, 320)); // put larva at left boundary
  larva.changeDirection();                  // larva would be moving left so need to mimic that direction
  larva.move();                             // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Larva, moveTakesAway14Point1FromXPositionWhenLarvaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(482, 320)); // put larva at right boundary
  larva.move();                              // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Larva, moveSetsJustMovedDownToFalseWhenLarvaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.setPosition(sf::Vector2f(18, 320)); // put larva at left boundary
  larva.move();                             // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_FALSE(larva.hasJustMovedDown());
}

TEST(Larva, moveSetsJustMovedDownToFalseWhenLarvaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(482, 320)); // put larva at right boundary
  larva.move();                              // call to move larva down which sets justMovedDownToTrue

  larva.move();
  EXPECT_FALSE(larva.hasJustMovedDown());
}

TEST(Larva, moveAdds42ToYPositionWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(482, 320));
  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(482, 362));
}

TEST(Larva, moveChangesDirectionWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(482, 320));
  larva.move();
  EXPECT_EQ(larva.getDirection(), -1);
}

TEST(Larva, moveSetsJustMovedDownToTrueWhenLarvaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(482, 320));
  larva.move();
  EXPECT_TRUE(larva.hasJustMovedDown());
}

TEST(Larva, moveAdds42ToYPositionWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.setPosition(sf::Vector2f(18, 320));
  larva.move();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(18, 362));
}

TEST(Larva, moveChangesDirectionWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.changeDirection();
  larva.setPosition(sf::Vector2f(18, 320));
  larva.move();
  EXPECT_EQ(larva.getDirection(), 1);
}

TEST(Larva, moveSetsJustMovedDownToTrueWhenLarvaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(300, 320, pSprite);

  larva.setPosition(sf::Vector2f(18, 320));
  larva.move();
  EXPECT_TRUE(larva.hasJustMovedDown());
}

TEST(Larva, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  larva.move();
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

TEST(Larva, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(900, 1100));

  larva.reset();
  EXPECT_EQ(larva.getPosition(), sf::Vector2f(200, 320));
}

TEST(Larva, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  larva.setPosition(sf::Vector2f(900, 1100));

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

TEST(Larva, shootSetsPositionOfFirstLaserIfBelowBoardAndLarvaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
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

  EXPECT_CALL(laser1, setPosition(sf::Vector2f(215, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootSetsPositionOfSecondLaserIfBelowBoardAndFirstLaserIsOnBoardAndLarvaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
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

  EXPECT_CALL(laser2, setPosition(sf::Vector2f(215, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootSetsPositionOfThirdLaserIfBelowBoardAndFirstAndSecondLasersAreOnBoardAndLarvaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
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

  EXPECT_CALL(laser3, setPosition(sf::Vector2f(215, 368)))
      .Times(1);
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootDoesNotSetPositionOfAnyLaserIfTheyAreAllOnBoardAndLarvaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
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
  larva.shoot(metroidLasers, 0);
}

TEST(Larva, shootDoesNotSetPositionOfAnyLaserIfRandomNumberIsNot0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);
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
  larva.shoot(metroidLasers, 50);
}
