#include "../../include/models/Gamma.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockSound.hpp"

using ::testing::NiceMock;

TEST(Gamma, setsPointsToTenUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MockSound deathSound;
  MockSound *pDeathSound {&deathSound};
  Gamma gamma(200, 320, pSprite, pDeathSound);

  EXPECT_EQ(gamma.getPoints(), 10);
}
