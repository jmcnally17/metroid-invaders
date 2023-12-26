#include "../../include/models/Invader.hpp"
#include "../mockModels/MockSprite.hpp"
#include "../mockModels/MockSound.hpp"

using ::testing::NiceMock;
using ::testing::Return;

class InvaderTest : public testing::Test
{
protected:
  NiceMock<MockSprite> sprite;
  MockSprite *pSprite {&sprite};
  NiceMock<MockSound> deathSound;
  MockSound *pDeathSound {&deathSound};
  Invader invader {Invader(300, 320, pSprite, 2.5, 50, 1, pDeathSound)};
};

TEST_F(InvaderTest, setsPointsUponInstantiation)
{
  EXPECT_EQ(invader.getPoints(), 50);
}

TEST_F(InvaderTest, setsDirectionUponInstantiation)
{
  EXPECT_EQ(invader.getDirection(), 1);
}

TEST_F(InvaderTest, changeDirectionSetsDirectionToMinusOne)
{
  invader.changeDirection();
  EXPECT_EQ(invader.getDirection(), -1);
}

TEST_F(InvaderTest, changeDirectionSetsDirectionBackToOne)
{
  invader.changeDirection(); // set direction to -1
  
  invader.changeDirection();
  EXPECT_EQ(invader.getDirection(), 1);
}

TEST_F(InvaderTest, moveMovesSpriteToTheRightWhenDirectionIsOne)
{
  EXPECT_CALL(sprite, move(sf::Vector2f(2.5, 0)))
    .Times(1);
  invader.move();
}

TEST_F(InvaderTest, moveMovesSpriteToTheLeftWhenDirectionIsMinusOne)
{
  invader.changeDirection(); // set direction to -1
  
  EXPECT_CALL(sprite, move(sf::Vector2f(-2.5, 0)))
    .Times(1);
  invader.move();
}

TEST_F(InvaderTest, diePlaysDeathSound)
{
  EXPECT_CALL(deathSound, play())
    .Times(1);
  invader.die();
}
