#ifndef MOCK_SOUND_HPP
#define MOCK_SOUND_HPP

#include <gmock/gmock.h>
#include "../../include/adaptors/ISound.hpp"

class MockSound : public ISound
{
public:
  MOCK_METHOD(void, play, ());
  MOCK_METHOD(void, setLoop, (bool loop));
  MOCK_METHOD(void, stop, ());
  MOCK_METHOD(sf::Sound::Status, getStatus, (), (const));
};

#endif
