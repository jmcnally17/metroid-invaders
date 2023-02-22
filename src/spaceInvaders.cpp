#include "../include/spaceInvaders.hpp"
#include "../include/game.hpp"
#include "../include/gameOver.hpp"
#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/wrappers/soundWrapper.hpp"
#include "../include/wrappers/clockWrapper.hpp"
#include "../include/wrappers/textWrapper.hpp"
#include "../include/models/cannonLaser.hpp"
#include "../include/models/laserCannon.hpp"
#include "../include/models/invaders.hpp"
#include "../include/models/invaderLaser.hpp"
#include "../include/interfaces/collisionInterface.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Space Invaders");

  CannonLaser cannonLaser = makeLaser();
  LaserCannon cannon = makeCannon(cannonLaser);
  std::vector<std::vector<IInvader *>> invaders = makeInvaders();
  std::vector<ILaser *> invaderLasers = makeInvaderLasers();

  ClockWrapper clock;
  int interval = 665;
  int step = 1;

  std::vector<ISound *> invaderSounds = makeInvaderSounds();
  int soundCounter = 0;

  Collision collisionInterface;

  int level = 1;
  int score = 0;

  sf::Font m56;
  m56.loadFromFile("public/fonts/MicroN56.ttf");
  TextWrapper scoreText = makeScoreText(m56);
  TextWrapper gameOverText = makeGameOverText(m56);
  TextWrapper playAgainText = makePlayAgainText(m56);

  bool isPlaying = true;
  bool gameOver = false;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window.close();
      }
    }

    if (isPlaying)
    {
      drawObjects(window, cannon, cannonLaser, invaders, invaderLasers, scoreText);
      if (areInvadersDead(invaders))
      {
        levelUp(level, interval, step, soundCounter, invaders, clock);
      }
      evaluateLaserInvaderCollision(collisionInterface, cannonLaser, invaders, score, scoreText);
      if (haveInvadersInvaded(invaders))
      {
        endGame(isPlaying, gameOver, score, scoreText);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        moveLaserCannon(cannon, 0.25);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        moveLaserCannon(cannon, -0.25);
      }
      moveLaser(cannonLaser);
      moveInvaders(invaders, clock, interval, step, invaderSounds, soundCounter);
      moveInvaderLasers(invaderLasers);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
      {
        fireLaser(cannon);
      }
      shootInvaderLaser(invaders, invaderLasers);
    }
    else if (gameOver)
    {
      displayGameOverScreen(window, gameOverText, scoreText, playAgainText);
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
      {
        playAgain(isPlaying, gameOver, cannon, cannonLaser, invaders, interval, step, soundCounter, level, score, scoreText, clock);
      }
    }
  }

  return 0;
}

CannonLaser makeLaser()
{
  sf::Texture laserTexture;
  laserTexture.loadFromFile("public/images/newSprites/cannonLaser.png");
  SpriteWrapper *laserSprite = new SpriteWrapper(laserTexture);

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("public/audio/invaderDeath.wav");
  SoundWrapper *deathSound = new SoundWrapper(deathBuffer);

  CannonLaser cannonLaser(laserSprite, deathSound);
  return cannonLaser;
}

LaserCannon makeCannon(CannonLaser &cannonLaser)
{
  sf::Texture cannonTexture;
  cannonTexture.loadFromFile("public/images/newSprites/laserCannon.png");
  SpriteWrapper *cannonSprite = new SpriteWrapper(cannonTexture);

  sf::SoundBuffer fireSoundBuffer;
  fireSoundBuffer.loadFromFile("public/audio/shoot.wav");
  SoundWrapper *fireSound = new SoundWrapper(fireSoundBuffer);

  CannonLaser *pLaser = &cannonLaser;
  LaserCannon cannon(cannonSprite, pLaser, fireSound);
  return cannon;
}

