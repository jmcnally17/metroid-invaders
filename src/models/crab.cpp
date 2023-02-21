#include "../../include/models/crab.hpp"

Crab::Crab(float x, float y, ISprite *sprite) : Invader(x, y, sprite)
{
  width_ = 66;
  height_ = 48;
  points_ = 20;
}
