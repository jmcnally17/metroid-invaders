#ifndef TEXT_ADAPTOR_HPP
#define TEXT_ADAPTOR_HPP

#include "./IText.hpp"

class TextAdaptor : public IText, virtual public sf::Drawable
{
public:
  TextAdaptor(const sf::String &string, const sf::Font &font);
  void setPosition(const sf::Vector2f &position) override;
  void setCharacterSize(unsigned int size);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  void setString(const std::string &string) override;
  sf::FloatRect getLocalBounds() const override;
  void setOrigin(float x, float y) override;
  void setFillColor(const sf::Color &color);

private:
  sf::String string_;
  sf::Font font_;
  sf::Text text_;
};

#endif
