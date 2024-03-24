#include "../include/adaptors/RenderWindowAdaptor.hpp"
#include "../include/adaptors/ClockAdaptor.hpp"
#include "../include/helpers/Factory.hpp"
#include "../include/helpers/Game.hpp"
#include "../include/helpers/game/Collision.hpp"
#include "../include/helpers/game/GameObjectManager.hpp"
#include "../include/helpers/game/GunshipManager.hpp"
#include "../include/helpers/game/LevelManager.hpp"
#include "../include/helpers/game/MetroidManager.hpp"
#include "../include/helpers/game/RidleyManager.hpp"
#include "../include/helpers/Graphics.hpp"

int main()
{
  // set up the game window
  RenderWindowAdaptor window(sf::VideoMode(1536, 1344), "Metroid Invaders");
  
  ClockAdaptor frameClock;
  
  // backgrounds
  std::unordered_map<std::string, ISprite*> backgrounds {Factory::makeBackgrounds()};
  
  // text objects
  std::unordered_map<std::string, IText*> textObjects {Factory::makeTextObjects()};
  
  // audio objects
  std::unordered_map<std::string, ISound*> themes {Factory::makeThemes()};
  
  // game objects
  std::array<IBunker*, 4> bunkers {Factory::makeBunkers()};
  GunshipLaser gunshipLaser {Factory::makeGunshipLaser()};
  Gunship gunship {Factory::makeGunship(gunshipLaser)};
  std::array<std::array<IMetroid*, 11>, 5> metroids {Factory::makeMetroids()};
  std::array<IMetroidLaser*, 3> metroidLasers {Factory::makeMetroidLasers()};
  Ridley ridley {Factory::makeRidley()};
  std::array<ISound*, 4> metroidSounds {Factory::makeMetroidSounds()};
  std::array<sf::RectangleShape, 2> rectangles {Factory::makeRectangles()};
  ClockAdaptor movementClock;
  
  // game variables
  std::unordered_map<std::string, int> variables {
    {"soundCounter", 0},
    {"interval", 665},
    {"step", 1},
    {"level", 1},
    {"score", 0},
    {"highScore", 0},
  };
  
  // helpers
  Collision *collision {new Collision()};
  Graphics graphics;
  Game game;
  GunshipManager *gunshipManager {new GunshipManager()};
  LevelManager *levelManager {new LevelManager()};
  MetroidManager *metroidManager {new MetroidManager()};
  RidleyManager *ridleyManager {new RidleyManager};
  GameObjectManager gameObjectManager(collision, gunshipManager, levelManager, metroidManager, ridleyManager);

  // final setup
  bool isPlaying {false};
  bool gameOver {false};
  game.pullHighScore(variables, *textObjects["highScore"]);
  auto titleTheme {themes.find("title")->second};
  titleTheme->play();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window.close();
      }
      else if (event.type == sf::Event::Resized)
      {
        game.adjustView(window, event.size.width, event.size.height);
      }
    }

    if (frameClock.getElapsedTime().asMicroseconds() >= 6250)
    {
      if (isPlaying)
      {
        graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
        gameObjectManager.implementGameObjects(bunkers, gunship, gunshipLaser, metroids, metroidLasers, metroidSounds, ridley, textObjects, themes, variables, isPlaying, gameOver, movementClock);
      }
      else if (gameOver)
      {
        graphics.displayGameOverScreen(window, textObjects);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
          levelManager->resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
          levelManager->resetValues(isPlaying, gameOver, variables);
          levelManager->resetInformationObjects(textObjects, themes, movementClock);
        }
      }
      else
      {
        graphics.displayTitleScreen(window, backgrounds, textObjects);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
          game.play(isPlaying, themes, movementClock);
        }
      }
      frameClock.restart();
    }
  }

  return 0;
}
