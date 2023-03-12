#ifndef MOCK_OBJECT_INTERFACE_HPP
#define MOCK_OBJECT_INTERFACE_HPP

#include <gmock/gmock.h>
#include "../../include/models/objectInterface.hpp"

class MockObjectInterface : public ObjectInterface
{
public:
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(void, reset, ());
  MOCK_METHOD(sf::FloatRect, getGlobalBounds, (), (const));
  MOCK_METHOD(bool, intersects, (const sf::FloatRect &rectangle), (const));
};

#endif
