#ifndef METROIDS_HPP
#define METROIDS_HPP

#include "./metroid.hpp"

class Alpha : public Metroid
{
public:
  Alpha(float x, float y, ISprite *sprite);
};

class Gamma : public Metroid
{
public:
  Gamma(float x, float y, ISprite *sprite);
};

class Larva : public Metroid
{
public:
  Larva(float x, float y, ISprite *sprite);
};

#endif
