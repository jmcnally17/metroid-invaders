#ifndef SOUND_ADAPTOR_HPP
#define SOUND_ADAPTOR_HPP

#include "./ISound.hpp"

class SoundAdaptor : public ISound
{
public:
  SoundAdaptor(const sf::SoundBuffer &buffer);
  void play() override;
  void setLoop(bool loop) override;
  void stop() override;
  sf::Sound::Status getStatus() const override;

private:
  sf::SoundBuffer buffer_;
  sf::Sound sound_;
};

#endif
