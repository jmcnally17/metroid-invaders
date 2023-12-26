#ifndef MOCK_RENDER_WINDOW_HPP
#define MOCK_RENDER_WINDOW_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/IRenderWindow.hpp"

class MockRenderWindow : public IRenderWindow
{
public:
  MOCK_METHOD(void, clear, ());
  MOCK_METHOD(void, draw, (const sf::Drawable &drawable));
  MOCK_METHOD(void, display, ());
  MOCK_METHOD(void, setView, (const sf::View &view));
};

#endif
