#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include <vector>
#include "./wrappers/textWrapper.hpp"
#include "./wrappers/soundWrapper.hpp"
#include "./wrappers/spriteWrapper.hpp"
#include "./models/gunshipLaser.hpp"
#include "./models/gunship.hpp"
#include "./models/iMetroid.hpp"
#include "./models/ridley.hpp"

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y);

SoundWrapper makeTheme(std::string fileName);

SpriteWrapper makeTitleBackground();

GunshipLaser makeGunshipLaser();

Gunship makeGunship(GunshipLaser &gunshipLaser);

std::vector<std::vector<IMetroid *>> makeMetroids();

std::vector<ILaser *> makeMetroidLasers();

Ridley makeRidley();

std::vector<ISound *> makeMetroidSounds();

#endif
