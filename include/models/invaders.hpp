#ifndef INVADERS_HPP
#define INVADERS_HPP

#include "./invader.hpp"

class Crab : public Invader
{
public:
  Crab(float x, float y, ISprite *sprite);
};

class Octopus : public Invader
{
public:
  Octopus(float x, float y, ISprite *sprite);
};

class Squid : public Invader
{
public:
  Squid(float x, float y, ISprite *sprite);
};

#endif
