#include "../../include/models/invaders.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Crab, hasAWidthClassMemberOf66)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getWidth(), 66);
}

TEST(Crab, hasAHeightClassMemberOf48)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getHeight(), 48);
}

TEST(Crab, hasAPointsClassMemberOf20)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getPoints(), 20);
}

TEST(Crab, hasAnOriginalPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getOriginalPosition(), sf::Vector2f(200, 320));
}

TEST(Crab, setsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getPosition(), sf::Vector2f(200, 320));
}

TEST(Crab, hasABoolClassMemberCalledAliveSetToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_TRUE(crab.isAlive());
}

TEST(Crab, hasADirectionClassMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_EQ(crab.getDirection(), 1);
}

TEST(Crab, hasAJustMovedDownMemberSetToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  EXPECT_FALSE(crab.hasJustMovedDown());
}

TEST(Crab, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Crab crab(200, 320, pSprite);
}

TEST(Crab, setPositionChangesPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(500, 920));
}

TEST(Crab, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Crab crab(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  crab.setPosition(sf::Vector2f(500, 920));
}

TEST(Crab, drawCallsDrawOnTheSpriteClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  crab.draw(window);
}

TEST(Crab, dieChangesAliveClassMemberToFalse)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.die();
  EXPECT_FALSE(crab.isAlive());
}

TEST(Crab, changeDirectionMultipliesDirectionByMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.changeDirection();
  EXPECT_EQ(crab.getDirection(), -1);
}

TEST(Crab, moveAdds14Point1ToXPositionWhenDirectionIs1AndCrabIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(214.1, 320));
}

TEST(Crab, moveTakesAway14Point1FromXPositionWhenDirectionIsMinus1AndCrabIsNotAtSideBoundary)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.changeDirection();
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(185.9, 320));
}

TEST(Crab, moveAdds14Point1ToXPositionWhenCrabIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(300, 320, sprite);

  crab.setPosition(sf::Vector2f(18, 320)); // put crab at left boundary
  crab.changeDirection();                  // crab would be moving left so need to mimic that direction
  crab.move();                             // call to move crab down which sets justMovedDownToTrue

  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(32.1, 362));
}

TEST(Crab, moveTakesAway14Point1FromXPositionWhenCrabIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320)); // put crab at right boundary
  crab.move();                              // call to move crab down which sets justMovedDownToTrue

  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(467.9, 362));
}

TEST(Crab, moveSetsJustMovedDownToFalseWhenCrabIsAtLeftBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(300, 320, sprite);

  crab.setPosition(sf::Vector2f(18, 320)); // put crab at left boundary
  crab.move();                             // call to move crab down which sets justMovedDownToTrue

  crab.move();
  EXPECT_FALSE(crab.hasJustMovedDown());
}

TEST(Crab, moveSetsJustMovedDownToFalseWhenCrabIsAtRightBoundaryAndJustMovedDownIsTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320)); // put crab at right boundary
  crab.move();                              // call to move crab down which sets justMovedDownToTrue

  crab.move();
  EXPECT_FALSE(crab.hasJustMovedDown());
}

TEST(Crab, moveAdds42ToYPositionWhenCrabIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320));
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(482, 362));
}

TEST(Crab, moveChangesDirectionWhenCrabIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320));
  crab.move();
  EXPECT_EQ(crab.getDirection(), -1);
}

TEST(Crab, moveSetsJustMovedDownToTrueWhenCrabIsAtRightSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(482, 320));
  crab.move();
  EXPECT_TRUE(crab.hasJustMovedDown());
}

TEST(Crab, moveAdds42ToYPositionWhenCrabIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(300, 320, sprite);

  crab.setPosition(sf::Vector2f(18, 320));
  crab.move();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(18, 362));
}

TEST(Crab, moveChangesDirectionWhenCrabIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(300, 320, sprite);

  crab.changeDirection();
  crab.setPosition(sf::Vector2f(18, 320));
  crab.move();
  EXPECT_EQ(crab.getDirection(), 1);
}

TEST(Crab, moveSetsJustMovedDownToTrueWhenCrabIsAtLeftSideBoundaryAndHasNotJustMovedDown)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(300, 320, sprite);

  crab.setPosition(sf::Vector2f(18, 320));
  crab.move();
  EXPECT_TRUE(crab.hasJustMovedDown());
}

TEST(Crab, moveUpdatesPositionOnSpriteMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Crab crab(200, 320, pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(214.1, 320)));
  crab.move();
}

TEST(Crab, resurrectSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.die();

  crab.resurrect();
  EXPECT_TRUE(crab.isAlive());
}

TEST(Crab, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.setPosition(sf::Vector2f(900, 1100));

  crab.reset();
  EXPECT_EQ(crab.getPosition(), sf::Vector2f(200, 320));
}

TEST(Crab, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Crab crab(200, 320, pSprite);

  crab.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  crab.reset();
}

TEST(Crab, resetSetsAliveBackToTrue)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);

  crab.die();

  crab.reset();
  EXPECT_TRUE(crab.isAlive());
}

TEST(crab, shootSetsPositionOfFirstLaserIfBelowBoardAndCrabIsAlive)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Crab crab(200, 320, sprite);
  std::vector<ILaser *> invaderLasers(3);
  MockLaser laser1;
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

  EXPECT_CALL(laser1, setPosition(sf::Vector2f(224, 368)))
      .Times(1);
  crab.shoot(invaderLasers);
}
