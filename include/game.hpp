#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"
#include "./models/iInvader.hpp"
#include "./interfaces/collisionInterface.hpp"

void drawObjects(IRenderWindow &window,
                 const ILaserCannon &cannon,
                 const ILaser &laser,
                 const std::vector<std::vector<IInvader *>> &invaders,
                 const std::vector<ILaser *> &invaderLasers,
                 const IText &scoreText,
                 const IText &livesText);

bool areInvadersDead(const std::vector<std::vector<IInvader *>> &invaders);

void levelUp(int &level,
             int &interval,
             int &step,
             int &soundCounter,
             const std::vector<std::vector<IInvader *>> &invaders,
             const std::vector<ILaser *> &invaderLasers,
             IClock &clock);

void evaluateLaserInvaderCollision(const CollisionInterface &collision,
                                   ILaser &laser,
                                   const std::vector<std::vector<IInvader *>> &invaders,
                                   int &score, IText &scoreText);

void decreaseCannonLives(ILaserCannon &cannon, ILaser &cannonLaser);

bool haveInvadersInvaded(const std::vector<std::vector<IInvader *>> &invaders);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void moveInvaders(const std::vector<std::vector<IInvader *>> &invaders,
                  IClock &clock,
                  int &interval,
                  int &step,
                  std::vector<ISound *> &sounds,
                  int &soundCounter);

void moveInvaderLasers(const std::vector<ILaser *> &invaderLasers);

void fireLaser(ILaserCannon &cannon);

void shootInvaderLaser(const std::vector<std::vector<IInvader *>> &invaders, const std::vector<ILaser *> &lasers);

void endGame(bool &isPlaying, bool &gameOver, int score, IText &scoreText);

#endif
