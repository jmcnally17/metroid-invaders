#include "../../../include/adaptors/IRenderWindow.hpp"
#include "../../../include/adaptors/IText.hpp"

void displayGameOverScreen(IRenderWindow &window, const std::unordered_map<std::string, IText*> &textObjects)
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
