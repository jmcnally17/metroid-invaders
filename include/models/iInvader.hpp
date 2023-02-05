#ifndef I_INVADER_HPP
#define I_INVADER_HPP

#include "../wrappers/iRenderWindow.hpp"

class IInvader
{
public:
  virtual void draw(IRenderWindow &window) const = 0;
};

#endif
