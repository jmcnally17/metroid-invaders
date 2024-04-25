#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "../adaptors/SpriteAdaptor.hpp"
#include "../adaptors/TextAdaptor.hpp"
#include "../adaptors/SoundAdaptor.hpp"
#include "../models/IBunker.hpp"
#include "../models/GunshipLaser.hpp"
#include "../models/Gunship.hpp"
#include "../models/IMetroid.hpp"
#include "../models/IMetroidLaser.hpp"
#include "../models/Ridley.hpp"
#include "../struct/GameObjectList.hpp"

class Factory
{
public:
  static std::unordered_map<std::string, ISprite*> makeBackgrounds();
  static std::unordered_map<std::string, IText*> makeTextObjects();
  static std::unordered_map<std::string, ISound*> makeThemes();
  static GameObjectList makeGameObjects();
  static std::array<ISound*, 4> makeMetroidSounds();
  static std::array<sf::RectangleShape, 2> makeRectangles();
  
private:
  static std::array<IBunker*, 4> makeBunkers();
  static GunshipLaser *makeGunshipLaser();
  static Gunship *makeGunship(GunshipLaser *gunshipLaser);
  static std::array<std::array<IMetroid*, 11>, 5> makeMetroids();
  static std::array<IMetroidLaser*, 3> makeMetroidLasers();
  static Ridley *makeRidley();
  static SpriteAdaptor *makeBackground(std::string fileName);
  static TextAdaptor *makeText(std::string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y);
  static SoundAdaptor *makeTheme(std::string fileName);
};

#endif
