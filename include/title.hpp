#ifndef TITLE_HPP
#define TITLE_HPP

#include "./adaptors/IRenderWindow.hpp"
#include "./adaptors/ISprite.hpp"
#include "./adaptors/IText.hpp"
#include "./adaptors/ISound.hpp"
#include "./adaptors/IClock.hpp"

void play(bool &isPlaying, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock);

#endif
