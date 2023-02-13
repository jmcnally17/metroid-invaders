#include "../../include/wrappers/iRenderWindow.hpp"
#include "../../include/wrappers/iText.hpp"

void displayGameOverScreen(IRenderWindow &window, IText &gameOverText)
{
  window.clear();
  window.draw(gameOverText);
  window.display();
}
