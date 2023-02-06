#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/models/laser.hpp"
#include "../include/wrappers/soundWrapper.hpp"
#include "../include/models/laserCannon.hpp"
#include "../include/models/squid.hpp"
#include "../include/models/crab.hpp"
#include "../include/models/octopus.hpp"
#include "../include/spaceInvaders.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Space Invaders");

  Laser laser = makeLaser();
  LaserCannon cannon = makeCannon(laser);
  std::vector<std::vector<Invader *>> invaders = makeInvaders();

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

    drawObjects(window, cannon, laser);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      moveLaserCannon(cannon, 0.25);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      moveLaserCannon(cannon, -0.25);
    }
    moveLaser(laser);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      fireLaser(cannon);
    }
  }

  return 0;
}

Laser makeLaser()
{
  sf::Texture laserTexture;
  laserTexture.loadFromFile("public/images/newSprites/laser.png");
  SpriteWrapper *laserSpriteWrapper = new SpriteWrapper(laserTexture);
  SpriteWrapper &rSpriteWrapper = *laserSpriteWrapper;

  Laser laser(rSpriteWrapper);
  return laser;
}

LaserCannon makeCannon(Laser &laser)
{
  sf::Texture cannonTexture;
  cannonTexture.loadFromFile("public/images/newSprites/laserCannon.png");
  SpriteWrapper *cannonSpriteWrapper = new SpriteWrapper(cannonTexture);
  SpriteWrapper &rSpriteWrapper = *cannonSpriteWrapper;

  sf::SoundBuffer fireSoundBuffer;
  fireSoundBuffer.loadFromFile("public/audio/shoot.wav");
  SoundWrapper *fireSoundWrapper = new SoundWrapper(fireSoundBuffer);
  SoundWrapper &rSoundWrapper = *fireSoundWrapper;

  LaserCannon cannon(rSpriteWrapper, laser, rSoundWrapper);
  return cannon;
}

std::vector<std::vector<Invader *>> makeInvaders()
{
  sf::Texture squidTexture;
  squidTexture.loadFromFile("public/images/newSprites/squid.png");
  sf::Texture crabTexture;
  crabTexture.loadFromFile("public/images/newSprites/crab.png");
  sf::Texture octopusTexture;
  octopusTexture.loadFromFile("public/images/newSprites/octopus.png");
  std::vector<std::vector<Invader *>> invaders(5);

  for (int i = 0; i < 5; i++)
  {
    std::vector<Invader *> invaderRow(11);
    for (int j = 0; j < 11; j++)
    {
      if (i == 0)
      {
        SpriteWrapper squidSpriteWrapper(squidTexture);
        Squid *squid = new Squid(i * 15, j * 15, squidSpriteWrapper);
        invaderRow.push_back(squid);
      }
      else if (i < 3)
      {
        SpriteWrapper crabSpriteWrapper(crabTexture);
        Crab *crab = new Crab(i * 15, j * 15, crabSpriteWrapper);
        invaderRow.push_back(crab);
      }
      else
      {
        SpriteWrapper octopusSpriteWrapper(octopusTexture);
        Octopus *octopus = new Octopus(i * 15, j * 15, octopusSpriteWrapper);
        invaderRow.push_back(octopus);
      }
    }
    invaders.push_back(invaderRow);
  }

  return invaders;
}
