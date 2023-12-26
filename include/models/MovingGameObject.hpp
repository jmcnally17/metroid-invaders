#ifndef MOVING_GAME_OBJECT_HPP
#define MOVING_GAME_OBJECT_HPP

#include "./GameObject.hpp"

class MovingGameObject : public GameObject
{
public:
  MovingGameObject(float x, float y, ISprite *sprite, float speed);
  sf::Vector2f getOriginalPosition() const;
  float getSpeed() const;
  void resetPosition();
  
protected:
  sf::Vector2f originalPosition_;
  float speed_;
};

#endif
