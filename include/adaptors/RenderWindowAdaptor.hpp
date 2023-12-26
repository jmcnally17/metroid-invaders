#ifndef RENDER_WINDOW_ADAPTOR_HPP
#define RENDER_WINDOW_ADAPTOR_HPP

#include "./IRenderWindow.hpp"

class RenderWindowAdaptor : public IRenderWindow
{
public:
  RenderWindowAdaptor(sf::VideoMode mode, const sf::String name);
  bool isOpen() const;
  bool pollEvent(sf::Event &event);
  void close();
  void clear() override;
  void draw(const sf::Drawable &drawable) override;
  void display() override;
  void setView(const sf::View &view) override;

private:
  sf::RenderWindow window_;
};

#endif
