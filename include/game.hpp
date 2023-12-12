#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iBunker.hpp"
#include "./models/iGunship.hpp"
#include "./models/iLaser.hpp"
#include "./models/iMetroid.hpp"
#include "./models/iRidley.hpp"
#include "./interfaces/collisionInterface.hpp"

void drawObjects(IRenderWindow &window,
                 const ISprite &gameBackground,
                 const std::vector<IBunker *> &bunkers,
                 const IGunship &gunship,
                 const ILaser &gunshipLaser,
                 const std::vector<std::vector<IMetroid *>> &metroids,
                 const std::vector<ILaser *> &metroidLasers,
                 const IRidley &ridley,
                 const IText &scoreText,
                 const IText &highScoreText,
                 const IText &livesText,
                 const std::vector<sf::RectangleShape> &rectangles);

void monitorRidleyMovementSound(IRidley &ridley);

bool areMetroidsDead(const std::vector<std::vector<IMetroid *>> &metroids);

void levelUp(std::unordered_map<std::string, int> &variables,
             const std::vector<std::vector<IMetroid *>> &metroids,
             const std::vector<ILaser *> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock);

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision,
                                          ILaser &gunshipLaser,
                                          const std::vector<std::vector<IMetroid *>> &metroids,
                                          std::unordered_map<std::string, int> &variables,
                                          IText &scoreText,
                                          IText &highScoreText);

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision,
                                         ILaser &gunshipLaser,
                                         IRidley &ridley,
                                         std::unordered_map<std::string, int> &variables,
                                         IText &scoreText,
                                         IText &highScoretext);

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, ILaser &gunshipLaser, std::vector<IBunker *> &bunkers);

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::vector<ILaser *> &metroidLasers, std::vector<IBunker *> &bunkers);

void evaluateGunshipMetroidLaserCollision(const CollisionInterface &collision,
                                          IGunship &gunship,
                                          const std::vector<ILaser *> &metroidLasers,
                                          ILaser &gunshipLaser,
                                          IText &livesText);

bool haveMetroidsInvaded(const std::vector<std::vector<IMetroid *>> &metroids);

void moveGunship(IGunship &gunship, float x);

void moveGunshipLaser(ILaser &gunshipLaser);

void moveMetroids(const std::vector<std::vector<IMetroid *>> &metroids,
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::vector<ISound *> &sounds);

void moveMetroidLasers(const std::vector<ILaser *> &metroidLasers);

void moveRidley(IRidley &ridley);

void fireGunshipLaser(IGunship &gunship);

void shootMetroidLaser(const std::vector<std::vector<IMetroid *>> &metroids, const std::vector<ILaser *> &metroidLasers);

void spawnRidley(IRidley &ridley);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, ISound &battleTheme, ISound &creditsTheme);

void updateHighScore(std::unordered_map<std::string, int> &variables, IText &scoreText, IText &highScoreText);

#endif
