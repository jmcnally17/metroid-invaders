#ifndef MOCK_TEXT_HPP
#define MOCK_TEXT_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/iText.hpp"

class MockText : public IText
{
public:
  MOCK_METHOD(void, draw, (sf::RenderTarget & target, sf::RenderStates states), (const));
};

#endif
