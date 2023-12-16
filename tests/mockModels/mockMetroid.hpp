#ifndef MOCK_METROID_HPP
#define MOCK_METROID_HPP

#include <gmock/gmock.h>
#include "../../include/models/iMetroid.hpp"

class MockMetroid : public IMetroid
{
public:
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(sf::Vector2f, getOriginalPosition, (), (const));
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(bool, isAlive, (), (const));
  MOCK_METHOD(void, die, ());
  MOCK_METHOD(void, move, ());
  MOCK_METHOD(bool, hasJustMovedDown, (), (const));
  MOCK_METHOD(void, resurrect, ());
  MOCK_METHOD(void, reset, ());
  MOCK_METHOD(int, getPoints, (), (const));
  MOCK_METHOD(int, getDirection, (), (const));
  MOCK_METHOD(void, changeDirection, ());
  MOCK_METHOD(void, shoot, ((const std::array<ILaser*, 3>) &metroidLasers, int randomNumber), (const));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const sf::FloatRect &rectangle), (const));
};

#endif
