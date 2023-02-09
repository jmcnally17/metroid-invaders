#ifndef TIME_WRAPPER_HPP
#define TIME_WRAPPER_HPP

#include <SFML/Graphics.hpp>
#include "./iTime.hpp"

class TimeWrapper : public ITime, public sf::Time
{
public:
  int asMilliseconds() const;
};

#endif
