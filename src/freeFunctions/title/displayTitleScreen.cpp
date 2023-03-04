#include "../../../include/wrappers/iRenderWindow.hpp"
#include "../../../include/wrappers/iSprite.hpp"

void displayTitleScreen(IRenderWindow &window, const ISprite &background)
{
  window.clear();
  window.draw(background);
}
