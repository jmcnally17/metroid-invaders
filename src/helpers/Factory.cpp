#include "../../include/helpers/Factory.hpp"
#include "../../include/models/Bunker.hpp"
#include "../../include/models/Larva.hpp"
#include "../../include/models/Alpha.hpp"
#include "../../include/models/Gamma.hpp"
#include "../../include/models/MetroidLaser.hpp"

std::unordered_map<std::string, ISprite*> Factory::makeBackgrounds()
{
  SpriteAdaptor *titleBackground {Factory::makeBackground("title")};
  SpriteAdaptor *gameBackground {Factory::makeBackground("game")};
  
  return std::unordered_map<std::string, ISprite*> {
    {"title", titleBackground},
    {"game", gameBackground},
  };
}

std::unordered_map<std::string, IText*> Factory::makeTextObjects()
{
  sf::Font m56;
  m56.loadFromFile("resources/fonts/MicroN56.ttf");
  sf::Color white {sf::Color::White};
  sf::Color green {sf::Color::Green};
  std::string titleString {"Metroid Invaders"};
  std::string instructionsString {"Press enter to play!"};
  std::string scoreString {"Score: 0"};
  std::string highScoreString {"High Score: 0"};
  std::string livesString {"Lives: 3"};
  std::string gameOverString {"Game Over"};
  std::string playAgainString {"Press p to play again"};
  TextAdaptor *titleText {makeText(titleString, m56, 100, green, 0.5, 768, 100)};
  TextAdaptor *instructionsText {makeText(instructionsString, m56, 50, green, 0.5, 768, 1200)};
  TextAdaptor *scoreText {makeText(scoreString, m56, 50, white, 0, 20, 0)};
  TextAdaptor *highScoreText {makeText(highScoreString, m56, 50, white, 0.5, 768, 0)};
  TextAdaptor *livesText {makeText(livesString, m56, 50, white, 0, 1250, 0)};
  TextAdaptor *gameOverText {makeText(gameOverString, m56, 153, white, 0.5, 768, 200)};
  TextAdaptor *playAgainText {makeText(playAgainString, m56, 48, white, 0.5, 768, 1000)};
  
  return std::unordered_map<std::string, IText*> {
    {"title", titleText},
    {"instructions", instructionsText},
    {"score", scoreText},
    {"highScore", highScoreText},
    {"lives", livesText},
    {"gameOver", gameOverText},
    {"playAgain", playAgainText},
  };
}

std::unordered_map<std::string, ISound*> Factory::makeThemes()
{
  SoundAdaptor *titleTheme {Factory::makeTheme("title")};
  SoundAdaptor *battleTheme {Factory::makeTheme("battle")};
  SoundAdaptor *creditsTheme {Factory::makeTheme("credits")};
  
  return std::unordered_map<std::string, ISound*> {
    {"title", titleTheme},
    {"battle", battleTheme},
    {"credits", creditsTheme},
  };
}

std::array<IBunker*, 4> Factory::makeBunkers()
{
  sf::Texture bunkerTexture1;
  bunkerTexture1.loadFromFile("resources/images/sprites/bunker1.png");
  sf::Texture bunkerTexture2;
  bunkerTexture2.loadFromFile("resources/images/sprites/bunker2.png");
  sf::Texture bunkerTexture3;
  bunkerTexture3.loadFromFile("resources/images/sprites/bunker3.png");
  sf::Texture bunkerTexture4;
  bunkerTexture4.loadFromFile("resources/images/sprites/bunker4.png");
  sf::Texture bunkerTexture5;
  bunkerTexture5.loadFromFile("resources/images/sprites/bunker5.png");
  
  std::array<IBunker*, 4> bunkers;
  
  float xOffset {192};
  float xIncrement {336};
  
  for (int i = 0; i < 4; i++)
  {
    SpriteAdaptor *bunkerSprite1 {new SpriteAdaptor(bunkerTexture1)};
    SpriteAdaptor *bunkerSprite2 {new SpriteAdaptor(bunkerTexture2)};
    SpriteAdaptor *bunkerSprite3 {new SpriteAdaptor(bunkerTexture3)};
    SpriteAdaptor *bunkerSprite4 {new SpriteAdaptor(bunkerTexture4)};
    SpriteAdaptor *bunkerSprite5 {new SpriteAdaptor(bunkerTexture5)};
    Bunker *bunker {new Bunker(xOffset + (xIncrement * i), 1032, bunkerSprite1, bunkerSprite2, bunkerSprite3, bunkerSprite4, bunkerSprite5)};
    bunkers[i] = bunker;
  }

  return bunkers;
}

