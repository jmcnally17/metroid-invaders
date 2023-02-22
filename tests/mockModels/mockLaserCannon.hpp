#ifndef MOCK_LASER_CANNON_HPP
#define MOCK_LASER_CANNON_HPP

#include <gmock/gmock.h>
#include "../../include/models/iLaserCannon.hpp"

class MockLaserCannon : public ILaserCannon
{
public:
  MOCK_METHOD(float, getWidth, (), (const));
  MOCK_METHOD(float, getHeight, (), (const));
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(void, move, (float x));
  MOCK_METHOD(void, fire, ());
  MOCK_METHOD(void, reset, ());
};

#endif
