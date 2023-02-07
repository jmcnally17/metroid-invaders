#include "../include/models/objectInterface.hpp"

bool haveCollided(ObjectInterface &object1, ObjectInterface &object2)
{
  bool condition1 = object1.getPosition().y + object1.getHeight() > object2.getPosition().y;
  bool condition2 = object1.getPosition().y < object2.getPosition().y + object2.getHeight();
  return condition1 && condition2;
}
