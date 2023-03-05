#include "../../include/models/ridley.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Ridley, hasAWidthClassMemberOf96)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_EQ(ridley.getWidth(), 96);
}

TEST(Ridley, hasAHeightClassMemberOf42)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_EQ(ridley.getHeight(), 42);
}

TEST(Ridley, setsItsOwnPositionMember)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, setsPositionOnSpriteClassMembers)
{
  MockSprite rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
}

TEST(Ridley, hasAPointsMemberOf150)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_EQ(ridley.getPoints(), 150);
}

TEST(Ridley, hasADirectionMemberInitiallySetToMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, setsLoopOnMovementSoundToTrue)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  MockSound movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;

  EXPECT_CALL(movementSound, setLoop(true))
      .Times(1);
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
}

TEST(Ridley, setPositionChangesPosition)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500, 920));
}

TEST(Ridley, setPositionUpdatesSpritePositions)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(500, 920)))
      .Times(1);
  ridley.setPosition(sf::Vector2f(500, 920));
}

TEST(Ridley, drawCallsDrawOnRightSpriteClassMemberWhenOnTheBoardAndDirectionIs1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
  MockRenderWindow window;

  ridley.setPosition(sf::Vector2f(500, 200));
  ridley.changeDirection();

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST(Ridley, drawCallsDrawOnLeftSpriteClassMemberWhenOnTheBoardAndDirectionIsMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
  MockRenderWindow window;

  ridley.setPosition(sf::Vector2f(500, 200));
  ridley.changeDirection();

  EXPECT_CALL(window, draw(testing::Truly([](const sf::Drawable &drawable)
                                          { return true; })))
      .Times(1);
  ridley.draw(window);
}

TEST(Ridley, drawDoesNotCallDrawOnSpriteClassMemberWhenLeftOfTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
  MockRenderWindow window;

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST(Ridley, drawDoesNotCallDrawOnTheSpriteClassMemberWhenRightOfTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);
  MockRenderWindow window;

  ridley.setPosition(sf::Vector2f(1536, 200));

  EXPECT_CALL(window, draw)
      .Times(0);
  ridley.draw(window);
}

TEST(Ridley, changeDirectionSwitchesDirectionTo1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, changeDirectionSwitchesDirectionBackToMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.changeDirection(); // Set direction to 1

  ridley.changeDirection();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, resetSetsPositionBackToOriginalPosition)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(900, 1100));

  ridley.reset();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, resetSetsSpritePositionsBackToOriginalPosition)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(900, 1100));

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  ridley.reset();
}

TEST(Ridley, resetSetsDirectionBackToMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.changeDirection(); // Set direction to 1

  ridley.reset();
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, moveAdds0Point125ToXPositionWhenDirectionIs1AndIsOnTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board
  ridley.changeDirection();                   // Set direction to 1

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500.125, 200));
}

TEST(Ridley, moveTakesAway0Point125ToXPositionWhenDirectionIsMinus1AndIsOnTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(499.875, 200));
}

TEST(Ridley, moveDoesNotChangePositionWhenRidleyIsLeftOfTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, moveDoesNotChangePositionWhenRidleyIsRightOfTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(1536, 200)); // Put Ridley off the window to the right

  ridley.move();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(1536, 200));
}

TEST(Ridley, moveUpdatesSpritePositionsWhenOnTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 200)); // Put Ridley on the board

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(499.875, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(499.875, 200)))
      .Times(1);
  ridley.move();
}

TEST(Ridley, spawnChangesDirectionTo1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), 1);
}

TEST(Ridley, spawnChangesDirectionToMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.changeDirection(); // Set direction to 1

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, spawnAdds0Point125ToXPositionWhenRidleyIsLeftOfBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.spawn(0);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-95.875, 200));
}

TEST(Ridley, spawnTakesAway0Point125FromXPositionWhenRidleyIsRightOfBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(1536, 200)); // Put Ridley off the window to the right
  ridley.changeDirection();                    // Set direction to 1

  ridley.spawn(0);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(1535.875, 200));
}

TEST(Ridley, spawnUpdatesSpritePositions)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-95.875, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-95.875, 200)))
      .Times(1);
  ridley.spawn(0);
}

TEST(Ridley, spawnPlaysTheMovementSound)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  MockSound movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_CALL(movementSound, play())
      .Times(1);
  ridley.spawn(0);
}

TEST(Ridley, spawnDoesNotSpawnRidleyWhenNotAtLeftOrRightEdgeOfBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 200));

  EXPECT_CALL(movementSound, play())
      .Times(0);
  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(500, 200));
}

TEST(Ridley, spawnDoesNotSpawnRidleyWhenRandomNumberIsNot0)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  EXPECT_CALL(movementSound, play())
      .Times(0);
  ridley.spawn(50);
  EXPECT_EQ(ridley.getDirection(), -1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, stopMovementSoundIfPlayingStopsMovementSoundIfItIsPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfPlaying();
}

TEST(Ridley, stopMovementSoundIfPlayingDoesNotStopMovementSoundIfItIsNotPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Stopped));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfPlaying();
}

TEST(Ridley, stopMovementSoundIfAtSideOfWindowStopsMovementSoundIfAtLeftSideAndPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST(Ridley, stopMovementSoundIfAtSideOfWindowStopsMovementSoundIfAtRightSideAndPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(1536, 200));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST(Ridley, stopMovementSoundIfAtSideOfWindowDoesNotStopMovementSoundIfInTheWindowAndPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ridley.setPosition(sf::Vector2f(500, 200));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Playing));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST(Ridley, stopMovementSoundIfAtSideOfWindowDoesNotStopMovementSoundIfNotPlaying)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Stopped));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST(Ridley, dieSetsPositionToRightOfWindowWhenDirectionIs1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);

  ridley.setPosition(sf::Vector2f(500, 200));
  ridley.changeDirection(); // Set direction to 1

  ridley.die();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(1536, 200));
}

TEST(Ridley, dieSetsPositionToLeftOfWindowWhenDirectionIsMinus1)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);

  ridley.setPosition(sf::Vector2f(500, 200));

  ridley.die();
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
}

TEST(Ridley, dieUpdatesSpritePositions)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);

  ridley.setPosition(sf::Vector2f(500, 200));

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(-96, 200)))
      .Times(1);
  ridley.die();
}

TEST(Ridley, dieStopsTheMovementSound)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound = &deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);

  EXPECT_CALL(movementSound, stop())
      .Times(1);
  ridley.die();
}

TEST(Ridley, diePlaysTheDeathSound)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound deathSound;
  MockSound *pDeathSound = &deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, pDeathSound);

  EXPECT_CALL(deathSound, play())
      .Times(1);
  ridley.die();
}
