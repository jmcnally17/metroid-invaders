#ifndef I_INVADER_HPP
#define I_INVADER_HPP

#include "./objectInterface.hpp"

class IInvader : public ObjectInterface
{
public:
  virtual sf::Vector2f getOriginalPosition() const = 0;
  virtual void setPosition(const sf::Vector2f &position) = 0;
  virtual bool isAlive() const = 0;
  virtual void die() = 0;
  virtual void move() = 0;
  virtual bool hasJustMovedDown() const = 0;
  virtual void resurrect() = 0;
  virtual void reset() = 0;
  virtual int getPoints() const = 0;
};

#endif
