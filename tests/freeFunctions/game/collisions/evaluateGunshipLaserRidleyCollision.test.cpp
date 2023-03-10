#include "../../../../include/game.hpp"
#include "../../../mockInterfaces/mockCollision.hpp"
#include "../../../mockModels/mockLaser.hpp"
#include "../../../mockModels/mockRidley.hpp"
#include "../../../mockModels/mockText.hpp"

using ::testing::NiceMock;
using ::testing::Return;

TEST(evaluateGunshipLaserRidleyCollision, killsRidleyIfCollidingWithGunshipLaser)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> gunshipLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;
    int highScore = 1000;
    MockText highScoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));

    EXPECT_CALL(ridley, die())
        .Times(1);
    evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
}

TEST(evaluateGunshipLaserRidleyCollision, addsTheRidleyPointsToTheScore)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> gunshipLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    MockText scoreText;
    int highScore = 1000;
    MockText highScoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    EXPECT_CALL(scoreText, setString("Score: 580"))
        .Times(1);
    evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
    EXPECT_EQ(score, 580);
}

TEST(evaluateGunshipLaserRidleyCollision, updatesTheHighScoreIfScoreSurpassesIt)
{
    NiceMock<MockCollision> collision;
    NiceMock<MockLaser> gunshipLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;
    int highScore = 450;
    MockText highScoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    EXPECT_CALL(highScoreText, setString("High Score: 580"))
        .Times(1);
    evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
    EXPECT_EQ(highScore, 580);
}

TEST(evaluateGunshipLaserRidleyCollision, resetsTheGunshipLaser)
{
    NiceMock<MockCollision> collision;
    MockLaser gunshipLaser;
    NiceMock<MockRidley> ridley;
    int score = 430;
    NiceMock<MockText> scoreText;
    int highScore = 1000;
    MockText highScoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(true));

    EXPECT_CALL(gunshipLaser, reset())
        .Times(1);
    evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
}

TEST(evaluateGunshipLaserRidleyCollision, doesNotModifyAnythingIfRidleyAndLaserAreNotColliding)
{
    NiceMock<MockCollision> collision;
    MockLaser gunshipLaser;
    MockRidley ridley;
    int score = 430;
    MockText scoreText;
    int highScore = 1000;
    MockText highScoreText;

    ON_CALL(collision, haveCollided)
        .WillByDefault(Return(false));
    ON_CALL(ridley, getPoints())
        .WillByDefault(Return(150));

    EXPECT_CALL(ridley, die())
        .Times(0);
    EXPECT_CALL(scoreText, setString)
        .Times(0);
    EXPECT_CALL(gunshipLaser, reset())
        .Times(0);
    evaluateGunshipLaserRidleyCollision(collision, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
    EXPECT_EQ(score, 430);
}
