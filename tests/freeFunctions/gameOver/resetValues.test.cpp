#include <gtest/gtest.h>
#include "../../../include/GameOver.hpp"

class ResetValuesTest : public testing::Test
{
protected:
  bool isPlaying {false};
  bool gameOver {true};
  std::unordered_map<std::string, int> variables {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };
};

TEST_F(ResetValuesTest, setsIsPlayingToTrue)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_TRUE(isPlaying);
}

TEST_F(ResetValuesTest, setsGameOverToFalse)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_FALSE(gameOver);
}

TEST_F(ResetValuesTest, resetsClockInterval)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["interval"], 665);
}

TEST_F(ResetValuesTest, resetsClockStepCounter)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["step"], 1);
}

TEST_F(ResetValuesTest, resetsSoundCounter)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST_F(ResetValuesTest, resetsLevel)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["level"], 1);
}

TEST_F(ResetValuesTest, resetsScore)
{
  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["score"], 0);
}
