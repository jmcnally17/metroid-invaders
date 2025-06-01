#include <fstream>
#include "../../../include/Constants.hpp"
#include "../../../include/helpers/game/LevelManager.hpp"

void LevelManager::levelUp(std::unordered_map<std::string, int> &variables, const GameObjectList &gameObjects, IClock &movementClock) const
{
  variables["level"]++;
  variables["interval"] = 665;
  variables["step"] = 1;
  variables["soundCounter"] = 0;
  for (auto row : gameObjects.metroids)
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
      float levelUpShift = (variables["level"] - 1) * 2.625 * Constants::LENGTH_SCALE;
      sf::Vector2f levelUpPosition(originalXPosition, originalYPosition + levelUpShift);
      metroid->setPosition(levelUpPosition);
    }
  }
  for (auto metroidLaser : gameObjects.metroidLasers)
  {
    metroidLaser->resetPosition();
  }
  gameObjects.ridley->reset();
  gameObjects.ridley->stopMovementSoundIfPlaying();
  movementClock.restart();
}

void LevelManager::endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, const std::unordered_map<std::string, ISound*> &themes) const
{
  isPlaying = false;
  gameOver = true;
  ridley.stopMovementSoundIfPlaying();
  auto battleTheme {themes.find("battle")->second};
  auto creditsTheme {themes.find("credits")->second};
  battleTheme->stop();
  creditsTheme->play();
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
  scoreText->setPosition(sf::Vector2f(48 * Constants::LENGTH_SCALE, 37.5 * Constants::LENGTH_SCALE));
  sf::FloatRect scoreTextRect {scoreText->getLocalBounds()};
  scoreText->setOrigin(scoreTextRect.size.x / 2, 0);
}

void LevelManager::reset(const GameObjectList &gameObjects, bool &isPlaying, bool &gameOver, std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock) const
{
  resetObjects(gameObjects);
  resetValues(isPlaying, gameOver, variables);
  resetInformationObjects(textObjects, themes, movementClock);
}

void LevelManager::resetObjects(const GameObjectList &gameObjects) const
{
  gameObjects.gunship->reset();
  gameObjects.gunshipLaser->resetPosition();
  for (auto metroidRow : gameObjects.metroids)
  {
    for (auto metroid : metroidRow)
    {
      metroid->reset();
    }
  }
  for (auto metroidLaser : gameObjects.metroidLasers)
  {
    metroidLaser->resetPosition();
  }
  gameObjects.ridley->reset();
  for (auto bunker : gameObjects.bunkers)
  {
    bunker->reset();
  }
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
  scoreText->setPosition(sf::Vector2f(1.25 * Constants::LENGTH_SCALE, 0));
  scoreText->setOrigin(0, 0);
  livesText->setString("Lives: 3");
  creditsTheme->stop();
  battleTheme->play();
  movementClock.restart();
}
