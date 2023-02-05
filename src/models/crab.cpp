#include "../../include/models/crab.hpp"

Crab::Crab(float x, float y, ISprite &sprite) : Invader(x, y, sprite), width_(66), height_(48), points_(20) {}

float Crab::getWidth() const
{
  return width_;
}

float Crab::getHeight() const
{
  return height_;
}

int Crab::getPoints() const
{
  return points_;
}
