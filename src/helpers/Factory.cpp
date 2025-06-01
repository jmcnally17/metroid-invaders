#include "../../include/Constants.hpp"
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
  m56.openFromFile("resources/fonts/MicroN56.ttf");
  sf::Color white {sf::Color::White};
  sf::Color green {sf::Color::Green};
  std::string titleString {"Metroid Invaders"};
  std::string instructionsString {"Press enter to play!"};
  std::string scoreString {"Score: 0"};
  std::string highScoreString {"High Score: 0"};
  std::string livesString {"Lives: 3"};
  std::string gameOverString {"Game Over"};
  std::string playAgainString {"Press p to play again"};
  TextAdaptor *titleText {makeText(titleString, m56, 6.25 * Constants::LENGTH_SCALE, green, 0.5, 48 * Constants::LENGTH_SCALE, 16 * Constants::LENGTH_SCALE)};
  TextAdaptor *instructionsText {makeText(instructionsString, m56, 3.125 * Constants::LENGTH_SCALE, green, 0.5, 48 * Constants::LENGTH_SCALE, 75 * Constants::LENGTH_SCALE)};
  TextAdaptor *scoreText {makeText(scoreString, m56, 3.125 * Constants::LENGTH_SCALE, white, 0, 1.25 * Constants::LENGTH_SCALE, 0)};
  TextAdaptor *highScoreText {makeText(highScoreString, m56, 3.125 * Constants::LENGTH_SCALE, white, 0.5, 48 * Constants::LENGTH_SCALE, 0)};
  TextAdaptor *livesText {makeText(livesString, m56, 3.125 * Constants::LENGTH_SCALE, white, 0, 78.125 * Constants::LENGTH_SCALE, 0)};
  TextAdaptor *gameOverText {makeText(gameOverString, m56, 9.5625 * Constants::LENGTH_SCALE, white, 0.5, 48 * Constants::LENGTH_SCALE, 12.5 * Constants::LENGTH_SCALE)};
  TextAdaptor *playAgainText {makeText(playAgainString, m56, 3 * Constants::LENGTH_SCALE, white, 0.5, 48 * Constants::LENGTH_SCALE, 62.5 * Constants::LENGTH_SCALE)};
  
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

GameObjectList Factory::makeGameObjects()
{
  GameObjectList gameObjects;
  
  gameObjects.bunkers = makeBunkers();
  GunshipLaser *gunshipLaser {makeGunshipLaser()};
  gameObjects.gunshipLaser = gunshipLaser;
  gameObjects.gunship = makeGunship(gunshipLaser);
  gameObjects.metroids = makeMetroids();
  gameObjects.metroidLasers = makeMetroidLasers();
  gameObjects.ridley = makeRidley();
  
  return gameObjects;
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
  
  float xOffset {12 * Constants::LENGTH_SCALE};
  float xIncrement {21 * Constants::LENGTH_SCALE};
  
  for (int i = 0; i < 4; i++)
  {
    SpriteAdaptor *bunkerSprite1 {new SpriteAdaptor(bunkerTexture1)};
    SpriteAdaptor *bunkerSprite2 {new SpriteAdaptor(bunkerTexture2)};
    SpriteAdaptor *bunkerSprite3 {new SpriteAdaptor(bunkerTexture3)};
    SpriteAdaptor *bunkerSprite4 {new SpriteAdaptor(bunkerTexture4)};
    SpriteAdaptor *bunkerSprite5 {new SpriteAdaptor(bunkerTexture5)};
    Bunker *bunker {new Bunker(xOffset + (xIncrement * i), 64.5 * Constants::LENGTH_SCALE, bunkerSprite1, bunkerSprite2, bunkerSprite3, bunkerSprite4, bunkerSprite5)};
    bunkers[i] = bunker;
  }

  return bunkers;
}

