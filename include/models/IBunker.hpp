#ifndef I_BUNKER_HPP
#define I_BUNKER_HPP

#include "./IGameObject.hpp"

class IBunker : public IGameObject
{
public:
  virtual int getHealth() const = 0;
  virtual void decreaseHealth() = 0;
  virtual void draw(IRenderWindow &window) const = 0;
  virtual void reset() = 0;
};

#endif
