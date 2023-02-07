#ifndef UFO_HPP
#define UFO_HPP

#include "./invader.hpp"

class UFO : public Invader
{
public:
  UFO(float x, float y, ISprite &sprite);
  float getWidth() const override;
  float getHeight() const override;
  int getPoints() const;

private:
  float width_;
  float height_;
  int points_;
};

#endif
