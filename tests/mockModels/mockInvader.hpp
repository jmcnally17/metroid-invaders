#ifndef MOCK_INVADER_HPP
#define MOCK_INVADER_HPP

#include <gmock/gmock.h>
#include "../../include/models/iInvader.hpp"

class MockInvader : public IInvader
{
public:
  MOCK_METHOD(void, draw, (IRenderWindow &window), (const));
};

#endif
