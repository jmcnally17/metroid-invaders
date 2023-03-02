#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include <vector>
#include "./wrappers/textWrapper.hpp"
#include "./models/cannonLaser.hpp"
#include "./models/laserCannon.hpp"
#include "./models/iMetroid.hpp"
#include "./models/ridley.hpp"

CannonLaser makeLaser();

LaserCannon makeCannon(CannonLaser &cannonLaser);

std::vector<std::vector<IMetroid *>> makeMetroids();

std::vector<ILaser *> makeMetroidLasers();

Ridley makeRidley();

std::vector<ISound *> makeMetroidSounds();

TextWrapper makeScoreText(const sf::Font &font);

TextWrapper makeLivesText(const LaserCannon &cannon, const sf::Font &font);

TextWrapper makeGameOverText(const sf::Font &font);

TextWrapper makePlayAgainText(const sf::Font &font);

#endif
