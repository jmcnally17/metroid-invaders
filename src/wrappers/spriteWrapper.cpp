#include "../../include/wrappers/spriteWrapper.hpp"

SpriteWrapper::SpriteWrapper(sf::Sprite &sprite) : sf::Sprite::Sprite(sprite) {}

void SpriteWrapper::setPosition(const sf::Vector2f &position)
{
  sf::Sprite::setPosition(position);
}

void SpriteWrapper::draw(sf::RenderTarget &target, sf::RenderStates states) const {};
