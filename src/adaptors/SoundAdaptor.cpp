#include "../../include/adaptors/SoundAdaptor.hpp"

SoundAdaptor::SoundAdaptor(const sf::SoundBuffer &buffer) : buffer_(buffer)
{
  sound_.setBuffer(buffer_);
}

void SoundAdaptor::play()
{
  sound_.play();
}

void SoundAdaptor::setLoop(bool loop)
{
  sound_.setLoop(loop);
}

void SoundAdaptor::stop()
{
  sound_.stop();
}

sf::Sound::Status SoundAdaptor::getStatus() const
{
  return sound_.getStatus();
}
