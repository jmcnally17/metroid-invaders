#ifndef INVADER_HPP
#define INVADER_HPP

#include "./iInvader.hpp"
#include "../wrappers/iSprite.hpp"

class Invader : public IInvader
{
public:
  Invader(float x, float y, ISprite &sprite);
  sf::Vector2f getOriginalPosition() const;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position);
  void draw(IRenderWindow &window) const override;
  bool isAlive() const override;
  void die() override;
  int getDirection() const;
  void move() override;
  void changeDirection();
  bool hasJustMovedDown() const override;
  void reset();

private:
  sf::Vector2f originalPosition_;
  sf::Vector2f position_;
  ISprite &sprite_;
  bool alive_;
  int direction_;
  bool justMovedDown_;
};

#endif
