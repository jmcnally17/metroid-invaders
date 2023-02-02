#include "../include/wrappers/iRenderWindow.hpp"
#include "../include/models/iLaserCannon.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon)
{
  window.clear();
  cannon.draw(window);
}
