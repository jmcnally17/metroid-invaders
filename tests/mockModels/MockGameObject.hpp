#ifndef MOCK_GAME_OBJECT_HPP
#define MOCK_GAME_OBJECT_HPP

#include <gmock/gmock.h>
#include "../../include/models/IGameObject.hpp"

class MockGameObject : public IGameObject
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const IGameObject &gameObject), (const));
};

#endif
