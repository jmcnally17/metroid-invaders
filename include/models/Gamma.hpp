#ifndef GAMMA_HPP
#define GAMMA_HPP

#include "./Metroid.hpp"

class Gamma : public Metroid
{
public:
  Gamma(float x, float y, ISprite *sprite, ISound *deathSound);
};

#endif
