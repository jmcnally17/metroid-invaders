#ifndef GAME_HPP
#define GAME_HPP

#include "./game/ICollision.hpp"

class Game
{
public:
  Game(ICollision &collision);
  void checkForCollisions(const std::array<IBunker*, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers, IRidley &ridley, const std::unordered_map<std::string, IText*> &textObjects, std::unordered_map<std::string, int> &variables) const;
  
private:
  ICollision &collision_;
};

#endif
