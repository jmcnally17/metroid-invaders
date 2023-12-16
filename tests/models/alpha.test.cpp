#include "../../include/models/metroids.hpp"
#include "../mockModels/mockSprite.hpp"
#include "../mockModels/mockRenderWindow.hpp"
#include "../mockModels/mockLaser.hpp"

using ::testing::NiceMock;

TEST(AlphaTest, hasAPointsClassMemberOf20)
{
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  Alpha alpha {Alpha(200, 320, pSprite)};
  
  EXPECT_EQ(alpha.getPoints(), 20);
}
