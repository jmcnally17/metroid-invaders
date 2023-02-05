#include "../../include/models/squid.hpp"
#include "../mockModels/mockSprite.hpp"

using ::testing::NiceMock;

TEST(Squid, hasAWidthClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getWidth(), 48);
}

TEST(Squid, hasAHeightClassMemberOf48)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getHeight(), 48);
}

TEST(Squid, hasAPointsClassMemberOf30)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPoints(), 30);
}

TEST(Squid, setsOwnPositionMember)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  EXPECT_EQ(squid.getPosition(), sf::Vector2f(200, 320));
}

TEST(Squid, setsPositionOnSpriteClassMember)
{
  MockSprite sprite;

  EXPECT_CALL(sprite, setPosition(sf::Vector2f(200, 320)))
      .Times(1);
  Squid squid(200, 320, sprite);
}

TEST(Squid, setPositionChangesPosition)
{
  NiceMock<MockSprite> sprite;
  Squid squid(200, 320, sprite);

  squid.setPosition(sf::Vector2f(500, 920));
  EXPECT_EQ(squid.getPosition(), sf::Vector2f(500, 920));
}
