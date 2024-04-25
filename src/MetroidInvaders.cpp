#include "../include/adaptors/RenderWindowAdaptor.hpp"
#include "../include/adaptors/ClockAdaptor.hpp"
#include "../include/Constants.hpp"
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
  // set up the game window and game clock
  RenderWindowAdaptor window(sf::VideoMode(96 * Constants::LENGTH_SCALE, 84 * Constants::LENGTH_SCALE), "Metroid Invaders");
  ClockAdaptor gameClock;
  
  // backgrounds
  std::unordered_map<std::string, ISprite*> backgrounds {Factory::makeBackgrounds()};
  
  // text objects
  std::unordered_map<std::string, IText*> textObjects {Factory::makeTextObjects()};
  
  // audio objects
  std::unordered_map<std::string, ISound*> themes {Factory::makeThemes()};
  
  // game objects
  GameObjectList gameObjects {Factory::makeGameObjects()};
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

  // final setup for the title screen
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
    
    if (isPlaying) {
      graphics.drawObjects(window, backgrounds, gameObjects, textObjects, rectangles);
    }

    if (gameClock.getElapsedTime().asMicroseconds() >= Constants::FRAME_LENGTH)
    {
      if (isPlaying)
      {
        gameObjectManager.implementGameObjects(gameObjects, metroidSounds, textObjects, themes, variables, isPlaying, gameOver, movementClock);
      }
      else if (gameOver)
      {
        graphics.displayGameOverScreen(window, textObjects);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
          levelManager->reset(gameObjects, isPlaying, gameOver, variables, textObjects, themes, movementClock);
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
      gameClock.restart();
    }
  }

  return 0;
}
