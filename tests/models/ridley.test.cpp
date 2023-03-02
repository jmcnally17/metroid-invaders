#include "../../include/models/ridley.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;

TEST(Ridley, hasAWidthClassMemberOf96)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  EXPECT_EQ(ridley.getWidth(), 96);
}

TEST(Ridley, hasAHeightClassMemberOf42)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  EXPECT_EQ(ridley.getHeight(), 42);
}

TEST(Ridley, setsItsOwnPositionMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

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
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  EXPECT_EQ(ridley.getPoints(), 150);
}

TEST(Ridley, hasADirectionMemberInitiallySetTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, setPositionChangesPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

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

TEST(Ridley, drawCallsDrawOnTheSpriteClassMember)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);
  MockRenderWindow window;

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST(Ridley, changeDirectionSwitchesDirectionToMinus1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, changeDirectionSwitchesDirectionBackTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.changeDirection(); // Set direction to -1

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, resetSetsPositionBackToOriginalPosition)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

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

TEST(Ridley, resetSetsDirectionBackTo1)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.changeDirection(); // Set direction to -1

  ridley.reset();
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, moveAdds0Point25ToXPositionWhenDirectionIs1AndIsOnTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500.25, 200));
}

TEST(Ridley, moveTakesAway0Point25ToXPositionWhenDirectionIsMinus1AndIsOnTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board
  ridley.changeDirection();                   // Set direction to -1

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(499.75, 200));
}

TEST(Ridley, moveDoesNotChangePositionWhenRidleyIsLeftOfTheBoard)
{
  MockSprite *sprite = new NiceMock<MockSprite>();
  Ridley ridley(sprite);

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}
