#ifndef OCTOPUS_HPP
#define OCTOPUS_HPP

#include "./invader.hpp"

class Octopus : public Invader
{
public:
  Octopus(float x, float y, ISprite *sprite);
};

#endif
