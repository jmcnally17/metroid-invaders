#ifndef CLOCK_WRAPPER_HPP
#define CLOCK_WRAPPER_HPP

#include "./IClock.hpp"

class ClockWrapper : public IClock, public sf::Clock
{
public:
  sf::Time getElapsedTime() const override;
  sf::Time restart() override;
};

#endif
