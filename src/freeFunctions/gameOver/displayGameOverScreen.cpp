#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"

void displayGameOverScreen(IRenderWindow &window, const IText &gameOverText, const IText &scoreText, const IText &playAgainText)
{
  window.clear();
  window.draw(gameOverText);
  window.draw(scoreText);
  window.draw(playAgainText);
  window.display();
}
