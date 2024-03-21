#ifndef CLOCK_ADAPTOR_HPP
#define CLOCK_ADAPTOR_HPP

#include "./IClock.hpp"

class ClockAdaptor : public IClock, public sf::Clock
{
public:
  sf::Time getElapsedTime() const override;
  sf::Time restart() override;
};

#endif
