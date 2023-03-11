#ifndef END_GAME_HPP
#define END_GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iText.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./models/iGunship.hpp"
#include "./models/iLaser.hpp"
#include "./models/iMetroid.hpp"
#include "./models/iRidley.hpp"
#include "./models/iBunker.hpp"

void displayGameOverScreen(IRenderWindow &window, const IText &gameOverText, const IText &scoreText, const IText &playAgainText);

void resetObjects(IGunship &gunship, ILaser &gunshipLaser,
                  const std::vector<std::vector<IMetroid *>> &metroids,
                  const std::vector<ILaser *> &metroidLasers,
                  IRidley &ridley,
                  const std::vector<IBunker *> &bunkers);

void resetValues(bool &isPlaying, bool &gameOver, int &interval, int &step, int &soundCounter, int &level, int &score);

void resetInformationObjects(IText &scoreText, IText &livesText, ISound &creditsTheme, ISound &battleTheme, IClock &movementClock);

#endif
