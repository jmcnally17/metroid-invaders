#include "../../include/models/Ridley.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockSound.hpp"
#include "../mockModels/MockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class RidleyTest : public testing::Test
{
protected:
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite {&rightSprite};
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound {&deathSound};
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite {&leftSprite};
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound {&movementSound};
  Ridley ridley {Ridley(pRightSprite, pDeathSound, pLeftSprite, pMovementSound)};
  MockRenderWindow window;
};

TEST_F(RidleyTest, setsPositionOnSpritesUponInstantiation)
{
  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  Ridley ridley {Ridley(pRightSprite, pDeathSound, pLeftSprite, pMovementSound)};
}

TEST_F(RidleyTest, setsSpeedUponInstantiation)
{
  EXPECT_FLOAT_EQ(ridley.getSpeed(), 1.6);
}

TEST_F(RidleyTest, setsPointsUponInstantiation)
{
  EXPECT_EQ(ridley.getPoints(), 150);
}

TEST_F(RidleyTest, setsDirectionUponInstantiation)
{
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, setsLoopOnMovementSoundToTrue)
{
  EXPECT_CALL(movementSound, setLoop(true))
      .Times(1);
  Ridley ridley(pRightSprite, pDeathSound, pLeftSprite, pMovementSound);
}

TEST_F(RidleyTest, setPositionUpdatesSpritePositions)
{
  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  ridley.setPosition(sf::Vector2f(500, 920));
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

TEST_F(RidleyTest, spawnChangesDirectionToOne)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST_F(RidleyTest, spawnChangesDirectionBackToMinusOne)
{
  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST_F(RidleyTest, spawnShiftsSpritesToTheRightWhenAtLeftBoundary)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  ridley.spawn(0);
}

TEST_F(RidleyTest, spawnShiftsSpritesToTheLeftWhenAtRightBoundary)
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

TEST_F(RidleyTest, spawnDoesNotSpawnRidleyWhenNotAtLeftOrRightBoundary)
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

TEST_F(RidleyTest, spawnDoesNotSpawnRidleyWhenRandomNumberIsNotZero)
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

TEST_F(RidleyTest, moveMovesSpritesToTheLeftWhenDirectionIsMinusOneAndNotAtLeftOrRightBoundary)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  ridley.move();
}

TEST_F(RidleyTest, moveMovesSpritesToTheRightWhenDirectionIsOneAndNotAtLeftOrRghtBoundary)
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

TEST_F(RidleyTest, moveDoesNotChangePositionWhenAtLeftBoundary)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.move();
}

TEST_F(RidleyTest, moveDoesNotChangePositionWhenAtRightBoundary)
{
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.move();
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

TEST_F(RidleyTest, dieSetsSpritePositionsToRightBoundaryWhenDirectionIsOne)
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

TEST_F(RidleyTest, dieSetsSpritePositionsToLeftBoundaryWhenDirectionIsMinusOne)
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
