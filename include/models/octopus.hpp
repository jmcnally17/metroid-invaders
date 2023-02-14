#ifndef OCTOPUS_HPP
#define OCTOPUS_HPP

#include "./invader.hpp"

class Octopus : public Invader
{
public:
  Octopus(float x, float y, ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  int getPoints() const override;

private:
  float width_;
  float height_;
  int points_;
};

#endif
