#ifndef I_RIDLEY_MANAGER_HPP
#define I_RIDLEY_MANAGER_HPP

#include "../../models/IRidley.hpp"

class IRidleyManager
{
public:
  virtual void monitorRidleyMovementSound(IRidley &ridley) const = 0;
  virtual void spawnRidley(IRidley &ridley) const = 0;
  virtual void moveRidley(IRidley &ridley) const = 0;
};

#endif
