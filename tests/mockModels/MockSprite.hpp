#ifndef MOCK_SPRITE_HPP
#define MOCK_SPRITE_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/ISprite.hpp"

class MockSprite : public ISprite
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (sf::RenderTarget & target, sf::RenderStates states), (const));
  MOCK_METHOD(void, move, (const sf::Vector2f &offset));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
};

#endif
