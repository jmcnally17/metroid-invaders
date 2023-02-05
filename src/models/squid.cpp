#include "../../include/models/squid.hpp"

Squid::Squid(float x, float y, ISprite &sprite) : Invader(x, y, sprite), width_(48), height_(48), points_(30) {}

float Squid::getWidth() const
{
  return width_;
}

float Squid::getHeight() const
{
  return height_;
}

int Squid::getPoints() const
{
  return points_;
}
