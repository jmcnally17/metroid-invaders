#ifndef MOCK_METROID_LASER
#define MOCK_METROID_LASER

#include <gmock/gmock.h>
#include "../../include/models/IMetroidLaser.hpp"

class MockMetroidLaser : public IMetroidLaser
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const IGameObject &gameObject), (const));
  MOCK_METHOD(void, resetPosition, ());
  MOCK_METHOD(void, move, ());
};

#endif
