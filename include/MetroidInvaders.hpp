#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include "./wrappers/TextWrapper.hpp"
#include "./wrappers/SoundWrapper.hpp"
#include "./wrappers/SpriteWrapper.hpp"
#include "./wrappers/IRenderWindow.hpp"
#include "./models/IBunker.hpp"
#include "./models/GunshipLaser.hpp"
#include "./models/Gunship.hpp"
#include "./models/IMetroid.hpp"
#include "./models/IMetroidLaser.hpp"
#include "./models/Ridley.hpp"

SpriteWrapper makeBackground(std::string fileName);

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y);

SoundWrapper makeTheme(std::string fileName);

std::array<IBunker*, 4> makeBunkers();

GunshipLaser makeGunshipLaser();

Gunship makeGunship(GunshipLaser &gunshipLaser);

std::array<std::array<IMetroid*, 11>, 5> makeMetroids();

std::array<IMetroidLaser*, 3> makeMetroidLasers();

Ridley makeRidley();

std::array<ISound*, 4> makeMetroidSounds();

std::array<sf::RectangleShape, 2> makeRectangles();

void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText);

void adjustView(IRenderWindow &window, int windowWidth, int windowHeight);

#endif
