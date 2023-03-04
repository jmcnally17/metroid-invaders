#include "../../include/wrappers/textWrapper.hpp"

TextWrapper::TextWrapper(const sf::String &string, const sf::Font &font) : string_(string), font_(font)
{
  text_.setString(string_);
  text_.setFont(font_);
}

void TextWrapper::setPosition(const sf::Vector2f &position)
{
  text_.setPosition(position);
}

void TextWrapper::setCharacterSize(unsigned int size)
{
  text_.setCharacterSize(size);
}

void TextWrapper::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(text_, states);
};

void TextWrapper::setString(const std::string &string)
{
  text_.setString(string);
}

sf::FloatRect TextWrapper::getLocalBounds() const
{
  return text_.getLocalBounds();
}

void TextWrapper::setOrigin(float x, float y)
{
  text_.setOrigin(x, y);
}

void TextWrapper::setFillColor(const sf::Color &color)
{
  text_.setFillColor(color);
}
