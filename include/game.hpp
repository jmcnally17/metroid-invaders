#ifndef GAME_FUNCTIONS_HPP
#define GAME_FUNCTIONS_HPP

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

void levelUp(std::unordered_map<std::string, int> &variables,
             const std::array<std::array<IMetroid*, 11>, 5> &metroids,
             const std::array<IMetroidLaser*, 3> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock);

void moveGunship(IGunship &gunship, int direction);

void moveGunshipLaser(IGunshipLaser &gunshipLaser);

void moveMetroidLasers(const std::array<IMetroidLaser*, 3> &metroidLasers);

void fireGunshipLaser(IGunship &gunship);

void shootMetroidLaser(const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers);

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, std::unordered_map<std::string, ISound*> &themes);

void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects);

#endif
