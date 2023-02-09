#ifndef I_CLOCK_HPP
#define I_CLOCK_HPP

#include <SFML/Graphics.hpp>

class IClock
{
public:
  virtual sf::Time getElapsedTime() const = 0;
  virtual sf::Time restart() = 0;
};

#endif
