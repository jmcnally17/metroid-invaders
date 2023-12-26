#include "../../../include/adaptors/IRenderWindow.hpp"
#include "../../../include/adaptors/ISprite.hpp"
#include "../../../include/adaptors/IText.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background, const IText &titleText, const IText &instructionsText)
{
  window.clear();
  window.draw(background);
  window.draw(titleText);
  window.draw(instructionsText);
  window.display();
}
