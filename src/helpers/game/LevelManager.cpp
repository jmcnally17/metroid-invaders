#include <fstream>
#include "../../../include/helpers/game/LevelManager.hpp"

void LevelManager::levelUp(std::unordered_map<std::string, int> &variables,
             const std::array<std::array<IMetroid*, 11>, 5> &metroids,
             const std::array<IMetroidLaser*, 3> &metroidLasers,
             IRidley &ridley,
             IClock &movementClock) const
{
  variables["level"]++;
  variables["interval"] = 665;
  variables["step"] = 1;
  variables["soundCounter"] = 0;
  for (auto row : metroids)
  {
    for (auto metroid : row)
    {
      metroid->resurrect();
      if (metroid->getDirection() == -1)
      {
        metroid->changeDirection();
      }
      sf::Vector2f originalPosition {metroid->getOriginalPosition()};
      float originalXPosition {originalPosition.x};
      float originalYPosition {originalPosition.y};
      float levelUpShift = (variables["level"] - 1) * 42;
      sf::Vector2f levelUpPosition(originalXPosition, originalYPosition + levelUpShift);
      metroid->setPosition(levelUpPosition);
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->resetPosition();
  }
  ridley.reset();
  ridley.stopMovementSoundIfPlaying();
  movementClock.restart();
}

void LevelManager::endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, std::unordered_map<std::string, ISound*> &themes) const
{
  isPlaying = false;
  gameOver = true;
  ridley.stopMovementSoundIfPlaying();
  auto battleTheme {themes.find("battle")->second};
  auto creditsTheme {themes.find("credits")->second};
  battleTheme->stop();
  creditsTheme->play();
}

void LevelManager::resetObjects(IGunship &gunship, IGunshipLaser &gunshipLaser,
                  const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                  const std::array<IMetroidLaser*, 3> &metroidLasers,
                  IRidley &ridley,
                  const std::array<IBunker*, 4> &bunkers) const
{
  gunship.reset();
  gunshipLaser.resetPosition();
  for (auto metroidRow : metroids)
  {
    for (auto metroid : metroidRow)
    {
      metroid->reset();
    }
  }
  for (auto metroidLaser : metroidLasers)
  {
    metroidLaser->resetPosition();
  }
  ridley.reset();
  for (auto bunker : bunkers)
  {
    bunker->reset();
  }
}

void LevelManager::updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects) const
{
  auto scoreText {textObjects.find("score")->second};
  auto highScoreText {textObjects.find("highScore")->second};
  if (variables["score"] > variables["highScore"])
  {
    variables["highScore"] = variables["score"];
    std::ofstream highScoreWriteFile("highScore.txt");
    highScoreWriteFile << variables["score"];
    highScoreWriteFile.close();
    scoreText->setString("New High Score! " + std::to_string(variables["score"]) + " points");
    highScoreText->setString("High Score: " + std::to_string(variables["score"]));
  }
  else
  {
    scoreText->setString("You scored " + std::to_string(variables["score"]) + " points");
  }
  scoreText->setPosition(sf::Vector2f(768, 600));
  sf::FloatRect scoreTextRect {scoreText->getLocalBounds()};
  scoreText->setOrigin(scoreTextRect.width / 2, 0);
}

void LevelManager::resetValues(bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables) const
{
  isPlaying = true;
  gameOver = false;
  variables["interval"] = 665;
  variables["step"] = 1;
  variables["soundCounter"] = 0;
  variables["level"] = 1;
  variables["score"] = 0;
}

void LevelManager::resetInformationObjects(const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const
{
  auto scoreText {textObjects.find("score")->second};
  auto livesText {textObjects.find("lives")->second};
  auto creditsTheme {themes.find("credits")->second};
  auto battleTheme {themes.find("battle")->second};
  scoreText->setString("Score: 0");
  scoreText->setPosition(sf::Vector2f(20, 0));
  scoreText->setOrigin(0, 0);
  livesText->setString("Lives: 3");
  creditsTheme->stop();
  battleTheme->play();
  movementClock.restart();
}
