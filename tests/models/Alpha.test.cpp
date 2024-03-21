#include "../../include/models/Alpha.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockSound.hpp"

using ::testing::NiceMock;

TEST(Alpha, setsPointsToTwentyUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MockSound deathSound;
  MockSound *pDeathSound {&deathSound};
  Alpha alpha(200, 320, pSprite, pDeathSound);

  EXPECT_EQ(alpha.getPoints(), 20);
}
