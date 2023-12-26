#include "../../include/models/Larva.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockSound.hpp"

using ::testing::NiceMock;

TEST(Larva, setsPointsToThirtyUponInstantiation)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  MockSound deathSound;
  MockSound *pDeathSound {&deathSound};
  Larva larva(200, 320, pSprite, pDeathSound);

  EXPECT_EQ(larva.getPoints(), 30);
}
