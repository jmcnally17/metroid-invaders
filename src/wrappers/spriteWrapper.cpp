#include "../../include/wrappers/spriteWrapper.hpp"

SpriteWrapper::SpriteWrapper(sf::Sprite &sprite) : sprite_(sprite) {}

void SpriteWrapper::setPosition(const sf::Vector2f &position)
{
  sprite_.setPosition(position);
}

void SpriteWrapper::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(sprite_, states);
};
