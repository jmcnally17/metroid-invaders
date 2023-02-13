#ifndef SPACE_INVADERS_HPP
#define SPACE_INVADERS_HPP

#include <vector>
#include "./wrappers/textWrapper.hpp"
#include "./models/laser.hpp"
#include "./models/laserCannon.hpp"
#include "./models/iInvader.hpp"

Laser makeLaser();

LaserCannon makeCannon(Laser &laser);

std::vector<std::vector<IInvader *>> makeInvaders();

std::vector<ISound *> makeInvaderSounds();

TextWrapper makeScoreText(const sf::Font &font, const int score);

TextWrapper makeGameOverText(const sf::Font &font);

TextWrapper makePlayAgainText(const sf::Font &font);

#endif
