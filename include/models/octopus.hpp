#ifndef OCTOPUS_HPP
#define OCTOPUS_HPP

#include "./invader.hpp"

class Octopus : public Invader
{
public:
  Octopus(float x, float y, ISprite &sprite);
  float getWidth() const;
  float getHeight() const;
  int getPoints() const;

private:
  float width_;
  float height_;
  int points_;
};

#endif
