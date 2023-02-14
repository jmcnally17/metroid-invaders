#include "../../include/models/octopus.hpp"

Octopus::Octopus(float x, float y, ISprite *sprite) : Invader(x, y, sprite), width_(72), height_(48), points_(10) {}

float Octopus::getWidth() const
{
  return width_;
}

float Octopus::getHeight() const
{
  return height_;
}

int Octopus::getPoints() const
{
  return points_;
}
