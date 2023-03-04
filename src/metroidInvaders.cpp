#include "../include/metroidInvaders.hpp"
#include "../include/game.hpp"
#include "../include/gameOver.hpp"
#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/wrappers/soundWrapper.hpp"
#include "../include/wrappers/clockWrapper.hpp"
#include "../include/wrappers/textWrapper.hpp"
#include "../include/models/gunshipLaser.hpp"
#include "../include/models/gunship.hpp"
#include "../include/models/metroids.hpp"
#include "../include/models/metroidLaser.hpp"
#include "../include/models/ridley.hpp"
#include "../include/interfaces/collisionInterface.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Metroid Invaders");

  GunshipLaser gunshipLaser = makeGunshipLaser();
  Gunship gunship = makeGunship(gunshipLaser);
  std::vector<std::vector<IMetroid *>> metroids = makeMetroids();
  std::vector<ILaser *> metroidLasers = makeMetroidLasers();
  Ridley ridley = makeRidley();

  ClockWrapper clock;
  int interval = 665;
  int step = 1;

  std::vector<ISound *> metroidSounds = makeMetroidSounds();
  int soundCounter = 0;

  Collision collisionInterface;

  int level = 1;
  int score = 0;

  sf::Font m56;
  m56.loadFromFile("public/fonts/MicroN56.ttf");
  TextWrapper scoreText = makeScoreText(m56);
  TextWrapper livesText = makeLivesText(gunship, m56);
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
      drawObjects(window, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, livesText);
      monitorRidleyMovementSound(ridley);
      if (areMetroidsDead(metroids))
      {
        levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, clock);
      }
      evaluateGunshipLaserMetroidCollision(collisionInterface, gunshipLaser, metroids, score, scoreText);
      evaluateGunshipLaserRidleyCollision(collisionInterface, gunshipLaser, ridley, score, scoreText);
      evaluateGunshipMetroidLaserCollision(collisionInterface, gunship, metroidLasers, gunshipLaser, livesText);
      if (haveMetroidsInvaded(metroids) || gunship.getLives() == 0)
      {
        endGame(isPlaying, gameOver, ridley, score, scoreText);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        moveGunship(gunship, 0.25);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        moveGunship(gunship, -0.25);
      }
      moveGunshipLaser(gunshipLaser);
      moveMetroids(metroids, clock, interval, step, metroidSounds, soundCounter);
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
        playAgain(isPlaying, gameOver, gunship, gunshipLaser, metroids, metroidLasers, ridley, interval, step, soundCounter, level, score, scoreText, livesText, clock);
      }
    }
  }

  return 0;
}

GunshipLaser makeGunshipLaser()
{
  sf::Texture gunshipLaserTexture;
  gunshipLaserTexture.loadFromFile("public/images/sprites/gunshipLaser.png");
  SpriteWrapper *gunshipLaserSprite = new SpriteWrapper(gunshipLaserTexture);

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("public/audio/metroidDeath.wav");
  SoundWrapper *deathSound = new SoundWrapper(deathBuffer);

  GunshipLaser gunshipLaser(gunshipLaserSprite, deathSound);
  return gunshipLaser;
}

Gunship makeGunship(GunshipLaser &gunshipLaser)
{
  sf::Texture gunshipTexture;
  gunshipTexture.loadFromFile("public/images/sprites/gunship.png");
  SpriteWrapper *gunshipSprite = new SpriteWrapper(gunshipTexture);

  sf::SoundBuffer fireSoundBuffer;
  fireSoundBuffer.loadFromFile("public/audio/shoot.wav");
  SoundWrapper *fireSound = new SoundWrapper(fireSoundBuffer);

  sf::SoundBuffer deathSoundBuffer;
  deathSoundBuffer.loadFromFile("public/audio/gunshipDeath.wav");
  SoundWrapper *deathSound = new SoundWrapper(deathSoundBuffer);

  GunshipLaser *pGunshipLaser = &gunshipLaser;
  Gunship gunship(gunshipSprite, pGunshipLaser, fireSound, deathSound);
  return gunship;
}

