#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include "./wrappers/iRenderWindow.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser);

void moveLaserCannon(ILaserCannon &cannon, float x);

void fireLaser(ILaserCannon &cannon);

#endif
