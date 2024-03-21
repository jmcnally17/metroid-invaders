#include "../../../include/helpers/game/Collision.hpp"
#include "../../mockModels/MockBunker.hpp"
#include "../../mockModels/MockGunship.hpp"
#include "../../mockModels/MockGunshipLaser.hpp"
#include "../../mockModels/MockMetroid.hpp"
#include "../../mockModels/MockMetroidLaser.hpp"
#include "../../mockModels/MockRidley.hpp"
#include "../../mockModels/MockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class CollisionTest : public testing::Test
{
protected:
  Collision collision;
  NiceMock<MockBunker> bunker;
  MockBunker *pBunker {&bunker};
  std::array<IBunker*, 4> bunkers {pBunker, pBunker, pBunker, pBunker};
  NiceMock<MockGunship> gunship;
  MockGunship *pGunship {&gunship};
  NiceMock<MockGunshipLaser> gunshipLaser;
  MockGunshipLaser *pGunshipLaser {&gunshipLaser};
  NiceMock<MockMetroid> metroid;
  MockMetroid *pMetroid {&metroid};
  std::array<std::array<IMetroid*, 11>, 5> metroids {{
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
    {{pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid, pMetroid}},
  }};
  NiceMock<MockMetroidLaser> metroidLaser;
  MockMetroidLaser *pMetroidLaser {&metroidLaser};
  std::array<IMetroidLaser*, 3> metroidLasers {pMetroidLaser, pMetroidLaser, pMetroidLaser};
  NiceMock<MockRidley> ridley;
  MockRidley *pRidley {&ridley};
  std::unordered_map<std::string, int> variables {
    {"score", 430},
    {"highScore", 1000},
  };
  NiceMock<MockText> scoreText;
  MockText *pScoreText {&scoreText};
  MockText highScoreText;
  MockText *pHighScoreText {&highScoreText};
  NiceMock<MockText> livesText;
  MockText *pLivesText {&livesText};
  std::unordered_map<std::string, IText*> textObjects {
    {"score", pScoreText},
    {"highScore", pHighScoreText},
    {"lives", pLivesText},
  };
};

TEST_F(CollisionTest, gunshipLaserBunkerCollisionDecreasesHealthOfBunkerWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(1);
  collision.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
}

TEST_F(CollisionTest, gunshipLaserBunkerCollisionResetsTheGunshipLaserWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  collision.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
}

TEST_F(CollisionTest, gunshipLaserBunkerCollisionDoesNotCarryOutCollisionMechanicWhenHealthIs0)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
}

TEST_F(CollisionTest, gunshipLaserBunkerCollisionDoesNotCarryOutCollisionMechanicWhenNotColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionKillsMetroidThatIsAliveAndGunshipLaserIsCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(1);
  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionAddsTheMetroidPointsToTheScore)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(scoreText, setString("Score: 460"))
      .Times(1);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
  EXPECT_EQ(variables["score"], 460);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionUpdatesTheHighScoreTextIfScoreSurpassesHighScore)
{
  variables["score"] = {990};

  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(highScoreText, setString("High Score: 1020"))
      .Times(1);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionDoesNotUpdateTheHighScoreTextIfScoreDoesNotSurpassHighScore)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(metroid, getPoints())
      .WillByDefault(Return(30));

  EXPECT_CALL(highScoreText, setString)
      .Times(0);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionDoesNotKillMetroidsThatAreAliveAndGunshipLaserIsNotCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(true));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionDoesNotKillMetroidsThatAreDeadAndGunshipLaserIsCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserMetroidCollisionDoesNotKillMetroidsThatAreDeadAndGunshipLaserIsNotCollidingWith)
{
  ON_CALL(metroid, isAlive())
      .WillByDefault(Return(false));
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(false));

  EXPECT_CALL(metroid, die())
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionKillsRidleyIfCollidingWithGunshipLaser)
{
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(ridley, die())
      .Times(1);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionAddsTheRidleyPointsToTheScore)
{
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(scoreText, setString("Score: 580"))
      .Times(1);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
  EXPECT_EQ(variables["score"], 580);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionUpdatesTheHighScoreTextIfScoreSurpassesHighScore)
{
  variables["score"] = {900};

  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(highScoreText, setString("High Score: 1050"))
      .Times(1);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionDoesNotUpdatesTheHighScoreTextIfScoreDoesNotSurpassHighScore)
{
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(highScoreText, setString)
      .Times(0);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionResetsTheGunshipLaser)
{
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
}

TEST_F(CollisionTest, gunshipLaserRidleyCollisionDoesNotModifyAnythingIfRidleyAndLaserAreNotColliding)
{
  ON_CALL(gunshipLaser, intersects)
      .WillByDefault(Return(false));
  ON_CALL(ridley, getPoints())
      .WillByDefault(Return(150));

  EXPECT_CALL(ridley, die())
      .Times(0);
  EXPECT_CALL(scoreText, setString)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  collision.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
  EXPECT_EQ(variables["score"], 430);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionCallsLoseLifeOnGunship)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, loseLife())
      .Times(1);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionCallsResetPositionOnGunship)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunship, resetPosition())
      .Times(1);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionCallsResetOnMetroidLasers)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionCallsResetOnGunshipLaser)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(gunshipLaser, resetPosition())
      .Times(1);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionUpdatesTheLivesText)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(true));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(livesText, setString("Lives: 1"))
      .Times(1);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, gunshipMetroidLaserCollisionDoesNotModifyAnythingIfThereAreNoCollisions)
{
  ON_CALL(gunship, intersects)
      .WillByDefault(Return(false));
  ON_CALL(gunship, getLives())
      .WillByDefault(Return(1));

  EXPECT_CALL(gunship, loseLife)
      .Times(0);
  EXPECT_CALL(gunship, resetPosition)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  EXPECT_CALL(gunshipLaser, resetPosition)
      .Times(0);
  EXPECT_CALL(livesText, setString)
      .Times(0);
  collision.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

TEST_F(CollisionTest, MetroidLaserBunkerCollisionDecreasesHealthOfBunkersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth())
      .Times(3);
  collision.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(CollisionTest, MetroidLaserBunkerCollisionResetsMetroidLasersWhenColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(metroidLaser, resetPosition())
      .Times(3);
  collision.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(CollisionTest, MetroidLaserBunkerCollisionDoesNotCarryOutCollisionMechanicsIfHealthIs0)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(0));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(true));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  collision.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
}

TEST_F(CollisionTest, MetroidLaserBunkerCollisionDoesNotCarryOutCollisionMechanicsWhenNotColliding)
{
  ON_CALL(bunker, getHealth())
      .WillByDefault(Return(10));
  ON_CALL(metroidLaser, intersects)
      .WillByDefault(Return(false));

  EXPECT_CALL(bunker, decreaseHealth)
      .Times(0);
  EXPECT_CALL(metroidLaser, resetPosition)
      .Times(0);
  collision.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
}