GunshipLaser *Factory::makeGunshipLaser()
{
  sf::Texture gunshipLaserTexture;
  gunshipLaserTexture.loadFromFile("resources/images/sprites/gunshipLaser.png");
  SpriteAdaptor *gunshipLaserSprite {new SpriteAdaptor(gunshipLaserTexture)};

  GunshipLaser *gunshipLaser {new GunshipLaser(gunshipLaserSprite)};
  return gunshipLaser;
}

Gunship *Factory::makeGunship(GunshipLaser *gunshipLaser)
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

  Gunship *gunship {new Gunship(gunshipSprite, gunshipLaser, fireSound, deathSound)};
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

  float xOffset {static_cast<float>(17.625 * Constants::LENGTH_SCALE)};
  float yOffset {static_cast<float>(21.75 * Constants::LENGTH_SCALE)};
  float extraLarvaXOffset {static_cast<float>(0.75 * Constants::LENGTH_SCALE)};
  float distanceBetweenMetroids {static_cast<float>(5.625 * Constants::LENGTH_SCALE)};

  for (int i = 0; i < 5; i++)
  {
    std::array<IMetroid*, 11> metroidRow;
    for (int j = 0; j < 11; j++)
    {
      if (i == 0)
      {
        SpriteAdaptor *larvaSprite {new SpriteAdaptor(larvaTexture)};
        Larva *larva {new Larva(j * distanceBetweenMetroids + xOffset + extraLarvaXOffset, i * distanceBetweenMetroids + yOffset, larvaSprite, deathSound)};
        metroidRow[j] = {larva};
      }
      else if (i < 3)
      {
        SpriteAdaptor *alphaSprite {new SpriteAdaptor(alphaTexture)};
        Alpha *alpha {new Alpha(j * distanceBetweenMetroids + xOffset, i * distanceBetweenMetroids + yOffset, alphaSprite, deathSound)};
        metroidRow[j] = {alpha};
      }
      else
      {
        SpriteAdaptor *gammaSprite {new SpriteAdaptor(gammaTexture)};
        Gamma *gamma {new Gamma(j * distanceBetweenMetroids + xOffset, i * distanceBetweenMetroids + yOffset, gammaSprite, deathSound)};
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

Ridley *Factory::makeRidley()
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

  Ridley *ridley {new Ridley(ridleyRightSprite, deathSound, ridleyLeftSprite, movementSound)};
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
  sf::RectangleShape rectangle1(sf::Vector2f(6 * Constants::LENGTH_SCALE, 2.625 * Constants::LENGTH_SCALE));
  rectangle1.setPosition(sf::Vector2f(-6 * Constants::LENGTH_SCALE, 12.5 * Constants::LENGTH_SCALE));
  rectangle1.setFillColor(sf::Color::Black);
  sf::RectangleShape rectangle2(sf::Vector2f(6 * Constants::LENGTH_SCALE, 2.625 * Constants::LENGTH_SCALE));
  rectangle2.setPosition(sf::Vector2f(96 * Constants::LENGTH_SCALE, 12.5 * Constants::LENGTH_SCALE));
  rectangle2.setFillColor(sf::Color::Black);

  return {rectangle1, rectangle2};
}

SpriteAdaptor *Factory::makeBackground(std::string fileName)
{
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("resources/images/backgrounds/" + fileName + ".png");
  SpriteAdaptor *background {new SpriteAdaptor(backgroundTexture)};
  background->setScale(sf::Vector2f(Constants::LENGTH_SCALE / 16, Constants::LENGTH_SCALE / 16));

  return background;
}

TextAdaptor *Factory::makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y)
{
  TextAdaptor *text {new TextAdaptor(string, font)};
  text->setCharacterSize(characterSize);
  text->setFillColor(color);
  sf::FloatRect textRect {text->getLocalBounds()};
  text->setOrigin(textRect.size.x * originFactor, 0);
  text->setPosition(sf::Vector2f(x, y));

  return text;
}

SoundAdaptor *Factory::makeTheme(std::string fileName)
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile("resources/audio/" + fileName + ".wav");
  SoundAdaptor *theme {new SoundAdaptor(buffer)};
  theme->setLooping(true);

  return theme;
}
