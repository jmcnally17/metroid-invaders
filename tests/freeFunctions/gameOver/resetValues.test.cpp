#include <gtest/gtest.h>
#include "../../../include/gameOver.hpp"

TEST(resetValues, setsIsPlayingToTrue)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_TRUE(isPlaying);
}

TEST(resetValues, setsGameOverToFalse)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_FALSE(gameOver);
}

TEST(resetValues, resetsClockInterval)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["interval"], 665);
}

TEST(resetValues, resetsClockStepCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["step"], 1);
}

TEST(resetValues, resetsSoundCounter)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["soundCounter"], 0);
}

TEST(resetValues, resetsLevel)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["level"], 1);
}

TEST(resetValues, resetsScore)
{
  bool isPlaying = false;
  bool gameOver = true;
  std::unordered_map<std::string, int> variables = {
    {"soundCounter", 3},
    {"interval", 105},
    {"step", 8},
    {"level", 6},
    {"score", 1030},
  };

  resetValues(isPlaying, gameOver, variables);
  EXPECT_EQ(variables["score"], 0);
}
