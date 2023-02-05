#ifndef INVADER_HPP
#define INVADER_HPP

#include "./iInvader.hpp"
#include "../wrappers/iSprite.hpp"

class Invader : public IInvader
{
public:
  Invader(float x, float y, ISprite &sprite);
  sf::Vector2f getPosition() const;
  void setPosition(const sf::Vector2f &position);
  void draw(IRenderWindow &window) const override;

private:
  sf::Vector2f position_;
  ISprite &sprite_;
};

#endif
