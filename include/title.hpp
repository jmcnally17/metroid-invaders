#ifndef TITLE_HPP
#define TITLE_HPP

#include "./wrappers/IRenderWindow.hpp"
#include "./wrappers/ISprite.hpp"
#include "./wrappers/IText.hpp"
#include "./wrappers/ISound.hpp"
#include "./wrappers/IClock.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText);

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme, IClock &movementClock);

#endif
