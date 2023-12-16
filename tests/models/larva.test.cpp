#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;

TEST(Larva, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite = &sprite;
  Larva larva(200, 320, pSprite);

  EXPECT_EQ(larva.getPoints(), 30);
}
