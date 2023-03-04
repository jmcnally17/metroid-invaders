#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iSprite.hpp"
#include "../../../include/wrappers/iText.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText)
{
  window.clear();
  window.draw(background);
  window.draw(titleText);
  window.draw(instructionsText);
  window.display();
}
