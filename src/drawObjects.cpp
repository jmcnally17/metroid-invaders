#include "../include/wrappers/iRenderWindow.hpp"
#include "../include/models/iLaserCannon.hpp"
#include "../include/models/iLaser.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  window.display();
}
