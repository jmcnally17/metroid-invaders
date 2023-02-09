#include "../../include/wrappers/clockWrapper.hpp"

sf::Time ClockWrapper::getElapsedTime() const
{
  sf::Clock::getElapsedTime();
}

sf::Time ClockWrapper::restart()
{
  sf::Clock::restart();
}
