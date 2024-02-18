#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "../models/IBunker.hpp"
#include "../models/IGunship.hpp"
#include "../models/IGunshipLaser.hpp"
#include "../models/IMetroid.hpp"
#include "../models/IMetroidLaser.hpp"
#include "../models/IRidley.hpp"
#include "../adaptors/IText.hpp"

class Collision
{
public:
  static void checkForCollision(const std::array<IBunker*, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers, IRidley &ridley, const std::unordered_map<std::string, IText*> &textObjects, std::unordered_map<std::string, int> &variables);
  static void checkGunshipLaserBunkerCollision(IGunshipLaser &gunshipLaser, const std::array<IBunker*, 4> &bunkers);
  static void checkGunshipLaserMetroidCollision(IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects);
  static void checkGunshipLaserRidleyCollision(IGunshipLaser &gunshipLaser, IRidley &ridley, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects);
  static void checkGunshipMetroidLaserCollision(IGunship &gunship, const std::array<IMetroidLaser*, 3> &metroidLasers, IGunshipLaser &gunshipLaser, const std::unordered_map<std::string, IText*> &textObjects);
  static void checkMetroidLaserBunkerCollision(const std::array<IMetroidLaser*, 3> &metroidLasers, const std::array<IBunker*, 4> &bunkers);
};

#endif
