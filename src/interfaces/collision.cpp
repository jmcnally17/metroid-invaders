#include "../../include/interfaces/collisionInterface.hpp"

bool Collision::haveCollided(const ObjectInterface &object1, const ObjectInterface &object2) const
{
  sf::FloatRect object2Box {object2.getGlobalBounds()};
  return object1.intersects(object2Box);
}
