#ifndef I_INVADER_HPP
#define I_INVADER_HPP

#include "../wrappers/iRenderWindow.hpp"

class IInvader
{
public:
  virtual void draw(IRenderWindow &window) const = 0;
  virtual float getWidth() const = 0;
  virtual float getHeight() const = 0;
  virtual sf::Vector2f getPosition() const = 0;
};

#endif
