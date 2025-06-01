#include "../../include/adaptors/SoundAdaptor.hpp"

SoundAdaptor::SoundAdaptor(const sf::SoundBuffer &buffer) : buffer_(buffer), sound_(sf::Sound(buffer_)) {}

void SoundAdaptor::play()
{
  sound_.play();
}

void SoundAdaptor::setLooping(bool loop)
{
  sound_.setLooping(loop);
}

void SoundAdaptor::stop()
{
  sound_.stop();
}

sf::Sound::Status SoundAdaptor::getStatus() const
{
  return sound_.getStatus();
}
