#ifndef I_SOUND_HPP
#define I_SOUND_HPP

#include <SFML/Audio.hpp>

class ISound
{
public:
  virtual void play() = 0;
  virtual void setLoop(bool loop) = 0;
};

#endif
