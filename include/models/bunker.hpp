#ifndef BUNKER_HPP
#define BUNKER_HPP

#include "./iBunker.hpp"

class Bunker : public IBunker
{
public:
  Bunker(float x, float y, ISprite *sprite1, ISprite *sprite2, ISprite *sprite3, ISprite *sprite4, ISprite *sprite5);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  int getHealth() const override;
  void decreaseHealth() override;
  void draw(IRenderWindow &window) const override;
  void reset() override;
  sf::FloatRect getGlobalBounds() const override;
  bool intersects(const sf::FloatRect &rectangle) const override;

private:
  ISprite *sprite2_;
  ISprite *sprite3_;
  ISprite *sprite4_;
  ISprite *sprite5_;
  int health_;
  void setPosition(const sf::Vector2f &position) override;
};

#endif
