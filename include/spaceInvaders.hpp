#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include "./wrappers/iRenderWindow.hpp"
#include "./models/laserCannon.hpp"
#include "./models/laser.hpp"
#include "./models/iInvader.hpp"
#include <vector>

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void fireLaser(ILaserCannon &cannon);

bool hasInvaderBeenHit(ILaser &laser, IInvader &invader);

Laser makeLaser();

LaserCannon makeCannon(Laser &laser);

std::vector<std::vector<IInvader *>> makeInvaders();

#endif
