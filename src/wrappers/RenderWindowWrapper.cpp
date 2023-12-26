#include "../../include/wrappers/RenderWindowWrapper.hpp"

RenderWindowWrapper::RenderWindowWrapper(sf::VideoMode mode, const sf::String name) : window_(sf::RenderWindow(mode, name)) {}

bool RenderWindowWrapper::isOpen() const
{
  return window_.isOpen();
}

bool RenderWindowWrapper::pollEvent(sf::Event &event)
{
  return window_.pollEvent(event);
}

void RenderWindowWrapper::close()
{
  window_.close();
}

void RenderWindowWrapper::clear()
{
  window_.clear();
}

void RenderWindowWrapper::draw(const sf::Drawable &drawable)
{
  window_.draw(drawable);
}

void RenderWindowWrapper::display()
{
  window_.display();
}

void RenderWindowWrapper::setView(const sf::View &view)
{
  window_.setView(view);
}
