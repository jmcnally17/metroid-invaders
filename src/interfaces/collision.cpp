#include "../../include/interfaces/collisionInterface.hpp"

bool Collision::haveCollided(const ObjectInterface &object1, const ObjectInterface &object2) const
{
  bool condition1 = object1.getPosition().y + object1.getHeight() > object2.getPosition().y;
  bool condition2 = object1.getPosition().y < object2.getPosition().y + object2.getHeight();
  bool condition3 = object1.getPosition().x + object1.getWidth() > object2.getPosition().x;
  bool condition4 = object1.getPosition().x < object2.getPosition().x + object2.getWidth();
  return condition1 && condition2 && condition3 && condition4;
}