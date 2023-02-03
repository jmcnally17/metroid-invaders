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
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &vector));
};

#endif
