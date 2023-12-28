#include "../../../include/adaptors/IRenderWindow.hpp"
#include "../../../include/adaptors/ISprite.hpp"
#include "../../../include/adaptors/IText.hpp"

void displayTitleScreen(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const std::unordered_map<std::string, IText*> &textObjects)
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
