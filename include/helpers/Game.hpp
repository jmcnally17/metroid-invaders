#ifndef GAME_HPP
#define GAME_HPP

#include "./game/ICollision.hpp"
#include "../adaptors/ISound.hpp"
#include "../adaptors/IClock.hpp"

class Game
{
public:
  void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText) const;
  void adjustView(IRenderWindow &window, int windowWidth, int windowHeight) const;
  void play(bool &isPlaying, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const;
};

#endif
