#include "../../include/adaptors/RenderWindowAdaptor.hpp"

RenderWindowAdaptor::RenderWindowAdaptor(sf::VideoMode mode, const sf::String name) : window_(sf::RenderWindow(mode, name)) {}

bool RenderWindowAdaptor::isOpen() const
{
  return window_.isOpen();
}

bool RenderWindowAdaptor::pollEvent(sf::Event &event)
{
  return window_.pollEvent(event);
}

void RenderWindowAdaptor::close()
{
  window_.close();
}

void RenderWindowAdaptor::clear()
{
  window_.clear();
}

void RenderWindowAdaptor::draw(const sf::Drawable &drawable)
{
  window_.draw(drawable);
}

void RenderWindowAdaptor::display()
{
  window_.display();
}

void RenderWindowAdaptor::setView(const sf::View &view)
{
  window_.setView(view);
}
