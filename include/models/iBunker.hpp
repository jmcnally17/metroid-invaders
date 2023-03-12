#ifndef I_BUNKER_HPP
#define I_BUNKER_HPP

#include "./objectInterface.hpp"

class IBunker : public ObjectInterface
{
public:
  IBunker();
  IBunker(float x, float y, ISprite *sprite);
  virtual int getHealth() const = 0;
  virtual void decreaseHealth() = 0;
};

#endif
