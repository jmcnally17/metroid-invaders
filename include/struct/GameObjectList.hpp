#ifndef GAME_OBJECT_LIST_HPP
#define GAME_OBJECT_LIST_HPP

#include "../models/IBunker.hpp"
#include "../models/IGunship.hpp"
#include "../models/IGunshipLaser.hpp"
#include "../models/IMetroid.hpp"
#include "../models/IMetroidLaser.hpp"
#include "../models/IRidley.hpp"

struct GameObjectList {
  std::array<IBunker*, 4> bunkers;
  IGunship *gunship;
  IGunshipLaser *gunshipLaser;
  std::array<std::array<IMetroid*, 11>, 5> metroids;
  std::array<IMetroidLaser*, 3> metroidLasers;
  IRidley *ridley;
};

#endif
