#include "../../include/models/ridley.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockSound.hpp"
#include "../mockModels/mockRenderWindow.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(Ridley, setsPositionOnSpriteClassMembers)
{
  MockSprite rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  MockSprite leftSprite;
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

TEST(Ridley, getPositionReturnsSpritePosition)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, getPosition())
      .Times(1);
  EXPECT_EQ(ridley.getPosition(), sf::Vector2f(-96, 200));
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

  ridley.changeDirection();
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

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

TEST(Ridley, moveAdds1Point6ToSpriteXPositionsWhenDirectionIs1AndIsOnTheBoard)
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
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  ridley.move();
}

TEST(Ridley, moveTakesAway1Point6FromSpriteXPositionsWhenDirectionIsMinus1AndIsOnTheBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  ridley.move();
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
  ridley.move();
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(rightSprite, move)
      .Times(0);
  EXPECT_CALL(leftSprite, move)
      .Times(0);
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

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
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  ridley.spawn(0);
  EXPECT_EQ(ridley.getDirection(), -1);
}

TEST(Ridley, spawnAdds1Point6ToSpriteXPositionsWhenRidleyIsLeftOfBoard)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(1.6, 0)))
      .Times(1);
  ridley.spawn(0);
}

TEST(Ridley, spawnTakesAway1Point6FromSpriteXPositionsWhenRidleyIsRightOfBoard)
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
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));

  EXPECT_CALL(rightSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  EXPECT_CALL(leftSprite, move(sf::Vector2f(-1.6, 0)))
      .Times(1);
  ridley.spawn(0);
}

TEST(Ridley, spawnPlaysTheMovementSound)
{
  NiceMock<MockSprite> rightSprite;
  MockSprite *pRightSprite = &rightSprite;
  NiceMock<MockSprite> leftSprite;
  MockSprite *pLeftSprite = &leftSprite;
  NiceMock<MockSound> movementSound;
  MockSound *pMovementSound = &movementSound;
  MockSound *deathSound;
  Ridley ridley(pRightSprite, pLeftSprite, pMovementSound, deathSound);

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));

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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(1536, 200)));
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(-96, 200)));
  ON_CALL(movementSound, getStatus())
      .WillByDefault(Return(sf::Sound::Stopped));

  EXPECT_CALL(movementSound, stop())
      .Times(0);
  ridley.stopMovementSoundIfAtSideOfWindow();
}

TEST(Ridley, dieSetsSpritePositionsToRightOfWindowWhenDirectionIs1)
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

  ridley.changeDirection(); // Set direction to 1
  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

  EXPECT_CALL(rightSprite, setPosition(sf::Vector2f(1536, 200)))
      .Times(1);
  EXPECT_CALL(leftSprite, setPosition(sf::Vector2f(1536, 200)))
      .Times(1);
  ridley.die();
}

TEST(Ridley, dieSetsSpritePositionsToLeftOfWindowWhenDirectionIsMinus1)
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

  ON_CALL(rightSprite, getPosition())
      .WillByDefault(Return(sf::Vector2f(500, 200)));

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
