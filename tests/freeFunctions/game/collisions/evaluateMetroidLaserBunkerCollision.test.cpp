#include "../../../../include/Game.hpp"
#include "../../../mockModels/MockMetroidLaser.hpp"
#include "../../../mockModels/MockBunker.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateMetroidLaserBunkerCollisionTest : public testing::Test
{
protected:
  NiceMock<MockMetroidLaser> metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
};

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, decreasesHealthOfBunkersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(3);
  evaluateMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, resetsMetroidLasersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  evaluateMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicsIfHealthIs0)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  evaluateMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicsWhenNotColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  evaluateMetroidLaserBunkerCollision(metroidLasers, bunkers);
}
