#include <fstream>
#include "../include/metroidInvaders.hpp"
#include "../include/title.hpp"
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
#include "../include/models/bunker.hpp"
#include "../include/interfaces/collisionInterface.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Metroid Invaders");

  sf::Font m56;
  m56.loadFromFile("public/fonts/MicroN56.ttf");
  sf::Color white = sf::Color::White;
  sf::Color green = sf::Color::Green;

  // backgrounds
  SpriteWrapper titleBackground = makeBackground("title");
  SpriteWrapper gameBackground = makeBackground("game");
  gameBackground.setScale(4, 4);

  // text objects
  std::string titleString = "Metroid Invaders";
  std::string instructionsString = "Press enter to play!";
  std::string scoreString = "Score: 0";
  std::string highScoreString = "High Score: 0";
  std::string livesString = "Lives: 3";
  std::string gameOverString = "Game Over";
  std::string playAgainString = "Press p to play again";
  TextWrapper titleText = makeText(titleString, m56, 100, green, 0.5, 768, 100);
  TextWrapper instructionsText = makeText(instructionsString, m56, 50, green, 0.5, 768, 1200);
  TextWrapper scoreText = makeText(scoreString, m56, 50, white, 0, 20, 0);
  TextWrapper highScoreText = makeText(highScoreString, m56, 50, white, 0.5, 768, 0);
  TextWrapper livesText = makeText(livesString, m56, 50, white, 0, 1250, 0);
  TextWrapper gameOverText = makeText(gameOverString, m56, 153, white, 0.5, 768, 200);
  TextWrapper playAgainText = makeText(playAgainString, m56, 48, white, 0.5, 768, 1000);

  // audio objects
  SoundWrapper titleTheme = makeTheme("title");
  SoundWrapper battleTheme = makeTheme("battle");
  SoundWrapper creditsTheme = makeTheme("credits");

  // game objects
  std::vector<IBunker *> bunkers = makeBunkers();
  GunshipLaser gunshipLaser = makeGunshipLaser();
  Gunship gunship = makeGunship(gunshipLaser);
  std::vector<std::vector<IMetroid *>> metroids = makeMetroids();
  std::vector<ILaser *> metroidLasers = makeMetroidLasers();
  Ridley ridley = makeRidley();
  std::vector<ISound *> metroidSounds = makeMetroidSounds();
  int soundCounter = 0;
  ClockWrapper movementClock;
  int interval = 665;
  int step = 1;
  Collision collisionInterface;
  int level = 1;
  int score = 0;
  int highScore = 0;

  // final setup
  bool isPlaying = false;
  bool gameOver = false;
  pullHighScore(highScore, highScoreText);
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
    }

    if (isPlaying)
    {
      drawObjects(window, gameBackground, bunkers, gunship, gunshipLaser, metroids, metroidLasers, ridley, scoreText, highScoreText, livesText);
      monitorRidleyMovementSound(ridley);
      if (areMetroidsDead(metroids))
      {
        levelUp(level, interval, step, soundCounter, metroids, metroidLasers, ridley, movementClock);
      }
      evaluateGunshipLaserMetroidCollision(collisionInterface, gunshipLaser, metroids, score, scoreText, highScore, highScoreText);
      evaluateGunshipLaserRidleyCollision(collisionInterface, gunshipLaser, ridley, score, scoreText, highScore, highScoreText);
      evaluateGunshipLaserBunkerCollision(collisionInterface, gunshipLaser, bunkers);
      evaluateMetroidLaserBunkerCollision(collisionInterface, metroidLasers, bunkers);
      evaluateGunshipMetroidLaserCollision(collisionInterface, gunship, metroidLasers, gunshipLaser, livesText);
      if (haveMetroidsInvaded(metroids) || gunship.getLives() == 0)
      {
        endGame(isPlaying, gameOver, ridley, battleTheme, creditsTheme);
        updateHighScore(score, highScore, scoreText, highScoreText);
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
      moveMetroids(metroids, movementClock, interval, step, metroidSounds, soundCounter);
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
        resetValues(isPlaying, gameOver, interval, step, soundCounter, level, score);
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
  }

  return 0;
}

