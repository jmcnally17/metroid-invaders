#include "../../include/helpers/Graphics.hpp"

void Graphics::displayTitleScreen(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const std::unordered_map<std::string, IText*> &textObjects) const
{
  auto titleBackground {backgrounds.find("title")->second};
  auto titleText {textObjects.find("title")->second};
  auto instructionsText {textObjects.find("instructions")->second};
  window.clear();
  window.draw(*titleBackground);
  window.draw(*titleText);
  window.draw(*instructionsText);
  window.display();
}

void Graphics::drawObjects(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const GameObjectList &gameObjects, const std::unordered_map<std::string, IText*> &textObjects, const std::array<sf::RectangleShape, 2> &rectangles) const
{
  window.clear();
  auto gameBackground {backgrounds.find("game")->second};
  window.draw(*gameBackground);
  for (auto bunker : gameObjects.bunkers)
  {
    bunker->draw(window);
  }
  gameObjects.gunship->draw(window);
  gameObjects.gunshipLaser->draw(window);
  for (auto row : gameObjects.metroids)
  {
    for (auto metroid : row)
    {
      if (metroid->isAlive())
      {
        metroid->draw(window);
      }
    }
  }
  for (auto metroidLaser : gameObjects.metroidLasers)
  {
    metroidLaser->draw(window);
  }
  gameObjects.ridley->draw(window);
  auto scoreText {textObjects.find("score")->second};
  auto highScoreText {textObjects.find("highScore")->second};
  auto livesText {textObjects.find("lives")->second};
  window.draw(*scoreText);
  window.draw(*highScoreText);
  window.draw(*livesText);
  for (auto rectangle : rectangles)
  {
    window.draw(rectangle);
  }
  window.display();
}

void Graphics::displayGameOverScreen(IRenderWindow &window, const std::unordered_map<std::string, IText*> &textObjects) const
{
  auto gameOverText {textObjects.find("gameOver")->second};
  auto scoreText {textObjects.find("score")->second};
  auto playAgainText {textObjects.find("playAgain")->second};
  window.clear();
  window.draw(*gameOverText);
  window.draw(*scoreText);
  window.draw(*playAgainText);
  window.display();
}
