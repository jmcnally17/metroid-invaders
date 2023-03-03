#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Gamma, hasAWidthClassMemberOf66)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getWidth(), 72);
}

TEST(Gamma, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getHeight(), 48);
}

TEST(Gamma, hasAPointsClassMemberOf20)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getPoints(), 10);
}

TEST(Gamma, hasAnOriginalPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Gamma, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(200, 320));
}

TEST(Gamma, hasABoolClassMemberCalledAliveSetToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, hasADirectionClassMemberInitiallySetTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getDirection(), 1);
}

TEST(Gamma, hasAJustMovedDownMemberSetToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

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
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

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
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  gamma.draw(window);
}

TEST(Gamma, dieChangesAliveClassMemberToFalse)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.die();
  EXPECT_FALSE(gamma.isAlive());
}

TEST(Gamma, changeDirectionMultipliesDirectionByMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.changeDirection();
  EXPECT_EQ(gamma.getDirection(), -1);
}

TEST(Gamma, moveAdds14Point1ToXPositionWhenDirectionIs1AndGammaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Gamma, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndGammaIsNotAtSideBoundary)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.changeDirection();
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Gamma, moveAdds14Point1ToXPositionWhenGammaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(300, 320, pSprite);

  gamma.setPosition(sf::Vector2f(18, 320)); // put gamma at left boundary
  gamma.changeDirection();                  // gamma would be moving left so need to mimic that direction
  gamma.move();                             // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Gamma, moveTakesAway14Point1FromXPositionWhenGammaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(482, 320)); // put gamma at right boundary
  gamma.move();                              // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Gamma, moveSetsJustMovedDownToFalseWhenGammaIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(300, 320, pSprite);

  gamma.setPosition(sf::Vector2f(18, 320)); // put gamma at left boundary
  gamma.move();                             // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_FALSE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveSetsJustMovedDownToFalseWhenGammaIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(482, 320)); // put gamma at right boundary
  gamma.move();                              // call to move gamma down which sets justMovedDownToTrue

  gamma.move();
  EXPECT_FALSE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveAdds42ToYPositionWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(482, 362));
}

TEST(Gamma, moveChangesDirectionWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_EQ(gamma.getDirection(), -1);
}

TEST(Gamma, moveSetsJustMovedDownToTrueWhenGammaIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.setPosition(sf::Vector2f(482, 320));
  gamma.move();
  EXPECT_TRUE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveAdds42ToYPositionWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(300, 320, pSprite);

  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_EQ(gamma.getPosition(), sf::Vector2f(18, 362));
}

TEST(Gamma, moveChangesDirectionWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(300, 320, pSprite);

  gamma.changeDirection();
  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_EQ(gamma.getDirection(), 1);
}

TEST(Gamma, moveSetsJustMovedDownToTrueWhenGammaIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(300, 320, pSprite);

  gamma.setPosition(sf::Vector2f(18, 320));
  gamma.move();
  EXPECT_TRUE(gamma.hasJustMovedDown());
}

TEST(Gamma, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)))
      .Times(1);
  gamma.move();
}

TEST(Gamma, resurrectSetsAliveBackToTrue)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.die();

  gamma.resurrect();
  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

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
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  gamma.die();

  gamma.reset();
  EXPECT_TRUE(gamma.isAlive());
}

TEST(Gamma, shootSetsPositionOfFirstMetroidLaserIfBelowBoardAndGammaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
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

  EXPECT_CALL(metroidLaser1, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootSetsPositionOfSecondMetroidLaserIfBelowBoardAndFirstMetroidLaserIsOnBoardAndGammaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
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

  EXPECT_CALL(metroidLaser2, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootSetsPositionOfThirdMetroidLaserIfBelowBoardAndFirstAndSecondMetroidLasersAreOnBoardAndGammaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
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

  EXPECT_CALL(metroidLaser3, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootDoesNotSetPositionOfAnyMetroidLaserIfTheyAreAllOnBoardAndGammaIsAlive)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
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
  gamma.shoot(metroidLasers, 0);
}

TEST(Gamma, shootDoesNotSetPositionOfAnyMetroidLaserIfRandomNumberIsNot0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);
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
  gamma.shoot(metroidLasers, 50);
}
