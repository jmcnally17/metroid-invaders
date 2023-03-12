#include "../../include/wrappers/spriteWrapper.hpp"

SpriteWrapper::SpriteWrapper(sf::Texture &texture) : texture_(texture)
{
  sprite_.setTexture(texture_);
}

sf::Vector2f SpriteWrapper::getPosition() const
{
  return sprite_.getPosition();
}

void SpriteWrapper::setPosition(const sf::Vector2f &position)
{
  sprite_.setPosition(position);
}

void SpriteWrapper::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(sprite_, states);
};

void SpriteWrapper::move(const sf::Vector2f &offset)
{
  sprite_.move(offset);
}

sf::FloatRect SpriteWrapper::getGlobalBounds() const
{
  return sprite_.getGlobalBounds();
}
