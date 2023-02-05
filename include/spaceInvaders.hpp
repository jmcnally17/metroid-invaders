#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include "./wrappers/iRenderWindow.hpp"
#include "./models/laserCannon.hpp"
#include "./models/laser.hpp"
#include "./models/invader.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const IInvader &invader);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void fireLaser(ILaserCannon &cannon);

Laser makeLaser();

LaserCannon makeCannon(Laser &laser);

Invader makeInvader(float x, float y);

#endif
