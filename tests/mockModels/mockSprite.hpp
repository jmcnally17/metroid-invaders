#ifndef MOCK_SPRITE_HPP
#define MOCK_SPRITE_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/iSprite.hpp"

class MockSprite : public ISprite
{
public:
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position), (override));
  MOCK_METHOD(void, draw, (sf::RenderTarget & target, sf::RenderStates states), (const override));
};

#endif
