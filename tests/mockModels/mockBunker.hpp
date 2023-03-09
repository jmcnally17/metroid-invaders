#ifndef MOCK_BUNKER_HPP
#define MOCK_BUNKER_HPP

#include <gmock/gmock.h>
#include "../../include/models/iBunker.hpp"

class MockBunker : public IBunker
{
public:
  MOCK_METHOD(float, getWidth, (), (const));
  MOCK_METHOD(float, getHeight, (), (const));
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(void, reset, ());
};

#endif
