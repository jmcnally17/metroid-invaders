#ifndef SPRITE_WRAPPER_HPP
#define SPRITE_WRAPPER_HPP

#include "./iSprite.hpp"

class SpriteWrapper : public ISprite, virtual public sf::Drawable
{
public:
  SpriteWrapper(sf::Sprite &sprite);
  void setPosition(const sf::Vector2f &position) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
  sf::Sprite sprite_;
};

#endif
