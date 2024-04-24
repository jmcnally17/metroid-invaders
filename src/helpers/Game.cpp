#include <fstream>
#include "../../include/Constants.hpp"
#include "../../include/helpers/Game.hpp"

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
  float widthRatio {(float)windowWidth / 96 * Constants::lengthScale};
  float heightRatio {(float)windowHeight / 84 * Constants::lengthScale};

  float newXOrigin {0};
  float newYOrigin {0};
  float newWidth {96 * Constants::lengthScale};
  float newHeight {84 * Constants::lengthScale};

  if (widthRatio < heightRatio)
  {
    newHeight *= heightRatio / widthRatio;
    newYOrigin = ((84 * Constants::lengthScale) - newHeight) / 2;
  }
  else
  {
    newWidth *= widthRatio / heightRatio;
    newXOrigin = ((96 * Constants::lengthScale) - newWidth) / 2;
  }

  sf::FloatRect visibleArea(newXOrigin, newYOrigin, newWidth, newHeight);
  window.setView(sf::View(visibleArea));
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
