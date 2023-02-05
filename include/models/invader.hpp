#ifndef INVADER_HPP
#define INVADER_HPP

#include "../wrappers/iSprite.hpp"

class Invader
{
public:
  Invader(float x, float y, ISprite &sprite);
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &position);

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
