#include "../../include/models/invaders.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Octopus, hasAWidthClassMemberOf72)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getWidth(), 72);
}

TEST(Octopus, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getHeight(), 48);
}

TEST(Octopus, hasAPointsClassMemberOf10)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPoints(), 10);
}

TEST(Octopus, hasAnOriginalPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, hasABoolClassMemberCalledAliveSetToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_TRUE(octopus.isAlive());
}

TEST(Octopus, hasADirectionClassMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_EQ(octopus.getDirection(), 1);
}

TEST(Octopus, hasAJustMovedDownMemberSetToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  EXPECT_FALSE(octopus.hasJustMovedDown());
}

TEST(Octopus, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Octopus octopus(200, 320, pSprite);
}

TEST(Octopus, setPositionChangesPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(500, 920));
}

TEST(Octopus, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Octopus octopus(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  octopus.setPosition(sf::Vector2f(500, 920));
}

TEST(Octopus, drawCallsDrawOnTheSpriteClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  octopus.draw(window);
}

TEST(Octopus, dieChangesAliveClassMemberToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.die();
  EXPECT_FALSE(octopus.isAlive());
}

TEST(Octopus, changeDirectionMultipliesDirectionByMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.changeDirection();
  EXPECT_EQ(octopus.getDirection(), -1);
}

TEST(Octopus, moveAdds14Point1ToXPositionWhenDirectionIs1AndOctopusIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Octopus, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndOctopusIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.changeDirection();
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Octopus, moveAdds14Point1ToXPositionWhenOctopusIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320)); // put octopus at left boundary
  octopus.changeDirection();                  // octopus would be moving left so need to mimic that direction
  octopus.move();                             // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Octopus, moveTakesAway14Point1FromXPositionWhenOctopusIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320)); // put octopus at right boundary
  octopus.move();                              // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Octopus, moveSetsJustMovedDownToFalseWhenOctopusIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320)); // put octopus at left boundary
  octopus.move();                             // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_FALSE(octopus.hasJustMovedDown());
}

TEST(Octopus, moveSetsJustMovedDownToFalseWhenOctopusIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320)); // put octopus at right boundary
  octopus.move();                              // call to move octopus down which sets justMovedDownToTrue

  octopus.move();
  EXPECT_FALSE(octopus.hasJustMovedDown());
}

TEST(Octopus, moveAdds42ToYPositionWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(482, 362));
}

TEST(Octopus, moveChangesDirectionWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_EQ(octopus.getDirection(), -1);
}

TEST(Octopus, moveSetsJustMovedDownToTrueWhenOctopusIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(482, 320));
  octopus.move();
  EXPECT_TRUE(octopus.hasJustMovedDown());
}

TEST(Octopus, moveAdds42ToYPositionWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(18, 362));
}

TEST(Octopus, moveChangesDirectionWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(300, 320, sprite);

  octopus.changeDirection();
  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_EQ(octopus.getDirection(), 1);
}

TEST(Octopus, moveSetsJustMovedDownToTrueWhenOctopusIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(300, 320, sprite);

  octopus.setPosition(sf::Vector2f(18, 320));
  octopus.move();
  EXPECT_TRUE(octopus.hasJustMovedDown());
}

TEST(Octopus, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Octopus octopus(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  octopus.move();
}

TEST(Octopus, resurrectSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.die();

  octopus.resurrect();
  EXPECT_TRUE(octopus.isAlive());
}

TEST(Octopus, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.setPosition(sf::Vector2f(900, 1100));

  octopus.reset();
  EXPECT_EQ(octopus.getPosition(), sf::Vector2f(200, 320));
}

TEST(Octopus, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Octopus octopus(200, 320, pSprite);

  octopus.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  octopus.reset();
}

TEST(Octopus, resetSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);

  octopus.die();

  octopus.reset();
  EXPECT_TRUE(octopus.isAlive());
}

TEST(Octopus, shootSetsPositionOfFirstLaserIfBelowBoardAndOctopusIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);
  std::vector<ILaser *> invaderLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  MockLaser laser2;
  MockLaser *pLaser2 = &laser2;
  MockLaser laser3;
  MockLaser *pLaser3 = &laser3;
  invaderLasers[0] = pLaser1;
  invaderLasers[1] = pLaser2;
  invaderLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser1, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  octopus.shoot(invaderLasers);
}

TEST(Octopus, shootSetsPositionOfSecondLaserIfBelowBoardAndFirstLaserIsOnBoardAndOctopusIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);
  std::vector<ILaser *> invaderLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  MockLaser laser3;
  MockLaser *pLaser3 = &laser3;
  invaderLasers[0] = pLaser1;
  invaderLasers[1] = pLaser2;
  invaderLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser2, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  octopus.shoot(invaderLasers);
}

TEST(Octopus, shootSetsPositionOfThirdLaserIfBelowBoardAndFirstAndSecondLasersAreOnBoardAndOctopusIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);
  std::vector<ILaser *> invaderLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  NiceMock<MockLaser> laser3;
  MockLaser *pLaser3 = &laser3;
  invaderLasers[0] = pLaser1;
  invaderLasers[1] = pLaser2;
  invaderLasers[2] = pLaser3;

  ON_CALL(laser1, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 900)));
  ON_CALL(laser2, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 600)));
  ON_CALL(laser3, getPosition())
      .WillByDefault(Return(sf::Vector2f(120, 1344)));

  EXPECT_CALL(laser3, setPosition(sf::Vector2f(227, 368)))
      .Times(1);
  octopus.shoot(invaderLasers);
}

TEST(Octopus, shootDoesNotSetPositionOfAnyLaserIfTheyAreAllOnBoardAndOctopusIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Octopus octopus(200, 320, sprite);
  std::vector<ILaser *> invaderLasers(3);
  NiceMock<MockLaser> laser1;
  MockLaser *pLaser1 = &laser1;
  NiceMock<MockLaser> laser2;
  MockLaser *pLaser2 = &laser2;
  NiceMock<MockLaser> laser3;
  MockLaser *pLaser3 = &laser3;
  invaderLasers[0] = pLaser1;
  invaderLasers[1] = pLaser2;
  invaderLasers[2] = pLaser3;

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
  octopus.shoot(invaderLasers);
}
