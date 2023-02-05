#include "../../include/models/invader.hpp"

Invader::Invader(float x, float y) : position_(sf::Vector2f(x, y)) {}

sf::Vector2f Invader::getPosition() const
{
  return position_;
}
