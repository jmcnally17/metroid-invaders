#include "../../include/models/ridley.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Ridley, hasAWidthClassMemberOf96)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_EQ(ridley.getWidth(), 96);
}

TEST(Ridley, hasAHeightClassMemberOf42)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_EQ(ridley.getHeight(), 42);
}

TEST(Ridley, setsItsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;
  MockSprite *pSprite = &sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  Ridley ridley(pSprite);
}

TEST(Ridley, hasAPointsMemberOf150)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_EQ(ridley.getPoints(), 150);
}

TEST(Ridley, hasADirectionMemberInitiallySetToMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500, 920));
}

TEST(Ridley, setPositionUpdatesSpritePosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(500, 920)));
  ridley.setPosition(sf::Vector2f(500, 920));
}

TEST(Ridley, drawCallsDrawOnTheSpriteClassMemberWhenOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);
  MockRenderWindow window;

  ridley.setPosition(sf::Vector2f(500, 200));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST(Ridley, drawDoesNotCallDrawOnTheSpriteClassMemberWhenLeftOfTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST(Ridley, drawDoesNotCallDrawOnTheSpriteClassMemberWhenRightOfTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);
  MockRenderWindow window;

  ridley.setPosition(sf::Vector2f(1536, 200));

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST(Ridley, changeDirectionSwitchesDirectionTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, changeDirectionSwitchesDirectionBackToMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.changeDirection(); // Set direction to 1

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(900, 1100));

  ridley.reset();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, resetSetsSpritePositionBackToOriginalPosition)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  ridley.reset();
}

TEST(Ridley, resetSetsDirectionBackToMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.changeDirection(); // Set direction to 1

  ridley.reset();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, moveAdds0Point25ToXPositionWhenDirectionIs1AndIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board
  ridley.changeDirection();                   // Set direction to 1

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500.25, 200));
}

TEST(Ridley, moveTakesAway0Point25ToXPositionWhenDirectionIsMinus1AndIsOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(499.75, 200));
}

TEST(Ridley, moveDoesNotChangePositionWhenRidleyIsLeftOfTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, moveDoesNotChangePositionWhenRidleyIsRightOfTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(1536, 200)); // Put Ridley off the window to the right

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(1536, 200));
}

TEST(Ridley, moveUpdatesSpritePositionWhenOnTheBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(499.75, 200)))
      .Times(1);
  ridley.move();
}

TEST(Ridley, spawnChangesDirectionTo1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, spawnChangesDirectionToMinus1)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.changeDirection(); // Set direction to 1

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, spawnAdds0Point25ToXPositionWhenRidleyIsLeftOfBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.spawn(0);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-95.75, 200));
}

TEST(Ridley, spawnTakesAway0Point25FromXPositionWhenRidleyIsRightOfBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(1536, 200)); // Put Ridley off the window to the right
  ridley.changeDirection();                    // Set direction to 1

  ridley.spawn(0);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(1535.75, 200));
}

TEST(Ridley, spawnDoesNotChangeDirectionOrPositionWhenNotAtLeftOrRightEdgeOfBoard)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.setPosition(sf::Vector2f(500, 200));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500, 200));
}

TEST(Ridley, spawnDoesNotChangeDirectionOrPositionWhenRandomNumberIsNot0)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Ridley ridley(pSprite);

  ridley.spawn(50);
  EXPECT_EQ(ridley.getDirection(), -1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}
