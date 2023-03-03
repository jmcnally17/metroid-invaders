#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"
#include "./models/iMetroid.hpp"
#include "./models/iRidley.hpp"
#include "./interfaces/collisionInterface.hpp"

void drawObjects(IRenderWindow &window,
                 const ILaserCannon &cannon,
                 const ILaser &laser,
                 const std::vector<std::vector<IMetroid *>> &metroids,
                 const std::vector<ILaser *> &metroidLasers,
                 const IRidley &ridley,
                 const IText &scoreText,
                 const IText &livesText);

void monitorRidleyMovementSound(IRidley &ridley);

bool areMetroidsDead(const std::vector<std::vector<IMetroid *>> &metroids);

void levelUp(int &level,
             int &interval,
             int &step,
             int &soundCounter,
             const std::vector<std::vector<IMetroid *>> &metroids,
             const std::vector<ILaser *> &metroidLasers,
             IRidley &ridley,
             IClock &clock);

void evaluateLaserMetroidCollision(const CollisionInterface &collision,
                                   ILaser &laser,
                                   const std::vector<std::vector<IMetroid *>> &metroids,
                                   int &score, IText &scoreText);

void evaluateLaserRidleyCollision(ILaser &cannonLaser, IRidley &ridley, int &score, IText &scoreText);

bool hasCannonBeenHit(const CollisionInterface &collision, const ILaserCannon &cannon, const std::vector<ILaser *> &metroidLasers);

void decreaseCannonLives(ILaserCannon &cannon, ILaser &cannonLaser, const std::vector<ILaser *> &metroidLasers, IText &livesText);

bool haveMetroidsInvaded(const std::vector<std::vector<IMetroid *>> &metroids);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void moveMetroids(const std::vector<std::vector<IMetroid *>> &metroids,
                  IClock &clock,
                  int &interval,
                  int &step,
                  std::vector<ISound *> &sounds,
                  int &soundCounter);

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers);

void moveRidley(IRidley &ridley);

void fireLaser(ILaserCannon &cannon);

void shootMetroidLaser(const std::vector<std::vector<IMetroid *>> &metroids, const std::vector<ILaser *> &lasers);

void spawnRidley(IRidley &ridley);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, int score, IText &scoreText);

#endif
