#ifndef I_METROID_HPP
#define I_METROID_HPP

#include "./IGameObject.hpp"
#include "./IMetroidLaser.hpp"

class IMetroid : public IGameObject
{
public:
  virtual sf::Vector2f getOriginalPosition() const = 0;
  virtual int getPoints() const = 0;
  virtual int getDirection() const = 0;
  virtual void changeDirection() = 0;
  virtual bool isAlive() const = 0;
  virtual bool hasJustMovedDown() const = 0;
  virtual void move() = 0;
  virtual void die() = 0;
  virtual void resurrect() = 0;
  virtual void reset() = 0;
  virtual void shoot(const std::array<IMetroidLaser*, 3> &metroidLasers, int randomNumber = rand() % 10000) const = 0;
  
private:
  virtual void moveAcross() = 0;
  virtual void moveDown() = 0;
};

#endif
