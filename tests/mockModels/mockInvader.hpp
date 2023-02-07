#ifndef MOCK_INVADER_HPP
#define MOCK_INVADER_HPP

#include <gmock/gmock.h>
#include "../../include/models/iInvader.hpp"

class MockInvader : public IInvader
{
public:
  MOCK_METHOD(void, draw, (IRenderWindow & window), (const));
  MOCK_METHOD(float, getWidth, (), (const));
  MOCK_METHOD(float, getHeight, (), (const));
  MOCK_METHOD(sf::Vector2f, getPosition, (), (const));
  MOCK_METHOD(bool, isAlive, (), (const));
  MOCK_METHOD(void, die, ());
};

#endif
