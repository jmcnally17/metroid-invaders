#include "../include/wrappers/iRenderWindow.hpp"
#include "../include/models/iLaserCannon.hpp"
#include "../include/models/iLaser.hpp"
#include "../include/models/iInvader.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const IInvader &invader)
{
  window.clear();
  cannon.draw(window);
  laser.draw(window);
  invader.draw(window);
  window.display();
}
