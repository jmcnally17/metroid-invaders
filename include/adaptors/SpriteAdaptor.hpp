#ifndef SPRITE_ADAPTOR_HPP
#define SPRITE_ADAPTOR_HPP

#include "./ISprite.hpp"

class SpriteAdaptor : public ISprite, virtual public sf::Drawable
{
public:
  SpriteAdaptor(sf::Texture &texture);
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void move(const sf::Vector2f &offset) override;
  sf::FloatRect getGlobalBounds() const override;
  void setScale(const sf::Vector2f &scale) override;

private:
  sf::Texture texture_;
  sf::Sprite sprite_;
};

#endif
