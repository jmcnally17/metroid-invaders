#ifndef MOCK_SOUND_HPP
#define MOCK_SOUND_HPP

#include <gmock/gmock.h>
#include "../../include/wrappers/iSound.hpp"

class MockSound : public ISound
{
public:
  MOCK_METHOD(void, play, ());
  MOCK_METHOD(void, setLoop, (bool loop));
  MOCK_METHOD(void, stop, ());
};

#endif
