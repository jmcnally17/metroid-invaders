#include <vector>
#include "../../../include/gameOver.hpp"
#include "../../mockModels/mockGunship.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockMetroid.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockBunker.hpp"
#include "../../mockModels/mockText.hpp"
#include "../../mockModels/mockSound.hpp"
#include "../../mockModels/mockClock.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(playAgain, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_TRUE(isPlaying);
}

TEST(playAgain, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_FALSE(gameOver);
}

TEST(playAgain, resetsTheGunship)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(gunship, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsTheGunshipLaser)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  MockLaser gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsTheMetroids)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  MockMetroid metroid;
  MockMetroid *pMetroid = &metroid;
  std::vector<std::vector<IMetroid *>> metroids(2);
  for (int i = 0; i < 2; i++)
  {
    std::vector<IMetroid *> metroidRow(6);
    for (int j = 0; j < 6; j++)
    {
      metroidRow[j] = pMetroid;
    }
    metroids[i] = metroidRow;
  }
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroid, reset())
      .Times(12);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsMetroidLasers)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  MockLaser metroidLaser;
  MockLaser *pMetroidLaser = &metroidLaser;
  std::vector<ILaser *> metroidLasers(3);
  for (int i = 0; i < 3; i++)
  {
    metroidLasers[i] = pMetroidLaser;
  }
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsRidley)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  MockRidley ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(ridley, reset())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsTheBunkers)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  MockBunker bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(bunker, reset())
      .Times(4);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(interval, 665);
}

TEST(playAgain, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(step, 1);
}

TEST(playAgain, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(soundCounter, 0);
}

TEST(playAgain, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(level, 1);
}

TEST(playAgain, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
  EXPECT_EQ(score, 0);
}

TEST(playAgain, updatesScoreText)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  MockText scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(scoreText, setString("Score: 0"))
      .Times(1);
  EXPECT_CALL(scoreText, setPosition(sf::Vector2f(20, 0)))
      .Times(1);
  EXPECT_CALL(scoreText, setOrigin(0, 0))
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, updatesLivesText)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  MockText livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  ON_CALL(gunship, getLives())
      .WillByDefault(Return(3));

  EXPECT_CALL(livesText, setString("Lives: 3"))
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, stopsTheCreditsTheme)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  MockSound creditsTheme;
  NiceMock<MockSound> battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(creditsTheme, stop())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, playsTheBattleTheme)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  MockSound battleTheme;
  NiceMock<MockClock> clock;

  EXPECT_CALL(battleTheme, play())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}

TEST(playAgain, restartsClock)
{
  bool isPlaying = false;
  bool gameOver = true;
  NiceMock<MockGunship> gunship;
  NiceMock<MockLaser> gunshipLaser;
  std::vector<std::vector<IMetroid *>> metroids;
  std::vector<ILaser *> metroidLasers;
  NiceMock<MockRidley> ridley;
  std::vector<IBunker *> bunkers;
  int interval = 105;
  int step = 8;
  int soundCounter = 3;
  int level = 6;
  int score = 1030;
  NiceMock<MockText> scoreText;
  NiceMock<MockText> livesText;
  NiceMock<MockSound> creditsTheme;
  NiceMock<MockSound> battleTheme;
  MockClock clock;

  EXPECT_CALL(clock, restart())
      .Times(1);
  playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers, interval, step, soundCounter, level, score, scoreText, livesText, creditsTheme, battleTheme, clock);
}
