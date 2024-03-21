#include "../../include/adaptors/TextAdaptor.hpp"

TextAdaptor::TextAdaptor(const sf::String &string, const sf::Font &font) : string_(string), font_(font)
{
  text_.setString(string_);
  text_.setFont(font_);
}

void TextAdaptor::setPosition(const sf::Vector2f &position)
{
  text_.setPosition(position);
}

void TextAdaptor::setCharacterSize(unsigned int size)
{
  text_.setCharacterSize(size);
}

void TextAdaptor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(text_, states);
};

void TextAdaptor::setString(const std::string &string)
{
  text_.setString(string);
}

sf::FloatRect TextAdaptor::getLocalBounds() const
{
  return text_.getLocalBounds();
}

void TextAdaptor::setOrigin(float x, float y)
{
  text_.setOrigin(x, y);
}

void TextAdaptor::setFillColor(const sf::Color &color)
{
  text_.setFillColor(color);
}
