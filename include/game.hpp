#ifndef GAME_HPP
#define GAME_HPP

#include "./adaptors/IRenderWindow.hpp"
#include "./adaptors/ISound.hpp"
#include "./adaptors/IClock.hpp"
#include "./adaptors/IText.hpp"
#include "./models/IBunker.hpp"
#include "./models/IGunship.hpp"
#include "./models/IGunshipLaser.hpp"
#include "./models/IMetroidLaser.hpp"
#include "./models/IMetroid.hpp"
#include "./models/IRidley.hpp"

void drawObjects(IRenderWindow &window,
                 const std::unordered_map<std::string, ISprite*> &backgrounds,
                 const std::array<IBunker*, 4> &bunkers,
                 const IGunship &gunship,
                 const IGunshipLaser &gunshipLaser,
                 const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                 const std::array<IMetroidLaser*, 3> &metroidLasers,
                 const IRidley &ridley,
                 const std::unordered_map<std::string, IText*> &textObjects,
                 const std::array<sf::RectangleShape, 2> &rectangles);

void monitorRidleyMovementSound(IRidley &ridley);

bool areMetroidsDead(const std::array<std::array<IMetroid*, 11>, 5> &metroids);

void levelUp(std::unordered_map<std::string, int> &variables,
             const std::array<std::array<IMetroid*, 11>, 5> &metroids,
             const std::array<IMetroidLaser*, 3> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock);

bool haveMetroidsInvaded(const std::array<std::array<IMetroid*, 11>, 5> &metroids);

void moveGunship(IGunship &gunship, int direction);

void moveGunshipLaser(IGunshipLaser &gunshipLaser);

void moveMetroids(const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  IClock &movementClock,
                  std::unordered_map<std::string, int> &variables,
                  std::array<ISound*, 4> &sounds);

void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers);

void moveRidley(IRidley &ridley);

void fireGunshipLaser(IGunship &gunship);

void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers);

void spawnRidley(IRidley &ridley);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, std::unordered_map<std::string, ISound*> &themes);

void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects);

#endif