std::vector<std::vector<IMetroid *>> makeMetroids()
{
  sf::Texture larvaTexture;
  larvaTexture.loadFromFile("public/images/sprites/larva.png");
  sf::Texture alphaTexture;
  alphaTexture.loadFromFile("public/images/sprites/alpha.png");
  sf::Texture gammaTexture;
  gammaTexture.loadFromFile("public/images/sprites/gamma.png");
  std::vector<std::vector<IMetroid *>> metroids(5);

  float xOffset = 282;
  float yOffset = 348;
  float extraLarvaXOffset = 12;

  for (int i = 0; i < 5; i++)
  {
    std::vector<IMetroid *> metroidRow(11);
    for (int j = 0; j < 11; j++)
    {
      if (i == 0)
      {
        SpriteWrapper *larvaSprite = new SpriteWrapper(larvaTexture);
        Larva *larva = new Larva(j * 90 + xOffset + extraLarvaXOffset, i * 90 + yOffset, larvaSprite);
        metroidRow[j] = larva;
      }
      else if (i < 3)
      {
        SpriteWrapper *alphaSprite = new SpriteWrapper(alphaTexture);
        Alpha *alpha = new Alpha(j * 90 + xOffset, i * 90 + yOffset, alphaSprite);
        metroidRow[j] = alpha;
      }
      else
      {
        SpriteWrapper *gammaSprite = new SpriteWrapper(gammaTexture);
        Gamma *gamma = new Gamma(j * 90 + xOffset, i * 90 + yOffset, gammaSprite);
        metroidRow[j] = gamma;
      }
    }
    metroids[i] = metroidRow;
  }

  return metroids;
}

std::vector<ILaser *> makeMetroidLasers()
{
  sf::Texture metroidLaserTexture;
  metroidLaserTexture.loadFromFile("public/images/sprites/metroidLaser.png");
  std::vector<ILaser *> metroidLasers(3);

  for (int i = 0; i < 3; i++)
  {
    SpriteWrapper *metroidLaserSprite = new SpriteWrapper(metroidLaserTexture);
    MetroidLaser *metroidLaser = new MetroidLaser(metroidLaserSprite);
    metroidLasers[i] = metroidLaser;
  }

  return metroidLasers;
}

Ridley makeRidley()
{
  sf::Texture ridleyTexture;
  ridleyTexture.loadFromFile("public/images/sprites/ridley.png");
  SpriteWrapper *ridleySprite = new SpriteWrapper(ridleyTexture);

  sf::SoundBuffer movementBuffer;
  movementBuffer.loadFromFile("public/audio/ridley.wav");
  SoundWrapper *movementSound = new SoundWrapper(movementBuffer);

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("public/audio/ridleyDeath.wav");
  SoundWrapper *deathSound = new SoundWrapper(deathBuffer);

  Ridley ridley(ridleySprite, movementSound, deathSound);
  return ridley;
}

std::vector<ISound *> makeMetroidSounds()
{
  sf::SoundBuffer sound0Buffer;
  sound0Buffer.loadFromFile("public/audio/metroid0.wav");
  SoundWrapper *sound0 = new SoundWrapper(sound0Buffer);

  sf::SoundBuffer sound1Buffer;
  sound1Buffer.loadFromFile("public/audio/metroid1.wav");
  SoundWrapper *sound1 = new SoundWrapper(sound1Buffer);

  sf::SoundBuffer sound2Buffer;
  sound2Buffer.loadFromFile("public/audio/metroid2.wav");
  SoundWrapper *sound2 = new SoundWrapper(sound2Buffer);

  sf::SoundBuffer sound3Buffer;
  sound3Buffer.loadFromFile("public/audio/metroid3.wav");
  SoundWrapper *sound3 = new SoundWrapper(sound3Buffer);

  std::vector<ISound *> metroidSounds = {sound0, sound1, sound2, sound3};
  return metroidSounds;
}

SpriteWrapper makeTitleBackground()
{
  sf::Texture titleBackgroundTexture;
  titleBackgroundTexture.loadFromFile("public/images/backgrounds/title.png");
  SpriteWrapper titleBackground(titleBackgroundTexture);

  return titleBackground;
}

TextWrapper makeTitleText(const sf::Font &font)
{
  std::string titleString = "Metroid Invaders";
  TextWrapper titleText(titleString, font);
  sf::FloatRect titleTextRect = titleText.getLocalBounds();
  titleText.setOrigin(titleTextRect.width / 2, 0);
  titleText.setPosition(sf::Vector2f(768, 200));

  return titleText;
}

TextWrapper makeInstructionsText(const sf::Font &font)
{
  std::string instructionsString = "Press enter to play!";
  TextWrapper instructionsText(instructionsString, font);
  sf::FloatRect instructionsTextRect = instructionsText.getLocalBounds();
  instructionsText.setOrigin(instructionsTextRect.width / 2, 0);
  instructionsText.setPosition(sf::Vector2f(768, 800));

  return instructionsText;
}

TextWrapper makeScoreText(const sf::Font &font)
{
  std::string scoreString = "Score: 0";
  TextWrapper scoreText(scoreString, font);
  scoreText.setPosition(sf::Vector2f(20, 0));
  scoreText.setCharacterSize(50);
  return scoreText;
}

TextWrapper makeLivesText(const Gunship &gunship, const sf::Font &font)
{
  std::string livesString = "Lives: " + std::to_string(gunship.getLives());
  TextWrapper livesText(livesString, font);
  livesText.setPosition(sf::Vector2f(1250, 0));
  livesText.setCharacterSize(50);
  return livesText;
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
