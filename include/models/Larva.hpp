#ifndef LARVA_HPP
#define LARVA_HPP

#include "./Metroid.hpp"

class Larva : public Metroid
{
public:
  Larva(float x, float y, ISprite *sprite, ISound *deathSound);
};

#endif
