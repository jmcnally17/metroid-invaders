#ifndef MOCK_LASER_CANNON_HPP
#define MOCK_LASER_CANNON_HPP

#include <gmock/gmock.h>
#include "../../include/models/iLaserCannon.hpp"

class MockLaserCannon : public ILaserCannon
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const override));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const override));
  MOCK_METHOD(void, move, (float x), (override));
};

#endif