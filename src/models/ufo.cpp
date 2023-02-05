#include "../../include/models/ufo.hpp"

UFO::UFO(float x, float y, ISprite &sprite) : Invader(x, y, sprite), width_(96), height_(42), points_(150) {}

float UFO::getWidth() const
{
  return width_;
}

float UFO::getHeight() const
{
  return height_;
}

int UFO::getPoints() const
{
  return points_;
}
