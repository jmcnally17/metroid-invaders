#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iGunship.hpp"
#include "./models/iLaser.hpp"
#include "./models/iMetroid.hpp"
#include "./models/iRidley.hpp"
#include "./interfaces/collisionInterface.hpp"

void drawObjects(IRenderWindow &window,
                 const IGunship &gunship,
                 const ILaser &gunshipLaser,
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

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision,
                                          ILaser &gunshipLaser,
                                          const std::vector<std::vector<IMetroid *>> &metroids,
                                          int &score, IText &scoreText);

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision, ILaser &gunshipLaser, IRidley &ridley, int &score, IText &scoreText);

void evaluateGunshipMetroidLaserCollision(const CollisionInterface &collision,
                                          IGunship &gunship,
                                          const std::vector<ILaser *> &metroidLasers,
                                          ILaser &gunshipLaser,
                                          IText &livesText);

bool haveMetroidsInvaded(const std::vector<std::vector<IMetroid *>> &metroids);

void moveGunship(IGunship &gunship, float x);

void moveGunshipLaser(ILaser &gunshipLaser);

void moveMetroids(const std::vector<std::vector<IMetroid *>> &metroids,
                  IClock &clock,
                  int &interval,
                  int &step,
                  std::vector<ISound *> &sounds,
                  int &soundCounter);

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers);

void moveRidley(IRidley &ridley);

void fireGunshipLaser(IGunship &gunship);

void shootMetroidLaser(const std::vector<std::vector<IMetroid *>> &metroids, const std::vector<ILaser *> &metroidLasers);

void spawnRidley(IRidley &ridley);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, int score, IText &scoreText, ISound &battleTheme);

#endif
