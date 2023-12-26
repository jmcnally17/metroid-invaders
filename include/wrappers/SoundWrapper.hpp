#ifndef SOUND_WRAPPER_HPP
#define SOUND_WRAPPER_HPP

#include "./ISound.hpp"

class SoundWrapper : public ISound
{
public:
  SoundWrapper(const sf::SoundBuffer &buffer);
  void play() override;
  void setLoop(bool loop) override;
  void stop() override;
  sf::Sound::Status getStatus() const override;

private:
  sf::SoundBuffer buffer_;
  sf::Sound sound_;
};

#endif
