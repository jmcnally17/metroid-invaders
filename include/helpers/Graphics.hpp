#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "../models/IBunker.hpp"
#include "../models/IGunship.hpp"
#include "../models/IGunshipLaser.hpp"
#include "../models/IMetroid.hpp"
#include "../models/IMetroidLaser.hpp"
#include "../models/IRidley.hpp"
#include "../adaptors/IRenderWindow.hpp"
#include "../adaptors/ISprite.hpp"
#include "../adaptors/IText.hpp"

class Graphics
{
public:
  void displayTitleScreen(IRenderWindow &window, const std::unordered_map<std::string, ISprite*> &backgrounds, const std::unordered_map<std::string, IText*> &textObjects) const;
  void drawObjects(IRenderWindow &window,
                   const std::unordered_map<std::string, ISprite*> &backgrounds,
                   const std::array<IBunker*, 4> &bunkers,
                   const IGunship &gunship,
                   const IGunshipLaser &gunshipLaser,
                   const std::array<std::array<IMetroid*, 11>, 5> &metroids,
                   const std::array<IMetroidLaser*, 3> &metroidLasers,
                   const IRidley &ridley,
                   const std::unordered_map<std::string, IText*> &textObjects,
                   const std::array<sf::RectangleShape, 2> &rectangles) const;
  void displayGameOverScreen(IRenderWindow &window, const std::unordered_map<std::string, IText*> &textObjects) const;
};

#endif
