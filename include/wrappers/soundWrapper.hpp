#ifndef SOUND_WRAPPER_HPP
#define SOUND_WRAPPER_HPP

#include "./iSound.hpp"

class SoundWrapper : public ISound, public sf::Sound
{
public:
  SoundWrapper(const sf::SoundBuffer &buffer);
  void play() override;
};

#endif
