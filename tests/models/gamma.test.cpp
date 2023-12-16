#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;

TEST(Gamma, hasAPointsClassMemberOf10)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Gamma gamma(200, 320, pSprite);

  EXPECT_EQ(gamma.getPoints(), 10);
}
