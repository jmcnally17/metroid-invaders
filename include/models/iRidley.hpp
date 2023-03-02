#ifndef I_RIDLEY_HPP
#define I_RIDLEY_HPP

#include "./objectInterface.hpp"

class IRidley : public ObjectInterface
{
public:
  IRidley();
  IRidley(float width, float height, float x, float y, ISprite *sprite);
};

#endif
