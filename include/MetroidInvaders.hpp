#ifndef METROID_INVADERS_HPP
#define METROID_INVADERS_HPP

#include "./adaptors/IText.hpp"
#include "./adaptors/IRenderWindow.hpp"

void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText);

void adjustView(IRenderWindow &window, int windowWidth, int windowHeight);

#endif
