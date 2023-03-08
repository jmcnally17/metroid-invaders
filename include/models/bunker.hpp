#ifndef BUNKER_HPP
#define BUNKER_HPP

#include "./objectInterface.hpp"

class Bunker : public ObjectInterface
{
public:
  Bunker(float x, float y, ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  sf::Vector2f getPosition() const override;
  int getHealth() const;
  void draw(IRenderWindow &window) const override;
  void reset() override;

private:
  int health_;
  void setPosition(const sf::Vector2f &position) override;
};

#endif
