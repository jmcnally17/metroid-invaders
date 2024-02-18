#ifndef MOCK_COLLISION_HPP
#define MOCK_COLLISION_HPP

#include <gmock/gmock.h>
#include "../../../include/helpers/game/ICollision.hpp"

class MockCollision : public ICollision
{
public:
  MOCK_METHOD(void, checkGunshipLaserBunkerCollision, (IGunshipLaser &gunshipLaser, (const std::array<IBunker*, 4>) &bunkers), (const));
  MOCK_METHOD(void, checkGunshipLaserMetroidCollision, (IGunshipLaser &gunshipLaser, (const std::array<std::array<IMetroid*, 11>, 5>) &metroids, (std::unordered_map<std::string, int>) &variables, (const std::unordered_map<std::string, IText*>) &textObjects), (const));
  MOCK_METHOD(void, checkGunshipLaserRidleyCollision, (IGunshipLaser &gunshipLaser, IRidley &ridley, (std::unordered_map<std::string, int>) &variables, (const std::unordered_map<std::string, IText*>) &textObjects), (const));
  MOCK_METHOD(void, checkGunshipMetroidLaserCollision, (IGunship &gunship, (const std::array<IMetroidLaser*, 3>) &metroidLasers, IGunshipLaser &gunshipLaser, (const std::unordered_map<std::string, IText*>) &textObjects), (const));
  MOCK_METHOD(void, checkMetroidLaserBunkerCollision, ((const std::array<IMetroidLaser*, 3>) &metroidLasers, (const std::array<IBunker*, 4>) &bunkers), (const));
};

#endif