SpriteWrapper makeBackground(std::string fileName)
{
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("public/images/backgrounds/" + fileName + ".png");
  SpriteWrapper background(backgroundTexture);

  return background;
}

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y)
{
  TextWrapper text(string, font);
  text.setCharacterSize(characterSize);
  text.setFillColor(color);
  sf::FloatRect textRect = text.getLocalBounds();
  text.setOrigin(textRect.width * originFactor, 0);
  text.setPosition(sf::Vector2f(x, y));

  return text;
}

SoundWrapper makeTheme(std::string fileName)
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile("public/audio/" + fileName + ".wav");
  SoundWrapper theme(buffer);
  theme.setLoop(true);

  return theme;
}

std::vector<IBunker *> makeBunkers()
{
  sf::Texture bunkerTexture1;
  bunkerTexture1.loadFromFile("public/images/sprites/bunker1.png");
  sf::Texture bunkerTexture2;
  bunkerTexture2.loadFromFile("public/images/sprites/bunker2.png");
  sf::Texture bunkerTexture3;
  bunkerTexture3.loadFromFile("public/images/sprites/bunker3.png");
  sf::Texture bunkerTexture4;
  bunkerTexture4.loadFromFile("public/images/sprites/bunker4.png");
  sf::Texture bunkerTexture5;
  bunkerTexture5.loadFromFile("public/images/sprites/bunker5.png");

  std::vector<IBunker *> bunkers(4);

  float xOffset = 192;
  float xIncrement = 336;

  for (int i = 0; i < 4; i++)
  {
    SpriteWrapper *bunkerSprite1 = new SpriteWrapper(bunkerTexture1);
    SpriteWrapper *bunkerSprite2 = new SpriteWrapper(bunkerTexture2);
    SpriteWrapper *bunkerSprite3 = new SpriteWrapper(bunkerTexture3);
    SpriteWrapper *bunkerSprite4 = new SpriteWrapper(bunkerTexture4);
    SpriteWrapper *bunkerSprite5 = new SpriteWrapper(bunkerTexture5);
    Bunker *bunker = new Bunker(xOffset + (xIncrement * i), 1032, bunkerSprite1, bunkerSprite2, bunkerSprite3, bunkerSprite4, bunkerSprite5);
    bunkers[i] = bunker;
  }

  return bunkers;
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
  sf::Texture ridleyRightTexture;
  ridleyRightTexture.loadFromFile("public/images/sprites/ridleyRight.png");
  SpriteWrapper *ridleyRightSprite = new SpriteWrapper(ridleyRightTexture);

  sf::Texture ridleyLeftTexture;
  ridleyLeftTexture.loadFromFile("public/images/sprites/ridleyLeft.png");
  SpriteWrapper *ridleyLeftSprite = new SpriteWrapper(ridleyLeftTexture);

  sf::SoundBuffer movementBuffer;
  movementBuffer.loadFromFile("public/audio/ridley.wav");
  SoundWrapper *movementSound = new SoundWrapper(movementBuffer);

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("public/audio/ridleyDeath.wav");
  SoundWrapper *deathSound = new SoundWrapper(deathBuffer);

  Ridley ridley(ridleyRightSprite, ridleyLeftSprite, movementSound, deathSound);
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

void pullHighScore(int &highScore, IText &highScoreText)
{
  std::string highScoreString;
  std::ifstream highScoreFile("highScore.txt");
  getline(highScoreFile, highScoreString);
  highScoreFile.close();
  if (!(highScoreString == ""))
  {
    highScore = std::stoi(highScoreString);
    highScoreText.setString("HighScore: " + highScoreString);
  }
}
