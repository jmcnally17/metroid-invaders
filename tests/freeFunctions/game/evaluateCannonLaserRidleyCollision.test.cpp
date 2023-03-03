#include "../../../include/game.hpp"
#include "../../mockInterfaces/mockCollision.hpp"
#include "../../mockModels/mockLaser.hpp"
#include "../../mockModels/mockRidley.hpp"
#include "../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateCannonLaserRidleyCollision, killsRidleyIfCollidingWithCannonLaser)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> cannonLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));

    EXPECT_CALL(ridley, die())
        .Times(1);
    evaluateCannonLaserRidleyCollision(collision, cannonLaser, ridley, score, scoreText);
}

TEST(evaluateCannonLaserRidleyCollision, addsTheRidleyPointsToTheScore)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> cannonLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    evaluateCannonLaserRidleyCollision(collision, cannonLaser, ridley, score, scoreText);
    EXPECT_EQ(score, 580);
}

TEST(evaluateCannonLaserRidleyCollision, updatesTheScoreText)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> cannonLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    MockText scoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    EXPECT_CALL(scoreText, setString("Score: 580"))
        .Times(1);
    evaluateCannonLaserRidleyCollision(collision, cannonLaser, ridley, score, scoreText);
}

TEST(evaluateCannonLaserRidleyCollision, resetsTheCannonLaser)
{
    NiceMock<MockCollision> collision;
    MockLaser cannonLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));

    EXPECT_CALL(cannonLaser, reset())
        .Times(1);
    evaluateCannonLaserRidleyCollision(collision, cannonLaser, ridley, score, scoreText);
}

TEST(evaluateCannonLaserRidleyCollision, doesNotModifyAnythingIfRidleyAndLaserAreNotColliding)
{
    NiceMock<MockCollision> collision;
    MockLaser cannonLaser;
    MockRidley ridley;
    int score = 430;
    MockText scoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(false));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    EXPECT_CALL(ridley, die())
        .Times(0);
    EXPECT_CALL(scoreText, setString)
        .Times(0);
    EXPECT_CALL(cannonLaser, reset())
        .Times(0);
    evaluateCannonLaserRidleyCollision(collision, cannonLaser, ridley, score, scoreText);
    EXPECT_EQ(score, 430);
}
