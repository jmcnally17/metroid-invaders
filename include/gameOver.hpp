#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"
#include "./models/iInvader.hpp"

void displayGameOverScreen(IRenderWindow &window, IText &gameOverText, IText &playAgainText);

void playAgain(bool &isPlaying, bool &gameOver, ILaserCannon &cannon, ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders);

#endif
