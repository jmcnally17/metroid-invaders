#ifndef RIDLEY_MANAGER_HPP
#define RIDLEY_MANAGER_HPP

#include "./IRidleyManager.hpp"

class RidleyManager : public IRidleyManager
{
public:
  void monitorRidleyMovementSound(IRidley &ridley) const override;
  void spawnRidley(IRidley &ridley) const override;
  void moveRidley(IRidley &ridley) const override;
};

#endif
