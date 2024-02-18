#include "../../include/helpers/Game.hpp"

Game::Game(ICollision &collision) : collision_(collision){}

void Game::checkForCollisions(const std::array<IBunker *, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid *, 11>, 5> &metroids, const std::array<IMetroidLaser *, 3> &metroidLasers, IRidley &ridley, const std::unordered_map<std::string, IText *> &textObjects, std::unordered_map<std::string, int> &variables) const
{
  collision_.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
  collision_.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
  collision_.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
  collision_.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
  collision_.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}
