#ifndef I_BUNKER_HPP
#define I_BUNKER_HPP

#include "./objectInterface.hpp"

class IBunker : public ObjectInterface
{
public:
  IBunker();
  IBunker(float width, float height, float x, float y, ISprite *sprite);
  virtual void decreaseHealth() = 0;
};

#endif
