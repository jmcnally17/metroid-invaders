#ifndef CRAB_HPP
#define CRAB_HPP

#include "./invader.hpp"

class Crab : public Invader
{
public:
  Crab(float x, float y, ISprite *sprite);
};

#endif
