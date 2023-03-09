#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockBunker.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateGunshipLaserBunkerCollision, decreasesHealthOfBunkerWhenColliding)
{
  NiceMock<MockCollision> collision;
  NiceMock<MockLaser> gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }

  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(1);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST(evaluateGunshipLaserBunkerCollision, resetsTheGunshipLaserWhenColliding)
{
  NiceMock<MockCollision> collision;
  MockLaser gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }

  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, reset())
      .Times(1);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST(evaluateGunshipLaserBunkerCollision, doesNotCarryOutCollisionMechanicWhenHealthIs0)
{
  MockCollision collision;
  MockLaser gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }

  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset)
      .Times(0);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}

TEST(evaluateGunshipLaserBunkerCollision, doesNotCarryOutCollisionMechanicWhenNotColliding)
{
  NiceMock<MockCollision> collision;
  MockLaser gunshipLaser;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker = &bunker;
  std::vector<IBunker *> bunkers(4);
  for (int i = 0; i < 4; i++)
  {
    bunkers[i] = pBunker;
  }

  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(collision, haveCollided)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, reset)
      .Times(0);
  evaluateGunshipLaserBunkerCollision(collision, gunshipLaser, bunkers);
}
