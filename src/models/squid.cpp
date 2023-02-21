#include "../../include/models/squid.hpp"

Squid::Squid(float x, float y, ISprite *sprite) : Invader(x, y, sprite)
{
  width_ = 48;
  height_ = 48;
  points_ = 30;
}
