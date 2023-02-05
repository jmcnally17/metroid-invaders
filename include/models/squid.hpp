#ifndef SQUID_HPP
#define SQUID_HPP

#include "./invader.hpp"

class Squid : public Invader
{
public:
  Squid(float x, float y, ISprite &sprite);
  float getWidth() const;
  float getHeight() const;
  int getPoints() const;

private:
  float width_;
  float height_;
  int points_;
};

#endif
