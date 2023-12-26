#include "../../../../include/Game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/MockGunshipLaser.hpp"
#include "../../../mockModels/MockBunker.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateGunshipLaserBunkerCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockGunshipLaser> gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
};

TEST_F(EvaluateGunshipLaserBunkerCollisionTest, decreasesHealthOfBunkerWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(1);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST_F(EvaluateGunshipLaserBunkerCollisionTest, resetsTheGunshipLaserWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST_F(EvaluateGunshipLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicWhenHealthIs0)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST_F(EvaluateGunshipLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicWhenNotColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}
