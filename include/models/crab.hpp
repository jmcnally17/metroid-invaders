#ifndef CRAB_HPP
#define CRAB_HPP

#include "./invader.hpp"

class Crab : public Invader
{
public:
  Crab(float x, float y, ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  int getPoints() const override;

private:
  float width_;
  float height_;
  int points_;
};

#endif
