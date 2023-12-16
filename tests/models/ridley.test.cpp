#include "../../include/models/ridley.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class RidleyTest : public testing::Test
{
protected:
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite {&rightSprite};
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite {&leftSprite};
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound {&movementSound};
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound {&deathSound};
  Ridley ridley {Ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound)};
  MockRenderWindow window;
  sf::FloatRect spriteBounds {sf::FloatRect(sf::Vector2f(200, 600), sf::Vector2f(96, 42))};
};

TEST_F(RidleyTest, setsPositionOnSpriteClassMembers)
{
  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);
}

TEST_F(RidleyTest, getPositionReturnsSpritePosition)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, getPosition())
      .Times(1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST_F(RidleyTest, hasAPointsMemberOf150)
{
  EXPECT_EQ(ridley.getPoints(), 150);
}

TEST_F(RidleyTest, hasADirectionMemberInitiallySetToMinus1)
{
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, setsLoopOnMovementSoundToTrue)
{
  EXPECT_CALL(movementSound, setLoop(true))
      .Times(1);
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);
}

TEST_F(RidleyTest, setPositionUpdatesSpritePositions)
{
  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  ridley.setPosition(sf::Vector2f(500, 920));
}

TEST_F(RidleyTest, changeDirectionSwitchesDirectionTo1)
{
  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST_F(RidleyTest, changeDirectionSwitchesDirectionBackToMinus1)
{
  ridley.changeDirection(); // Set direction to 1

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, drawCallsDrawOnLeftSpriteClassMemberWhenOnTheBoardAndDirectionIsMinus1)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST_F(RidleyTest, drawCallsDrawOnRightSpriteClassMemberWhenOnTheBoardAndDirectionIs1)
{
  ridley.changeDirection(); // set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST_F(RidleyTest, drawDoesNotCallDrawOnSpriteClassMemberWhenLeftOfTheBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST_F(RidleyTest, drawDoesNotCallDrawOnTheSpriteClassMemberWhenRightOfTheBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST_F(RidleyTest, resetSetsSpritePositionsBackToOriginalPosition)
{
  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  ridley.reset();
}

TEST_F(RidleyTest, resetSetsDirectionBackToMinus1)
{
  ridley.changeDirection(); // Set direction to 1

  ridley.reset();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, moveTakesAway1Point6FromSpriteXPositionsWhenDirectionIsMinus1AndIsOnTheBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  ridley.move();
}

TEST_F(RidleyTest, moveAdds1Point6ToSpriteXPositionsWhenDirectionIs1AndIsOnTheBoard)
{
  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  ridley.move();
}

TEST_F(RidleyTest, moveDoesNotChangePositionWhenRidleyIsLeftOfTheBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.move();
}

TEST_F(RidleyTest, moveDoesNotChangePositionWhenRidleyIsRightOfTheBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.move();
}

TEST_F(RidleyTest, spawnChangesDirectionTo1)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST_F(RidleyTest, spawnChangesDirectionToMinus1)
{
  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, spawnAdds1Point6ToSpriteXPositionsWhenRidleyIsLeftOfBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  ridley.spawn(0);
}

TEST_F(RidleyTest, spawnTakesAway1Point6FromSpriteXPositionsWhenRidleyIsRightOfBoard)
{
  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  ridley.spawn(0);
}

TEST_F(RidleyTest, spawnPlaysTheMovementSound)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(movementSound, play())
      .Times(1);
  ridley.spawn(0);
}

TEST_F(RidleyTest, spawnDoesNotSpawnRidleyWhenNotAtLeftOrRightEdgeOfBoard)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(movementSound, play())
      .Times(0);
  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, spawnDoesNotSpawnRidleyWhenRandomNumberIsNot0)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(movementSound, play())
      .Times(0);
  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.spawn(50);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, stopMovementSoundIfPlayingStopsMovementSoundIfItIsPlaying)
{
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfPlaying();
}

TEST_F(RidleyTest, stopMovementSoundIfPlayingDoesNotStopMovementSoundIfItIsNotPlaying)
{
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Stopped));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfPlaying();
}

TEST_F(RidleyTest, stopMovementSoundIfAtSideOfWindowStopsMovementSoundIfAtLeftSideAndPlaying)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST_F(RidleyTest, stopMovementSoundIfAtSideOfWindowStopsMovementSoundIfAtRightSideAndPlaying)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST_F(RidleyTest, stopMovementSoundIfAtSideOfWindowDoesNotStopMovementSoundIfInTheWindowAndPlaying)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST_F(RidleyTest, stopMovementSoundIfAtSideOfWindowDoesNotStopMovementSoundIfNotPlaying)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Stopped));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST_F(RidleyTest, dieSetsSpritePositionsToRightOfWindowWhenDirectionIs1)
{
  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(1536, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(1536, 200)))
      .Times(1);
  ridley.die();
}

TEST_F(RidleyTest, dieSetsSpritePositionsToLeftOfWindowWhenDirectionIsMinus1)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  ridley.die();
}

TEST_F(RidleyTest, dieStopsTheMovementSound)
{
  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.die();
}

TEST_F(RidleyTest, diePlaysTheDeathSound)
{
  EXPECT_CALL(deathSound, play())
      .Times(1);
  ridley.die();
}

TEST_F(RidleyTest, getGlobalBoundsReturnsSpriteGlobalBounds)
{
  ON_CALL(rightSprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));

  EXPECT_CALL(rightSprite, getGlobalBounds())
      .Times(1);
  EXPECT_EQ(ridley.getGlobalBounds(), spriteBounds);
}

TEST_F(RidleyTest, intersectsGetsTheSpriteGlobalBounds)
{
  sf::FloatRect rectangle;

  EXPECT_CALL(rightSprite, getGlobalBounds())
      .Times(1);
  ridley.intersects(rectangle);
}

TEST_F(RidleyTest, intersectsReturnsTrueWhenCollidingWithARectangle)
{
  ON_CALL(rightSprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(220, 630), sf::Vector2f(6, 24));

  EXPECT_TRUE(ridley.intersects(rectangle));
}

TEST_F(RidleyTest, intersectsReturnsFalseWhenNotCollidingWithARectangle)
{
  ON_CALL(rightSprite, getGlobalBounds())
      .WillByDefault(Return(spriteBounds));
  sf::FloatRect rectangle(sf::Vector2f(120, 800), sf::Vector2f(6, 24));

  EXPECT_FALSE(ridley.intersects(rectangle));
}
