#ifndef GAME_HPP
#define GAME_HPP

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
                 const std::array<IBunker*, 4> &bunkers,
                 const IGunship &gunship,
                 const ILaser &gunshipLaser,
                 const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                 const std::array<ILaser*, 3> &metroidLasers,
                 const IRidley &ridley,
                 const IText &scoreText,
                 const IText &highScoreText,
                 const IText &livesText,
                 const std::array<sf::RectangleShape, 2> &rectangles);

void monitorRidleyMovementSound(IRidley &ridley);

bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids);

void levelUp(std::unordered_map<std::string, int> &variables,
             const std::array<std::array<IMetroid*, 11>, 5> &metroids,
             const std::array<ILaser*, 3> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock);

void evaluateGunshipLaserMetroidCollision(const CollisionInterface &collision,
                                          ILaser &gunshipLaser,
                                          const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                                          std::unordered_map<std::string, int> &variables,
                                          IText &scoreText,
                                          IText &highScoreText);

void evaluateGunshipLaserRidleyCollision(const CollisionInterface &collision,
                                         ILaser &gunshipLaser,
                                         IRidley &ridley,
                                         std::unordered_map<std::string, int> &variables,
                                         IText &scoreText,
                                         IText &highScoretext);

void evaluateGunshipLaserBunkerCollision(const CollisionInterface &collision, ILaser &gunshipLaser, std::array<IBunker*, 4> &bunkers);

void evaluateMetroidLaserBunkerCollision(const CollisionInterface &collision, const std::array<ILaser*, 3> &metroidLasers, std::array<IBunker*, 4> &bunkers);

void evaluateGunshipMetroidLaserCollision(const CollisionInterface &collision,
                                          IGunship &gunship,
                                          const std::array<ILaser*, 3> &metroidLasers,
                                          ILaser &gunshipLaser,
                                          IText &livesText);

bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids);

void moveGunship(IGunship &gunship, float x);

void moveGunshipLaser(ILaser &gunshipLaser);

void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::array<ISound*, 4> &sounds);

void moveMetroidLasers(const std::array<ILaser*, 3> &metroidLasers);

void moveRidley(IRidley &ridley);

void fireGunshipLaser(IGunship &gunship);

void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<ILaser*, 3> &metroidLasers);

void spawnRidley(IRidley &ridley);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, ISound &battleTheme, ISound &creditsTheme);

void updateHighScore(std::unordered_map<std::string, int> &variables, IText &scoreText, IText &highScoreText);

#endif
