#include "../../../include/helpers/game/LevelManager.hpp"
#include "../../mockModels/MockBunker.hpp"
#include "../../mockModels/MockClock.hpp"
#include "../../mockModels/MockGunship.hpp"
#include "../../mockModels/MockGunshipLaser.hpp"
#include "../../mockModels/MockMetroid.hpp"
#include "../../mockModels/MockMetroidLaser.hpp"
#include "../../mockModels/MockRidley.hpp"
#include "../../mockModels/MockSound.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class LevelManagerTest : public testing::Test
{
protected:
  LevelManager levelManager;
  std::unordered_map<std::string, int> variables {
    {"interval", 105},
    {"level", 5},
    {"soundCounter", 3},
    {"step", 15},
    {"score", 1030},
  };
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  NiceMock<MockMetroidLaser> metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockRidley> ridley;
  NiceMock<MockClock> movementClock;
  bool isPlaying {true};
  bool gameOver {false};
  NiceMock<MockSound> battleTheme;
  MockSound *pBattleTheme {&battleTheme};
  NiceMock<MockSound> creditsTheme;
  MockSound *pCreditsTheme {&creditsTheme};
  std::unordered_map<std::string, ISound*> themes {
    {"battle", pBattleTheme},
    {"credits", pCreditsTheme},
  };
  NiceMock<MockText> scoreText;
  MockText *pScoreText {&scoreText};
  NiceMock<MockText> livesText;
  MockText *pLivesText {&livesText};
  std::unordered_map<std::string, IText*> textObjects {
    {"score", pScoreText},
    {"lives", pLivesText},
  };
  NiceMock<MockGunship> gunship;
  NiceMock<MockGunshipLaser> gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
};

TEST_F(LevelManagerTest, levelUpAdds1ToTheLevelVariable)
{
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["level"], 6);
}

TEST_F(LevelManagerTest, levelUpResetsTheInterval)
{
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["interval"], 665);
}

TEST_F(LevelManagerTest, levelUpResetsTheStepCounter)
{
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(LevelManagerTest, levelUpResetsTheSoundCounter)
{
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST_F(LevelManagerTest, levelUpCallsResurrectOnEachMetroid)
{
  EXPECT_CALL(metroid, resurrect())
      .Times(55);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpChangesDirectionOnMetroidsIfTheyAreMovingLeft)
{
  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(-1));

  EXPECT_CALL(metroid, changeDirection())
      .Times(55);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpDoesNotChangeDirectionOnMetroidsIfTheyAreMovingRight)
{
  ON_CALL(metroid, getDirection())
      .WillByDefault(Return(1));

  EXPECT_CALL(metroid, changeDirection)
      .Times(0);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpSetsNextLevelPositionOnMetroids)
{
  ON_CALL(metroid, getOriginalPosition())
      .WillByDefault(Return(sf::Vector2f(400, 960)));

  EXPECT_CALL(metroid, setPosition(sf::Vector2f(400, 1170)))
      .Times(55);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpResetsTheMetroidLasers)
{
  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpResetsRidley)
{
  EXPECT_CALL(ridley, reset())
      .Times(1);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpStopsRidleyMovementSoundIfPlaying)
{
  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, levelUpRestartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  levelManager.levelUp(variables, metroids, metroidLasers, ridley, movementClock);
}

TEST_F(LevelManagerTest, endGameChangesIsPlayingToFalse)
{
  levelManager.endGame(isPlaying, gameOver, ridley, themes);
  EXPECT_FALSE(isPlaying);
}

TEST_F(LevelManagerTest, endGameChangesGameOverToTrue)
{
  levelManager.endGame(isPlaying, gameOver, ridley, themes);
  EXPECT_TRUE(gameOver);
}

TEST_F(LevelManagerTest, endGameStopsRidleyMovementSoundIfPlaying)
{
  EXPECT_CALL(ridley, stopMovementSoundIfPlaying())
      .Times(1);
  levelManager.endGame(isPlaying, gameOver, ridley, themes);
}

TEST_F(LevelManagerTest, endGameStopsTheBattleTheme)
{
  EXPECT_CALL(battleTheme, stop())
      .Times(1);
  levelManager.endGame(isPlaying, gameOver, ridley, themes);
}

TEST_F(LevelManagerTest, endGamePlaysTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, play())
      .Times(1);
  levelManager.endGame(isPlaying, gameOver, ridley, themes);
}

TEST_F(LevelManagerTest, resetObjectsResetsTheGunship)
{
  EXPECT_CALL(gunship, reset())
      .Times(1);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetObjectsResetsTheGunshipLaser)
{
  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetObjectsResetsTheMetroids)
{
  EXPECT_CALL(metroid, reset())
      .Times(55);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetObjectsResetsMetroidLasers)
{
  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetObjectsResetsRidley)
{
  EXPECT_CALL(ridley, reset())
      .Times(1);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetObjectsResetsTheBunkers)
{
  EXPECT_CALL(bunker, reset())
      .Times(4);
  levelManager.resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
}

TEST_F(LevelManagerTest, resetValuesSetsIsPlayingToTrue)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_TRUE(isPlaying);
}

TEST_F(LevelManagerTest, resetValuesSetsGameOverToFalse)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_FALSE(gameOver);
}

TEST_F(LevelManagerTest, resetValuesResetsClockInterval)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["interval"], 665);
}

TEST_F(LevelManagerTest, resetValuesResetsClockStepCounter)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(LevelManagerTest, resetValuesResetsSoundCounter)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST_F(LevelManagerTest, resetValuesResetsLevel)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["level"], 1);
}

TEST_F(LevelManagerTest, resetValuesResetsScore)
{
  levelManager.resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["score"], 0);
}

TEST_F(LevelManagerTest, resetInformationObjectsUpdatesScoreText)
{
  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  levelManager.resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(LevelManagerTest, resetInformationObjectsUpdatesLivesText)
{
  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  levelManager.resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(LevelManagerTest, resetInformationObjectsStopsTheCreditsTheme)
{
  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  levelManager.resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(LevelManagerTest, resetInformationObjectsPlaysTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  levelManager.resetInformationObjects(textObjects, themes, movementClock);
}

TEST_F(LevelManagerTest, resetInformationObjectsRestartsClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  levelManager.resetInformationObjects(textObjects, themes, movementClock);
}
