#ifndef END_GAME_HPP
#define END_GAME_HPP

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
                  const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  const std::array<ILaser*, 3> &metroidLasers,
                  IRidley &ridley,
                  const std::array<IBunker*, 4> &bunkers);

void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables);

void resetInformationObjects(IText &scoreText, IText &livesText, ISound &creditsTheme, ISound &battleTheme, IClock &movementClock);

#endif
