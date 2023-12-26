#include "../../include/interfaces/collisionInterface.hpp"

bool Collision::haveCollided(const IGameObject &gameObject1, const IGameObject &gameObject2) const
{
  return gameObject1.intersects(gameObject2);
}
