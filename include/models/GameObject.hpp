#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "./IGameObject.hpp"

class GameObject : public IGameObject
{
public:
  GameObject(float x, float y, ISprite *sprite);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  
protected:
  ISprite *sprite_;
};

#endif