GunshipLaser Factory::makeGunshipLaser()
{
  sf::Texture gunshipLaserTexture;
  gunshipLaserTexture.loadFromFile("resources/images/sprites/gunshipLaser.png");
  SpriteAdaptor *gunshipLaserSprite {new SpriteAdaptor(gunshipLaserTexture)};

  GunshipLaser gunshipLaser(gunshipLaserSprite);
  return gunshipLaser;
}

Gunship Factory::makeGunship(GunshipLaser &gunshipLaser)
{
  sf::Texture gunshipTexture;
  gunshipTexture.loadFromFile("resources/images/sprites/gunship.png");
  SpriteAdaptor *gunshipSprite {new SpriteAdaptor(gunshipTexture)};

  sf::SoundBuffer fireSoundBuffer;
  fireSoundBuffer.loadFromFile("resources/audio/shoot.wav");
  SoundAdaptor *fireSound {new SoundAdaptor(fireSoundBuffer)};

  sf::SoundBuffer deathSoundBuffer;
  deathSoundBuffer.loadFromFile("resources/audio/gunshipDeath.wav");
  SoundAdaptor *deathSound {new SoundAdaptor(deathSoundBuffer)};

  GunshipLaser *pGunshipLaser {&gunshipLaser};
  Gunship gunship(gunshipSprite, pGunshipLaser, fireSound, deathSound);
  return gunship;
}

std::array<std::array<IMetroid*, 11>, 5> Factory::makeMetroids()
{
  sf::Texture larvaTexture;
  larvaTexture.loadFromFile("resources/images/sprites/larva.png");
  sf::Texture alphaTexture;
  alphaTexture.loadFromFile("resources/images/sprites/alpha.png");
  sf::Texture gammaTexture;
  gammaTexture.loadFromFile("resources/images/sprites/gamma.png");
  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("resources/audio/metroidDeath.wav");
  SoundAdaptor *deathSound {new SoundAdaptor(deathBuffer)};

  std::array<std::array<IMetroid*, 11>, 5> metroids;

  float xOffset {282};
  float yOffset {348};
  float extraLarvaXOffset {12};

  for (int i = 0; i < 5; i++)
  {
    std::array<IMetroid*, 11> metroidRow;
    for (int j = 0; j < 11; j++)
    {
      if (i == 0)
      {
        SpriteAdaptor *larvaSprite {new SpriteAdaptor(larvaTexture)};
        Larva *larva {new Larva(j * 90 + xOffset + extraLarvaXOffset, i * 90 + yOffset, larvaSprite, deathSound)};
        metroidRow[j] = {larva};
      }
      else if (i < 3)
      {
        SpriteAdaptor *alphaSprite {new SpriteAdaptor(alphaTexture)};
        Alpha *alpha {new Alpha(j * 90 + xOffset, i * 90 + yOffset, alphaSprite, deathSound)};
        metroidRow[j] = {alpha};
      }
      else
      {
        SpriteAdaptor *gammaSprite {new SpriteAdaptor(gammaTexture)};
        Gamma *gamma {new Gamma(j * 90 + xOffset, i * 90 + yOffset, gammaSprite, deathSound)};
        metroidRow[j] = {gamma};
      }
    }
    metroids[i] = {metroidRow};
  }

  return metroids;
}

