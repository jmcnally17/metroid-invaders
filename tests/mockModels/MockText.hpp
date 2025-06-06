#ifndef MOCK_TEXT_HPP
#define MOCK_TEXT_HPP

#include <gmock/gmock.h>
#include "../../include/adaptors/IText.hpp"

class MockText : public IText
{
public:
  MOCK_METHOD(void, draw, (sf::RenderTarget &target, sf::RenderStates states), (const));
  MOCK_METHOD(void, setString, (const std::string &string));
  MOCK_METHOD(void, setPosition, (const sf::Vector2f &position));
  MOCK_METHOD(sf::FloatRect, getLocalBounds, (), (const));
  MOCK_METHOD(void, setOrigin, (float x, float y));
};

#endif
