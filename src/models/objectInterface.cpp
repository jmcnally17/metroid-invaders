#include "../../include/models/objectInterface.hpp"

ObjectInterface::ObjectInterface() {}

ObjectInterface::ObjectInterface(float width, float height, float x, float y, ISprite *sprite)
    : width_(width), height_(height), position_(sf::Vector2f(x, y)), sprite_(sprite)
{
  sprite->setPosition(position_);
}
