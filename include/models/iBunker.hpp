#ifndef I_BUNKER_HPP
#define I_BUNKER_HPP

#include "./objectInterface.hpp"

class IBunker : public ObjectInterface
{
public:
  IBunker(float width, float height, float x, float y, ISprite *sprite);
};

#endif
