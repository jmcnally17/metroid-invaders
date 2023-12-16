#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockBunker.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class EvaluateMetroidLaserBunkerCollisionTest : public testing::Test
{
protected:
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> metroidLaser;
  MockLaser *pMetroidLaser {&metroidLaser};
  std::array<ILaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
};

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, decreasesHealthOfBunkersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(3);
  evaluateMetroidLaserBunkerCollision(collision, metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, resetsMetroidLasersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, reset())
      .Times(3);
  evaluateMetroidLaserBunkerCollision(collision, metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicsIfHealthIs0)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, reset)
      .Times(0);
  evaluateMetroidLaserBunkerCollision(collision, metroidLasers, bunkers);
}

TEST_F(EvaluateMetroidLaserBunkerCollisionTest, doesNotCarryOutCollisionMechanicsWhenNotColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, reset)
      .Times(0);
  evaluateMetroidLaserBunkerCollision(collision, metroidLasers, bunkers);
}
