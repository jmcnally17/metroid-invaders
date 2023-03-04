#include <gtest/gtest.h>
#include "../../../include/title.hpp"

TEST(play, setsIsPlayingToTrue)
{
  bool isPlaying = false;

  play(isPlaying);
  EXPECT_TRUE(isPlaying);
}