std::array<IMetroidLaser*, 3> Factory::makeMetroidLasers()
{
  sf::Texture metroidLaserTexture;
  metroidLaserTexture.loadFromFile("resources/images/sprites/metroidLaser.png");
  
  std::array<IMetroidLaser*, 3> metroidLasers;
  for (int i = 0; i < 3; i++)
  {
    SpriteAdaptor *metroidLaserSprite {new SpriteAdaptor(metroidLaserTexture)};
    MetroidLaser *metroidLaser {new MetroidLaser(metroidLaserSprite)};
    metroidLasers[i] = {metroidLaser};
  }

  return metroidLasers;
}

Ridley Factory::makeRidley()
{
  sf::Texture ridleyRightTexture;
  ridleyRightTexture.loadFromFile("resources/images/sprites/ridleyRight.png");
  SpriteAdaptor *ridleyRightSprite {new SpriteAdaptor(ridleyRightTexture)};
  
  sf::Texture ridleyLeftTexture;
  ridleyLeftTexture.loadFromFile("resources/images/sprites/ridleyLeft.png");
  SpriteAdaptor *ridleyLeftSprite {new SpriteAdaptor(ridleyLeftTexture)};
  
  sf::SoundBuffer movementBuffer;
  movementBuffer.loadFromFile("resources/audio/ridley.wav");
  SoundAdaptor *movementSound {new SoundAdaptor(movementBuffer)};

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("resources/audio/ridleyDeath.wav");
  SoundAdaptor *deathSound {new SoundAdaptor(deathBuffer)};

  Ridley ridley(ridleyRightSprite, deathSound, ridleyLeftSprite, movementSound);
  return ridley;
}

std::array<ISound*, 4> Factory::makeMetroidSounds()
{
  sf::SoundBuffer sound0Buffer;
  sound0Buffer.loadFromFile("resources/audio/metroid0.wav");
  SoundAdaptor *sound0 {new SoundAdaptor(sound0Buffer)};

  sf::SoundBuffer sound1Buffer;
  sound1Buffer.loadFromFile("resources/audio/metroid1.wav");
  SoundAdaptor *sound1 {new SoundAdaptor(sound1Buffer)};

  sf::SoundBuffer sound2Buffer;
  sound2Buffer.loadFromFile("resources/audio/metroid2.wav");
  SoundAdaptor *sound2 {new SoundAdaptor(sound2Buffer)};

  sf::SoundBuffer sound3Buffer;
  sound3Buffer.loadFromFile("resources/audio/metroid3.wav");
  SoundAdaptor *sound3 {new SoundAdaptor(sound3Buffer)};

  std::array<ISound*, 4> metroidSounds {sound0, sound1, sound2, sound3};
  return metroidSounds;
}

std::array<sf::RectangleShape, 2> Factory::makeRectangles()
{
  sf::RectangleShape rectangle1(sf::Vector2f(96, 42));
  rectangle1.setPosition(sf::Vector2f(-96, 200));
  rectangle1.setFillColor(sf::Color::Black);
  sf::RectangleShape rectangle2(sf::Vector2f(96, 42));
  rectangle2.setPosition(sf::Vector2f(1536, 200));
  rectangle2.setFillColor(sf::Color::Black);

  return {rectangle1, rectangle2};
}

SpriteAdaptor *Factory::makeBackground(std::string fileName)
{
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("resources/images/backgrounds/" + fileName + ".png");
  SpriteAdaptor *background {new SpriteAdaptor(backgroundTexture)};

  return background;
}

TextAdaptor *Factory::makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y)
{
  TextAdaptor *text {new TextAdaptor(string, font)};
  text->setCharacterSize(characterSize);
  text->setFillColor(color);
  sf::FloatRect textRect {text->getLocalBounds()};
  text->setOrigin(textRect.width * originFactor, 0);
  text->setPosition(sf::Vector2f(x, y));

  return text;
}

SoundAdaptor *Factory::makeTheme(std::string fileName)
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile("resources/audio/" + fileName + ".wav");
  SoundAdaptor *theme {new SoundAdaptor(buffer)};
  theme->setLoop(true);

  return theme;
}
