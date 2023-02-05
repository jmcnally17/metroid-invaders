#include "../../include/wrappers/soundWrapper.hpp"

SoundWrapper::SoundWrapper(const sf::SoundBuffer &buffer) : sf::Sound::Sound(buffer) {}

void SoundWrapper::play()
{
  sf::Sound::play();
}
