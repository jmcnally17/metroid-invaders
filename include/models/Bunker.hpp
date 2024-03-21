#ifndef BUNKER_HPP
#define BUNKER_HPP

#include "./GameObject.hpp"
#include "./IBunker.hpp"

class Bunker : public GameObject, public IBunker
{
public:
  Bunker(float x, float y, ISprite *sprite1, ISprite *sprite2, ISprite *sprite3, ISprite *sprite4, ISprite *sprite5);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const IGameObject &gameObject) const override;
  int getHealth() const override;
  void decreaseHealth() override;
  void draw(IRenderWindow &window) const override;
  void reset() override;

private:
  ISprite *sprite2_;
  ISprite *sprite3_;
  ISprite *sprite4_;
  ISprite *sprite5_;
  int health_;
};

#endif
