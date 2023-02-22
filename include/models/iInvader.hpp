#ifndef I_INVADER_HPP
#define I_INVADER_HPP

#include <vector>
#include "./objectInterface.hpp"
#include "./iLaser.hpp"

class IInvader : public ObjectInterface
{
public:
  IInvader();
  IInvader(float width, float height, float x, float y, ISprite *sprite);
  virtual sf::Vector2f getOriginalPosition() const = 0;
  virtual bool isAlive() const = 0;
  virtual void die() = 0;
  virtual void move() = 0;
  virtual bool hasJustMovedDown() const = 0;
  virtual void resurrect() = 0;
  virtual int getPoints() const = 0;
  virtual int getDirection() const = 0;
  virtual void changeDirection() = 0;
  virtual void shoot(const std::vector<ILaser *> &lasers) const = 0;
};

#endif
