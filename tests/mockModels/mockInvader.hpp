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
  MOCK_METHOD(void, shoot, (const std::vector<ILaser *> &lasers, int randomNumber), (const));
};

#endif
