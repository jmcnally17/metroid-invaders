#include "../../include/wrappers/soundWrapper.hpp"

SoundWrapper::SoundWrapper(const sf::SoundBuffer &buffer) : buffer_(buffer)
{
  sound_.setBuffer(buffer_);
}

void SoundWrapper::play()
{
  sound_.play();
}

void SoundWrapper::setLoop(bool loop)
{
  sound_.setLoop(loop);
}
