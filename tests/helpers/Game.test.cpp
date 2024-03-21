#include "../../include/helpers/Game.hpp"
#include "../mockHelpers/game/MockCollision.hpp"
#include "../mockModels/MockBunker.hpp"
#include "../mockModels/MockClock.hpp"
#include "../mockModels/MockGunship.hpp"
#include "../mockModels/MockGunshipLaser.hpp"
#include "../mockModels/MockMetroid.hpp"
#include "../mockModels/MockMetroidLaser.hpp"
#include "../mockModels/MockRidley.hpp"
#include "../mockModels/MockSound.hpp"
#include "../mockModels/MockText.hpp"

using ::testing::NiceMock;

class GameTest : public ::testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  Game game {Game(collision)};
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
  NiceMock<MockGunship> gunship;
  MockGunship *pGunship {&gunship};
  NiceMock<MockGunshipLaser> gunshipLaser;
  MockGunshipLaser *pGunshipLaser {&gunshipLaser};
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
  MockRidley *pRidley {&ridley};
  std::unordered_map<std::string, int> variables {};
  std::unordered_map<std::string, IText*> textObjects {};
  bool isPlaying {false};
  NiceMock<MockSound> titleTheme;
  MockSound *pTitleTheme {&titleTheme};
  NiceMock<MockSound> battleTheme;
  MockSound *pBattleTheme {&battleTheme};
  std::unordered_map<std::string, ISound*> themes {
    {"title", pTitleTheme},
    {"battle", pBattleTheme},
  };
  NiceMock<MockClock> movementClock;
};

TEST_F(GameTest, checkForCollisionsChecksGunshipLaserBunkerCollision)
{
  EXPECT_CALL(collision, checkGunshipLaserBunkerCollision)
    .Times(1);
  game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
}

TEST_F(GameTest, checkForCollisionsChecksGunshipLaserMetroidCollision)
{
  EXPECT_CALL(collision, checkGunshipLaserMetroidCollision)
    .Times(1);
  game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
}

TEST_F(GameTest, checkForCollisionsChecksGunshipLaserRidleyCollision)
{
  EXPECT_CALL(collision, checkGunshipLaserRidleyCollision)
    .Times(1);
  game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
}

TEST_F(GameTest, checkForCollisionsChecksGunshipMetroidLaserCollision)
{
  EXPECT_CALL(collision, checkGunshipMetroidLaserCollision)
    .Times(1);
  game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
}

TEST_F(GameTest, checkForCollisionsChecksMetroidLaserBunkerCollision)
{
  EXPECT_CALL(collision, checkMetroidLaserBunkerCollision(metroidLasers, bunkers))
    .Times(1);
  game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
}

TEST_F(GameTest, playSetsIsPlayingToTrue)
{
  game.play(isPlaying, themes, movementClock);
  EXPECT_TRUE(isPlaying);
}

TEST_F(GameTest, playStopsTheTitleTheme)
{
  EXPECT_CALL(titleTheme, stop())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}

TEST_F(GameTest, playPlaysTheBattleTheme)
{
  EXPECT_CALL(battleTheme, play())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}

TEST_F(GameTest, playRestartsTheClock)
{
  EXPECT_CALL(movementClock, restart())
      .Times(1);
  game.play(isPlaying, themes, movementClock);
}
