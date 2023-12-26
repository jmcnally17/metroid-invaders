#include <fstream>
#include "../../include/wrappers/SpriteWrapper.hpp"
#include "../../include/wrappers/TextWrapper.hpp"
#include "../../include/wrappers/SoundWrapper.hpp"
#include "../../include/models/Bunker.hpp"
#include "../../include/models/GunshipLaser.hpp"
#include "../../include/models/Gunship.hpp"
#include "../../include/models/Larva.hpp"
#include "../../include/models/Alpha.hpp"
#include "../../include/models/Gamma.hpp"
#include "../../include/models/MetroidLaser.hpp"
#include "../../include/models/Ridley.hpp"

SpriteWrapper makeBackground(std::string fileName)
{
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("resources/images/backgrounds/" + fileName + ".png");
  SpriteWrapper background(backgroundTexture);

  return background;
}

TextWrapper makeText(std::string string, const sf::Font &font, int characterSize, const sf::Color &color, float originFactor, float x, float y)
{
  TextWrapper text(string, font);
  text.setCharacterSize(characterSize);
  text.setFillColor(color);
  sf::FloatRect textRect {text.getLocalBounds()};
  text.setOrigin(textRect.width * originFactor, 0);
  text.setPosition(sf::Vector2f(x, y));

  return text;
}

SoundWrapper makeTheme(std::string fileName)
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile("resources/audio/" + fileName + ".wav");
  SoundWrapper theme(buffer);
  theme.setLoop(true);

  return theme;
}

std::array<IBunker*, 4> makeBunkers()
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
    SpriteWrapper *bunkerSprite1 {new SpriteWrapper(bunkerTexture1)};
    SpriteWrapper *bunkerSprite2 {new SpriteWrapper(bunkerTexture2)};
    SpriteWrapper *bunkerSprite3 {new SpriteWrapper(bunkerTexture3)};
    SpriteWrapper *bunkerSprite4 {new SpriteWrapper(bunkerTexture4)};
    SpriteWrapper *bunkerSprite5 {new SpriteWrapper(bunkerTexture5)};
    Bunker *bunker {new Bunker(xOffset + (xIncrement * i), 1032, bunkerSprite1, bunkerSprite2, bunkerSprite3, bunkerSprite4, bunkerSprite5)};
    bunkers[i] = bunker;
  }

  return bunkers;
}

GunshipLaser makeGunshipLaser()
{
  sf::Texture gunshipLaserTexture;
  gunshipLaserTexture.loadFromFile("resources/images/sprites/gunshipLaser.png");
  SpriteWrapper *gunshipLaserSprite {new SpriteWrapper(gunshipLaserTexture)};

  GunshipLaser gunshipLaser(gunshipLaserSprite);
  return gunshipLaser;
}

Gunship makeGunship(GunshipLaser &gunshipLaser)
{
  sf::Texture gunshipTexture;
  gunshipTexture.loadFromFile("resources/images/sprites/gunship.png");
  SpriteWrapper *gunshipSprite {new SpriteWrapper(gunshipTexture)};

  sf::SoundBuffer fireSoundBuffer;
  fireSoundBuffer.loadFromFile("resources/audio/shoot.wav");
  SoundWrapper *fireSound {new SoundWrapper(fireSoundBuffer)};

  sf::SoundBuffer deathSoundBuffer;
  deathSoundBuffer.loadFromFile("resources/audio/gunshipDeath.wav");
  SoundWrapper *deathSound {new SoundWrapper(deathSoundBuffer)};

  GunshipLaser *pGunshipLaser {&gunshipLaser};
  Gunship gunship(gunshipSprite, pGunshipLaser, fireSound, deathSound);
  return gunship;
}

