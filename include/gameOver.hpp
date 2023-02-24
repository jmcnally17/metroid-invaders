#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iText.hpp"
#include "./wrappers/iClock.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"
#include "./models/iMetroid.hpp"

void displayGameOverScreen(IRenderWindow &window, const IText &gameOverText, const IText &scoreText, const IText &playAgainText);

void playAgain(bool &isPlaying,
               bool &gameOver,
               ILaserCannon &cannon,
               ILaser &laser,
               const std::vector<std::vector<IMetroid *>> &metroids,
               const std::vector<ILaser *> &metroidLasers,
               int &interval,
               int &step,
               int &soundCounter,
               int &level,
               int &score,
               IText &scoretext,
               IText &livesText,
               IClock &clock);

#endif
