#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include <vector>
#include "./wrappers/textWrapper.hpp"
#include "./wrappers/soundWrapper.hpp"
#include "./wrappers/spriteWrapper.hpp"
#include "./wrappers/iRenderWindow.hpp"
#include "./models/iBunker.hpp"
#include "./models/gunshipLaser.hpp"
#include "./models/gunship.hpp"
#include "./models/iMetroid.hpp"
#include "./models/ridley.hpp"

SpriteWrapper makeBackground(std::string fileName);

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y);

SoundWrapper makeTheme(std::string fileName);

std::vector<IBunker *> makeBunkers();

GunshipLaser makeGunshipLaser();

Gunship makeGunship(GunshipLaser &gunshipLaser);

std::vector<std::vector<IMetroid *>> makeMetroids();

std::vector<ILaser *> makeMetroidLasers();

Ridley makeRidley();

std::vector<ISound *> makeMetroidSounds();

std::vector<sf::RectangleShape> makeRectangles();

void pullHighScore(int &highScore, IText &highScoreText);

void adjustView(IRenderWindow &window, int windowWidth, int windowHeight);

#endif
