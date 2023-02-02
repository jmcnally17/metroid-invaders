#ifndef MOCK_RENDER_WINDOW_HPP
#define MOCK_RENDER_WINDOW_HPP

#include "../../include/wrappers/iRenderWindow.hpp"

class MockRenderWindow : public IRenderWindow
{
public:
  MOCK_METHOD(void, draw, (const sf::Drawable &drawable), (override));
};

#endif
