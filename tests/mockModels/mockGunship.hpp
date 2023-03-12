#ifndef MOCK_GUNSHIP_HPP
#define MOCK_GUNSHIP_HPP

#include <gmock/gmock.h>
#include "../../include/models/iGunship.hpp"

class MockGunship : public IGunship
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(void, move, (float x));
  MOCK_METHOD(void, fire, ());
  MOCK_METHOD(void, reset, ());
  MOCK_METHOD(void, loseLife, ());
  MOCK_METHOD(void, resetPosition, ());
  MOCK_METHOD(int, getLives, (), (const));
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const sf::FloatRect &rectangle), (const));
};

#endif
