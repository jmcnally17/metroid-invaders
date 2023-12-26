#include "../include/MetroidInvaders.hpp"
#include "../include/Factory.hpp"
#include "../include/Title.hpp"
#include "../include/Game.hpp"
#include "../include/GameOver.hpp"
#include "../include/adaptors/RenderWindowAdaptor.hpp"
#include "../include/adaptors/ClockAdaptor.hpp"
#include "../include/interfaces/collisionInterface.hpp"

int main()
{
  RenderWindowAdaptor window(sf::VideoMode(1536, 1344), "Metroid Invaders");
  
  ClockAdaptor frameClock;
  
  sf::Font m56;
  m56.loadFromFile("resources/fonts/MicroN56.ttf");
  sf::Color white {sf::Color::White};
  sf::Color green {sf::Color::Green};
  
  // backgrounds
  SpriteAdaptor titleBackground {Factory::makeBackground("title")};
  SpriteAdaptor gameBackground {Factory::makeBackground("game")};
  
  // text objects
  std::string titleString {"Metroid Invaders"};
  std::string instructionsString {"Press enter to play!"};
  std::string scoreString {"Score: 0"};
  std::string highScoreString {"High Score: 0"};
  std::string livesString {"Lives: 3"};
  std::string gameOverString {"Game Over"};
  std::string playAgainString {"Press p to play again"};
  TextAdaptor titleText {Factory::makeText(titleString, m56, 100, green, 0.5, 768, 100)};
  TextAdaptor instructionsText {Factory::makeText(instructionsString, m56, 50, green, 0.5, 768, 1200)};
  TextAdaptor scoreText {Factory::makeText(scoreString, m56, 50, white, 0, 20, 0)};
  TextAdaptor highScoreText {Factory::makeText(highScoreString, m56, 50, white, 0.5, 768, 0)};
  TextAdaptor livesText {Factory::makeText(livesString, m56, 50, white, 0, 1250, 0)};
  TextAdaptor gameOverText {Factory::makeText(gameOverString, m56, 153, white, 0.5, 768, 200)};
  TextAdaptor playAgainText {Factory::makeText(playAgainString, m56, 48, white, 0.5, 768, 1000)};
  
  // audio objects
  SoundAdaptor titleTheme {Factory::makeTheme("title")};
  SoundAdaptor battleTheme {Factory::makeTheme("battle")};
  SoundAdaptor creditsTheme {Factory::makeTheme("credits")};
  
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
  Collision collisionInterface;
  
  // variables
  std::unordered_map<std::string, int> variables {
    {"soundCounter", 0},
    {"interval", 665},
    {"step", 1},
    {"level", 1},
    {"score", 0},
    {"highScore", 0},
  };

  // final setup
  bool isPlaying {false};
  bool gameOver {false};
  pullHighScore(variables, highScoreText);
  titleTheme.play();

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
        drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText, rectangles);
        monitorRidleyMovementSound(ridley);
        if (areMetroidsDead(metroids))
        {
          levelUp(variables, metroids, metroidLasers, ridley, movementClock);
        }
        evaluateGunshipLaserMetroidCollision(collisionInterface, gunshipLaser, metroids, variables, scoreText, highScoreText);
        evaluateGunshipLaserRidleyCollision(collisionInterface, gunshipLaser, ridley, variables, scoreText, highScoreText);
        evaluateGunshipLaserBunkerCollision(collisionInterface, gunshipLaser, bunkers);
        evaluateMetroidLaserBunkerCollision(collisionInterface, metroidLasers, bunkers);
        evaluateGunshipMetroidLaserCollision(collisionInterface, gunship, metroidLasers, gunshipLaser, livesText);
        if (haveMetroidsInvaded(metroids) || gunship.getLives() == 0)
        {
          endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
          updateHighScore(variables, scoreText, highScoreText);
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
        displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
          resetObjects(gunship, gunshipLaser, metroids, metroidLasers, ridley, bunkers);
          resetValues(isPlaying, gameOver, variables);
          resetInformationObjects(scoreText, livesText, creditsTheme, battleTheme, movementClock);
        }
      }
      else
      {
        displayTitleScreen(window, titleBackground, titleText, instructionsText);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
          play(isPlaying, titleTheme, battleTheme, movementClock);
        }
      }
      frameClock.restart();
    }
  }

  return 0;
}
