#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include <vector>
#include "./wrappers/spriteWrapper.hpp"
#include "./wrappers/textWrapper.hpp"
#include "./wrappers/soundWrapper.hpp"
#include "./models/gunshipLaser.hpp"
#include "./models/gunship.hpp"
#include "./models/iMetroid.hpp"
#include "./models/ridley.hpp"

GunshipLaser makeGunshipLaser();

Gunship makeGunship(GunshipLaser &gunshipLaser);

std::vector<std::vector<IMetroid *>> makeMetroids();

std::vector<ILaser *> makeMetroidLasers();

Ridley makeRidley();

std::vector<ISound *> makeMetroidSounds();

SoundWrapper makeTitleTheme();

SpriteWrapper makeTitleBackground();

SoundWrapper makeBattleTheme();

SoundWrapper makeCreditsTheme();

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y);

#endif
