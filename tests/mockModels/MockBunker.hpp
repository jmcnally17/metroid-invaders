#ifndef MOCK_BUNKER_HPP
#define MOCK_BUNKER_HPP

#include <gmock/gmock.h>
#include "../../include/models/IBunker.hpp"

class MockBunker : public IBunker
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const IGameObject &gameObject), (const));
  MOCK_METHOD(int, getHealth, (), (const));
  MOCK_METHOD(void, decreaseHealth, ());
  MOCK_METHOD(void, draw, (IRenderWindow &window), (const));
  MOCK_METHOD(void, reset, ());
};

#endif
