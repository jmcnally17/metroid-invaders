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

TextWrapper makeTitleText(const sf::Font &font);

TextWrapper makeInstructionsText(const sf::Font &font);

SoundWrapper makeBattleTheme();

TextWrapper makeScoreText(const sf::Font &font);

TextWrapper makeLivesText(const Gunship &gunship, const sf::Font &font);

TextWrapper makeGameOverText(const sf::Font &font);

TextWrapper makePlayAgainText(const sf::Font &font);

#endif
