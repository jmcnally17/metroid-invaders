#ifndef TITLE_HPP
#define TITLE_HPP

#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSprite.hpp"
#include "./wrappers/iText.hpp"
#include "./wrappers/iSound.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText);

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme);

#endif
