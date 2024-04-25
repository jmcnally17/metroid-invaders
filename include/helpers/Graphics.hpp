#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "../struct/GameObjectList.hpp"
#include "../adaptors/IRenderWindow.hpp"
#include "../adaptors/ISprite.hpp"
#include "../adaptors/IText.hpp"

class Graphics
{
public:
  void displayTitleScreen(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const std::unordered_map<std::string, IText*> &textObjects) const;
  void drawObjects(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const GameObjectList &gameObjects, const std::unordered_map<std::string, IText*> &textObjects, const std::array<sf::RectangleShape, 2> &rectangles) const;
  void displayGameOverScreen(IRenderWindow &window, const std::unordered_map<std::string, IText*> &textObjects) const;
};

#endif
