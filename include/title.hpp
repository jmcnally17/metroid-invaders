#ifndef TITLE_HPP
#define TITLE_HPP

#include "./adaptors/IRenderWindow.hpp"
#include "./adaptors/ISprite.hpp"
#include "./adaptors/IText.hpp"
#include "./adaptors/ISound.hpp"
#include "./adaptors/IClock.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText);

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme, IClock &movementClock);

#endif
