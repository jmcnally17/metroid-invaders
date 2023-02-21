#ifndef SQUID_HPP
#define SQUID_HPP

#include "./invader.hpp"

class Squid : public Invader
{
public:
  Squid(float x, float y, ISprite *sprite);
};

#endif
