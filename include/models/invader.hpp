#ifndef INVADER_HPP
#define INVADER_HPP

#include "./iInvader.hpp"
#include "../wrappers/iSprite.hpp"

class Invader : public IInvader
{
public:
  Invader(float x, float y, ISprite *sprite);
  float getWidth() const override;
  float getHeight() const override;
  int getPoints() const override;
  sf::Vector2f getOriginalPosition() const override;
  sf::Vector2f getPosition() const override;
  void setPosition(const sf::Vector2f &position) override;
  void draw(IRenderWindow &window) const override;
  bool isAlive() const override;
  void die() override;
  int getDirection() const override;
  void move() override;
  void changeDirection() override;
  bool hasJustMovedDown() const override;
  void resurrect() override;
  void reset() override;

private:
  sf::Vector2f originalPosition_;
  sf::Vector2f position_;
  ISprite *sprite_;
  bool alive_;
  int direction_;
  bool justMovedDown_;

protected:
  float width_;
  float height_;
  int points_;
};

#endif
