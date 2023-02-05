#include "../../include/models/squid.hpp"

Squid::Squid() : width_(48), height_(48) {}

float Squid::getWidth() const
{
  return width_;
}

float Squid::getHeight() const
{
  return height_;
}
