#include "../../include/adaptors/ClockAdaptor.hpp"

sf::Time ClockAdaptor::getElapsedTime() const
{
  return sf::Clock::getElapsedTime();
}

sf::Time ClockAdaptor::restart()
{
  return sf::Clock::restart();
}
