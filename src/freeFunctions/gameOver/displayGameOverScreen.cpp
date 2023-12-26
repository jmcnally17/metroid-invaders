#include "../../../include/adaptors/IRenderWindow.hpp"
#include "../../../include/adaptors/IText.hpp"

void displayGameOverScreen(IRenderWindow &window, const IText &gameOverText, const IText &scoreText, const IText &playAgainText)
{
  window.clear();
  window.draw(gameOverText);
  window.draw(scoreText);
  window.draw(playAgainText);
  window.display();
}
