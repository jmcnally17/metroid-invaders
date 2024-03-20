#ifndef RIDLEY_MANAGER_HPP
#define RIDLEY_MANAGER_HPP

#include "../../models/IRidley.hpp"

class RidleyManager
{
public:
  void monitorRidleyMovementSound(IRidley &ridley) const;
  void spawnRidley(IRidley &ridley) const;
  void moveRidley(IRidley &ridley) const;
};

#endif
