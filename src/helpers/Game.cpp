#include <fstream>
#include "../../include/helpers/Game.hpp"

Game::Game(ICollision &collision) : collision_(collision){}

void Game::pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText) const
{
  std::string highScoreString;
  std::ifstream highScoreFile("highScore.txt");
  getline(highScoreFile, highScoreString);
  highScoreFile.close();
  if (!(highScoreString == ""))
  {
    variables["highScore"] = std::stoi(highScoreString);
    highScoreText.setString("HighScore: " + highScoreString);
  }
}

void Game::adjustView(IRenderWindow &window, int windowWidth, int windowHeight) const
{
  float widthRatio {(float)windowWidth / 1536};
  float heightRatio {(float)windowHeight / 1334};

  float newXOrigin {0};
  float newYOrigin {0};
  float newWidth {1536};
  float newHeight {1344};

  if (widthRatio < heightRatio)
  {
    newHeight *= heightRatio / widthRatio;
    newYOrigin = (1344 - newHeight) / 2;
  }
  else
  {
    newWidth *= widthRatio / heightRatio;
    newXOrigin = (1536 - newWidth) / 2;
  }

  sf::FloatRect visibleArea(newXOrigin, newYOrigin, newWidth, newHeight);
  window.setView(sf::View(visibleArea));
}

void Game::checkForCollisions(const std::array<IBunker *, 4> &bunkers, IGunship &gunship, IGunshipLaser &gunshipLaser, const std::array<std::array<IMetroid *, 11>, 5> &metroids, const std::array<IMetroidLaser *, 3> &metroidLasers, IRidley &ridley, const std::unordered_map<std::string, IText *> &textObjects, std::unordered_map<std::string, int> &variables) const
{
  collision_.checkGunshipLaserMetroidCollision(gunshipLaser, metroids, variables, textObjects);
  collision_.checkGunshipLaserRidleyCollision(gunshipLaser, ridley, variables, textObjects);
  collision_.checkGunshipLaserBunkerCollision(gunshipLaser, bunkers);
  collision_.checkMetroidLaserBunkerCollision(metroidLasers, bunkers);
  collision_.checkGunshipMetroidLaserCollision(gunship, metroidLasers, gunshipLaser, textObjects);
}

void Game::play(bool &isPlaying, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const
{
  auto titleTheme {themes.find("title")->second};
  auto battleTheme {themes.find("battle")->second};
  isPlaying = true;
  titleTheme->stop();
  battleTheme->play();
  movementClock.restart();
}
