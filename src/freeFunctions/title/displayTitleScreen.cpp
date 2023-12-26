#include "../../../include/wrappers/IRenderWindow.hpp"
#include "../../../include/wrappers/ISprite.hpp"
#include "../../../include/wrappers/IText.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText)
{
  window.clear();
  window.draw(background);
  window.draw(titleText);
  window.draw(instructionsText);
  window.display();
}
