#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include "./wrappers/iRenderWindow.hpp"
#include "./models/laserCannon.hpp"
#include "./models/laser.hpp"
#include "./models/iInvader.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const IInvader &invader);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void fireLaser(ILaserCannon &cannon);

Laser makeLaser();

LaserCannon makeCannon(Laser &laser);

#endif
