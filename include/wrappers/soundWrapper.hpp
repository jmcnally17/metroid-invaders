#ifndef SOUND_WRAPPER_HPP
#define SOUND_WRAPPER_HPP

#include "./iSound.hpp"

class SoundWrapper : public ISound
{
public:
  SoundWrapper(const sf::SoundBuffer &buffer);
  void play() override;
  void setLoop(bool loop) override;
  void stop() override;

private:
  sf::SoundBuffer buffer_;
  sf::Sound sound_;
};

#endif
