#ifndef MOCK_CLOCK_HPP
#define MOCK_CLOCK_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/iClock.hpp"

class MockClock : public IClock
{
public:
  MOCK_METHOD(sf::Time, getElapsedTime, (), (const));
  MOCK_METHOD(sf::Time, restart, ());
};

#endif
