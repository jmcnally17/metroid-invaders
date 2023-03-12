#ifndef MOCK_LASER_HPP
#define MOCK_LASER_HPP

#include <gmock/gmock.h>
#include "../../include/models/iLaser.hpp"

class MockLaser : public ILaser
{
public:
  MOCK_METHOD(float, getWidth, (), (const));
  MOCK_METHOD(float, getHeight, (), (const));
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(void, move, ());
  MOCK_METHOD(void, reset, ());
  MOCK_METHOD(void, playMetroidDeath, (), (const));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const sf::FloatRect &rectangle), (const));
};

#endif
