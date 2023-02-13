#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iText.hpp"

void displayGameOverScreen(IRenderWindow &window, IText &gameOverText, IText &playAgainText)
{
  window.clear();
  window.draw(gameOverText);
  window.draw(playAgainText);
  window.display();
}
