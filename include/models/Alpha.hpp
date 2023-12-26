#ifndef ALPHA_HPP
#define ALPHA_HPP

#include "./Metroid.hpp"

class Alpha : public Metroid
{
public:
  Alpha(float x, float y, ISprite *sprite, ISound *deathSound);
};

#endif
