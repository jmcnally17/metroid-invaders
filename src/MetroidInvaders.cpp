#include "../include/MetroidInvaders.hpp"
#include "../include/Title.hpp"
#include "../include/game.hpp"
#include "../include/gameOver.hpp"
#include "../include/helpers/Game.hpp"
#include "../include/helpers/Factory.hpp"
#include "../include/helpers/Graphics.hpp"
#include "../include/helpers/game/Collision.hpp"
#include "../include/adaptors/RenderWindowAdaptor.hpp"
#include "../include/adaptors/ClockAdaptor.hpp"

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
  Collision collision;
  Graphics graphics;
  Game game(collision);

  // final setup
  bool isPlaying {false};
  bool gameOver {false};
  pullHighScore(variables, *textObjects["highScore"]);
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
        adjustView(window, event.size.width, event.size.height);
      }
    }

    if (frameClock.getElapsedTime().asMicroseconds() >= 6250)
    {
      if (isPlaying)
      {
        graphics.drawObjects(window, backgrounds, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, rectangles);
        monitorRidleyMovementSound(ridley);
        if (areMetroidsDead(metroids))
        {
          levelUp(variables, metroids, metroidLasers, ridley, movementClock);
        }
        game.checkForCollisions(bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, textObjects, variables);
        if (haveMetroidsInvaded(metroids) || gunship.getLives() == 0)
        {
          endGame(isPlaying, gameOver, ridley, themes);
          updateHighScore(variables, textObjects);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
          moveGunship(gunship, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
          moveGunship(gunship, -1);
        }
        moveGunshipLaser(gunshipLaser);
        moveMetroids(metroids, movementClock, variables, metroidSounds);
        moveMetroidLasers(metroidLasers);
        moveRidley(ridley);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
          fireGunshipLaser(gunship);
        }
        shootMetroidLaser(metroids, metroidLasers);
        spawnRidley(ridley);
      }
      else if (gameOver)
      {
        displayGameOverScreen(window, textObjects);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
          resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
          resetValues(isPlaying, gameOver, variables);
          resetInformationObjects(textObjects, themes, movementClock);
        }
      }
      else
      {
        displayTitleScreen(window, backgrounds, textObjects);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
          play(isPlaying, themes, movementClock);
        }
      }
      frameClock.restart();
    }
  }

  return 0;
}
