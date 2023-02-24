#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Gamma, hasAWidthClassMemberOf72)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getWidth(), 72);
}

TEST(Gamma, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getHeight(), 48);
}

TEST(Gamma, hasAPointsClassMemberOf10)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getPoints(), 10);
}

TEST(Gamma, hasAnOriginalPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Gamma, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(200, 320));
}

TEST(Gamma, hasABoolClassMemberCalledAliveSetToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, hasADirectionClassMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_EQ(gamma.getDirection(), 1);
}

TEST(Gamma, hasAJustMovedDownMemberSetToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  EXPECT_FALSE(gamma.hasJustMovedDown());
}

TEST(Gamma, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Gamma gamma(200, 320, pSprite);
}

TEST(Gamma, setPositionChangesPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(500, 920));
}

TEST(Gamma, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  gamma.setPosition(sf::Vector2f(500, 920));
}

TEST(Gamma, drawCallsDrawOnTheSpriteClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gamma.draw(window);
}

TEST(Gamma, dieChangesAliveClassMemberToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.die();
  EXPECT_FALSE(gamma.isAlive());
}

TEST(Gamma, changeDirectionMultipliesDirectionByMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.changeDirection();
  EXPECT_EQ(gamma.getDirection(), -1);
}

TEST(Gamma, moveAdds14Point1ToXPositionWhenDirectionIs1AndGammaIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Gamma, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndGammaIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.changeDirection();
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Gamma, moveAdds14Point1ToXPositionWhenGammaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(300, 320, sprite);

  gamma.setPosition(sf::Vector2f(18, 320)); // put gamma at left boundary
  gamma.changeDirection();                  // gamma would be moving left so need to mimic that direction
  gamma.move();                             // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Gamma, moveTakesAway14Point1FromXPositionWhenGammaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(482, 320)); // put gamma at right boundary
  gamma.move();                              // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Gamma, moveSetsJustMovedDownToFalseWhenGammaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(300, 320, sprite);

  gamma.setPosition(sf::Vector2f(18, 320)); // put gamma at left boundary
  gamma.move();                             // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_FALSE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveSetsJustMovedDownToFalseWhenGammaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(482, 320)); // put gamma at right boundary
  gamma.move();                              // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_FALSE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveAdds42ToYPositionWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(482, 362));
}

TEST(Gamma, moveChangesDirectionWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_EQ(gamma.getDirection(), -1);
}

TEST(Gamma, moveSetsJustMovedDownToTrueWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_TRUE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveAdds42ToYPositionWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(300, 320, sprite);

  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(18, 362));
}

TEST(Gamma, moveChangesDirectionWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(300, 320, sprite);

  gamma.changeDirection();
  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_EQ(gamma.getDirection(), 1);
}

TEST(Gamma, moveSetsJustMovedDownToTrueWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(300, 320, sprite);

  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_TRUE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  gamma.move();
}

TEST(Gamma, resurrectSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.die();

  gamma.resurrect();
  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.setPosition(sf::Vector2f(900, 1100));

  gamma.reset();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(200, 320));
}

TEST(Gamma, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  gamma.reset();
}

TEST(Gamma, resetSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);

  gamma.die();

  gamma.reset();
  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, shootSetsPositionOfFirstLaserIfBelowBoardAndGammaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
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

  EXPECT_CALL(laser1, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootSetsPositionOfSecondLaserIfBelowBoardAndFirstLaserIsOnBoardAndGammaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
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

  EXPECT_CALL(laser2, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootSetsPositionOfThirdLaserIfBelowBoardAndFirstAndSecondLasersAreOnBoardAndGammaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
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

  EXPECT_CALL(laser3, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootDoesNotSetPositionOfAnyLaserIfTheyAreAllOnBoardAndGammaIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
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
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootDoesNotSetPositionOfAnyLaserIfRandomNumberIsNot0)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Gamma gamma(200, 320, sprite);
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
  gamma.shoot(metroidLasers, 50);
}
