#ifndef GAME_HPP
#define GAME_HPP

#include "./game/ICollision.hpp"
#include "../adaptors/ISound.hpp"
#include "../adaptors/IClock.hpp"

class Game
{
public:
  Game(ICollision &collision);
  void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText) const;
  void adjustView(IRenderWindow &window, int windowWidth, int windowHeight) const;
  void checkForCollisions(const std::array<IBunker*, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid*, 11>, 5> &metroids, const std::array<IMetroidLaser*, 3> &metroidLasers, IRidley &ridley, const std::unordered_map<std::string, IText*> &textObjects, std::unordered_map<std::string, int> &variables) const;
  void play(bool &isPlaying, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const;
  
private:
  ICollision &collision_;
};

#endif
