#ifndef SPRITE_WRAPPER_HPP
#define SPRITE_WRAPPER_HPP

#include "./iSprite.hpp"

class SpriteWrapper : public ISprite, public sf::Sprite
{
public:
  SpriteWrapper(sf::Sprite &sprite);
  void setPosition(const sf::Vector2f &position) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif
