#ifndef MOCK_TIME_HPP
#define MOCK_TIME_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/iTime.hpp"

class MockTime : public ITime
{
public:
  MOCK_METHOD(int, asMilliseconds, (), (const));
};

#endif