std::array<std::array<IMetroid*, 11>, 5> makeMetroids()
{
  sf::Texture larvaTexture;
  larvaTexture.loadFromFile("resources/images/sprites/larva.png");
  sf::Texture alphaTexture;
  alphaTexture.loadFromFile("resources/images/sprites/alpha.png");
  sf::Texture gammaTexture;
  gammaTexture.loadFromFile("resources/images/sprites/gamma.png");
  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("resources/audio/metroidDeath.wav");
  SoundWrapper *deathSound {new SoundWrapper(deathBuffer)};

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
        SpriteWrapper *larvaSprite {new SpriteWrapper(larvaTexture)};
        Larva *larva {new Larva(j * 90 + xOffset + extraLarvaXOffset, i * 90 + yOffset, larvaSprite, deathSound)};
        metroidRow[j] = {larva};
      }
      else if (i < 3)
      {
        SpriteWrapper *alphaSprite {new SpriteWrapper(alphaTexture)};
        Alpha *alpha {new Alpha(j * 90 + xOffset, i * 90 + yOffset, alphaSprite, deathSound)};
        metroidRow[j] = {alpha};
      }
      else
      {
        SpriteWrapper *gammaSprite {new SpriteWrapper(gammaTexture)};
        Gamma *gamma {new Gamma(j * 90 + xOffset, i * 90 + yOffset, gammaSprite, deathSound)};
        metroidRow[j] = {gamma};
      }
    }
    metroids[i] = {metroidRow};
  }

  return metroids;
}

std::array<IMetroidLaser*, 3> makeMetroidLasers()
{
  sf::Texture metroidLaserTexture;
  metroidLaserTexture.loadFromFile("resources/images/sprites/metroidLaser.png");
  
  std::array<IMetroidLaser*, 3> metroidLasers;
  for (int i = 0; i < 3; i++)
  {
    SpriteWrapper *metroidLaserSprite {new SpriteWrapper(metroidLaserTexture)};
    MetroidLaser *metroidLaser {new MetroidLaser(metroidLaserSprite)};
    metroidLasers[i] = {metroidLaser};
  }

  return metroidLasers;
}

Ridley makeRidley()
{
  sf::Texture ridleyRightTexture;
  ridleyRightTexture.loadFromFile("resources/images/sprites/ridleyRight.png");
  SpriteWrapper *ridleyRightSprite {new SpriteWrapper(ridleyRightTexture)};
  
  sf::Texture ridleyLeftTexture;
  ridleyLeftTexture.loadFromFile("resources/images/sprites/ridleyLeft.png");
  SpriteWrapper *ridleyLeftSprite {new SpriteWrapper(ridleyLeftTexture)};
  
  sf::SoundBuffer movementBuffer;
  movementBuffer.loadFromFile("resources/audio/ridley.wav");
  SoundWrapper *movementSound {new SoundWrapper(movementBuffer)};

  sf::SoundBuffer deathBuffer;
  deathBuffer.loadFromFile("resources/audio/ridleyDeath.wav");
  SoundWrapper *deathSound {new SoundWrapper(deathBuffer)};

  Ridley ridley(ridleyRightSprite, deathSound, ridleyLeftSprite, movementSound);
  return ridley;
}

std::array<ISound*, 4> makeMetroidSounds()
{
  sf::SoundBuffer sound0Buffer;
  sound0Buffer.loadFromFile("resources/audio/metroid0.wav");
  SoundWrapper *sound0 {new SoundWrapper(sound0Buffer)};

  sf::SoundBuffer sound1Buffer;
  sound1Buffer.loadFromFile("resources/audio/metroid1.wav");
  SoundWrapper *sound1 {new SoundWrapper(sound1Buffer)};

  sf::SoundBuffer sound2Buffer;
  sound2Buffer.loadFromFile("resources/audio/metroid2.wav");
  SoundWrapper *sound2 {new SoundWrapper(sound2Buffer)};

  sf::SoundBuffer sound3Buffer;
  sound3Buffer.loadFromFile("resources/audio/metroid3.wav");
  SoundWrapper *sound3 {new SoundWrapper(sound3Buffer)};

  std::array<ISound*, 4> metroidSounds {sound0, sound1, sound2, sound3};
  return metroidSounds;
}

std::array<sf::RectangleShape, 2> makeRectangles()
{
  sf::RectangleShape rectangle1(sf::Vector2f(96, 42));
  rectangle1.setPosition(sf::Vector2f(-96, 200));
  rectangle1.setFillColor(sf::Color::Black);
  sf::RectangleShape rectangle2(sf::Vector2f(96, 42));
  rectangle2.setPosition(sf::Vector2f(1536, 200));
  rectangle2.setFillColor(sf::Color::Black);

  return {rectangle1, rectangle2};
}

void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText)
{
  std::string highScoreString;
  std::ifstream highScoreFile("highScore.txt");
  getline(highScoreFile, highScoreString);
  highScoreFile.close();
  if (!(highScoreString == ""))
  {
    variables["highScore"] = std::stoi(highScoreString);
    highScoreText.setString("HighScore: " + highScoreString);
  }
}
