#ifndef SPRITE_WRAPPER_HPP
#define SPRITE_WRAPPER_HPP

#include "./iSprite.hpp"

class SpriteWrapper : public ISprite, virtual public sf::Drawable
{
public:
  SpriteWrapper(sf::Texture &texture);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void move(const sf::Vector2f &offset) override;
  sf::FloatRect getGlobalBounds() const override;

private:
  sf::Texture texture_;
  sf::Sprite sprite_;
};

#endif