std::vector<std::vector<IInvader *>> makeInvaders()
{
  sf::Texture squidTexture;
  squidTexture.loadFromFile("public/images/newSprites/squid.png");
  sf::Texture crabTexture;
  crabTexture.loadFromFile("public/images/newSprites/crab.png");
  sf::Texture octopusTexture;
  octopusTexture.loadFromFile("public/images/newSprites/octopus.png");
  std::vector<std::vector<IInvader *>> invaders(5);

  float xOffset = 282;
  float yOffset = 348;
  float extraSquidXOffset = 12;

  for (int i = 0; i < 5; i++)
  {
    std::vector<IInvader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      if (i == 0)
      {
        SpriteWrapper *squidSprite = new SpriteWrapper(squidTexture);
        Squid *squid = new Squid(j * 90 + xOffset + extraSquidXOffset, i * 90 + yOffset, squidSprite);
        invaderRow[j] = squid;
      }
      else if (i < 3)
      {
        SpriteWrapper *crabSprite = new SpriteWrapper(crabTexture);
        Crab *crab = new Crab(j * 90 + xOffset, i * 90 + yOffset, crabSprite);
        invaderRow[j] = crab;
      }
      else
      {
        SpriteWrapper *octopusSprite = new SpriteWrapper(octopusTexture);
        Octopus *octopus = new Octopus(j * 90 + xOffset, i * 90 + yOffset, octopusSprite);
        invaderRow[j] = octopus;
      }
    }
    invaders[i] = invaderRow;
  }

  return invaders;
}

std::vector<ILaser *> makeInvaderLasers()
{
  sf::Texture laserTexture;
  laserTexture.loadFromFile("public/images/newSprites/invaderLaser.png");
  std::vector<ILaser *> invaderLasers(3);

  for (int i = 0; i < 3; i++)
  {
    SpriteWrapper *laserSprite = new SpriteWrapper(laserTexture);
    InvaderLaser *laser = new InvaderLaser(laserSprite);
    invaderLasers[i] = laser;
  }

  return invaderLasers;
}

std::vector<ISound *> makeInvaderSounds()
{
  sf::SoundBuffer sound0Buffer;
  sound0Buffer.loadFromFile("public/audio/invader0.wav");
  SoundWrapper *sound0 = new SoundWrapper(sound0Buffer);

  sf::SoundBuffer sound1Buffer;
  sound1Buffer.loadFromFile("public/audio/invader1.wav");
  SoundWrapper *sound1 = new SoundWrapper(sound1Buffer);

  sf::SoundBuffer sound2Buffer;
  sound2Buffer.loadFromFile("public/audio/invader2.wav");
  SoundWrapper *sound2 = new SoundWrapper(sound2Buffer);

  sf::SoundBuffer sound3Buffer;
  sound3Buffer.loadFromFile("public/audio/invader3.wav");
  SoundWrapper *sound3 = new SoundWrapper(sound3Buffer);

  std::vector<ISound *> invaderSounds = {sound0, sound1, sound2, sound3};
  return invaderSounds;
}

TextWrapper makeScoreText(const sf::Font &font)
{
  std::string scoreString = "Score: 0";
  TextWrapper scoreText(scoreString, font);
  scoreText.setPosition(sf::Vector2f(20, 0));
  scoreText.setCharacterSize(50);
  return scoreText;
}

TextWrapper makeGameOverText(const sf::Font &font)
{
  std::string gameOverString = "Game Over";
  TextWrapper gameOverText(gameOverString, font);
  gameOverText.setPosition(sf::Vector2f(192, 200));
  gameOverText.setCharacterSize(153);
  return gameOverText;
}

TextWrapper makePlayAgainText(const sf::Font &font)
{
  std::string playAgainString = "Press p to play again";
  TextWrapper playAgainText(playAgainString, font);
  playAgainText.setPosition(sf::Vector2f(384, 1000));
  playAgainText.setCharacterSize(48);
  return playAgainText;
}
