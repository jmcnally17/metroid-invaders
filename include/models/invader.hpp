#ifndef INVADER_HPP
#define INVADER_HPP

#include "./iInvader.hpp"
#include "../wrappers/iSprite.hpp"

class Invader : public IInvader
{
public:
  Invader(float x, float y, ISprite &sprite);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position);
  void draw(IRenderWindow &window) const override;
  bool isAlive() const;
  void die();

private:
  sf::Vector2f position_;
  ISprite &sprite_;
  bool alive_;
};

#endif
