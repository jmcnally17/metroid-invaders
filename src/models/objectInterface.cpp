#include "../../include/models/objectInterface.hpp"

ObjectInterface::ObjectInterface() {}

ObjectInterface::ObjectInterface(float x, float y, ISprite *sprite)
    : sprite_(sprite)
{
  sprite->setPosition(sf::Vector2f(x, y));
}
