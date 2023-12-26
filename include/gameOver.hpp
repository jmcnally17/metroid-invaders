#ifndef END_GAME_HPP
#define END_GAME_HPP

#include "./adaptors/IRenderWindow.hpp"
#include "./adaptors/IText.hpp"
#include "./adaptors/ISound.hpp"
#include "./adaptors/IClock.hpp"
#include "./models/IGunship.hpp"
#include "./models/IGunshipLaser.hpp"
#include "./models/IMetroid.hpp"
#include "./models/IMetroidLaser.hpp"
#include "./models/IRidley.hpp"
#include "./models/IBunker.hpp"

void displayGameOverScreen(IRenderWindow &window, const IText &gameOverText, const IText &scoreText, const IText &playAgainText);

void resetObjects(IGunship &gunship, IGunshipLaser &gunshipLaser,
                  const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  const std::array<IMetroidLaser*, 3> &metroidLasers,
                  IRidley &ridley,
                  const std::array<IBunker*, 4> &bunkers);

void resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables);

void resetInformationObjects(IText &scoreText, IText &livesText, ISound &creditsTheme, ISound &battleTheme, IClock &movementClock);

#endif
