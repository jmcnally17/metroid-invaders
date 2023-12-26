#include "../../include/wrappers/ClockWrapper.hpp"

sf::Time ClockWrapper::getElapsedTime() const
{
  return sf::Clock::getElapsedTime();
}

sf::Time ClockWrapper::restart()
{
  return sf::Clock::restart();
}
