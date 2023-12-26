#ifndef RENDER_WINDOW_WRAPPER_HPP
#define RENDER_WINDOW_WRAPPER_HPP

#include "./IRenderWindow.hpp"

class RenderWindowWrapper : public IRenderWindow
{
public:
  RenderWindowWrapper(sf::VideoMode mode, const sf::String name);
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
