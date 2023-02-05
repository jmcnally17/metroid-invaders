#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/models/laser.hpp"
#include "../include/wrappers/soundWrapper.hpp"
#include "../include/models/laserCannon.hpp"
#include "../include/models/squid.hpp"
#include "../include/spaceInvaders.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Space Invaders");

  Laser laser = makeLaser();
  LaserCannon cannon = makeCannon(laser);
  Invader squid = makeInvader(400, 500);

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

    drawObjects(window, cannon, laser, squid);
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

Invader makeInvader(float x, float y)
{
  sf::Texture squidTexture;
  squidTexture.loadFromFile("public/images/newSprites/squid.png");
  SpriteWrapper *squidSpriteWrapper = new SpriteWrapper(squidTexture);
  SpriteWrapper &rSpriteWrapper = *squidSpriteWrapper;

  Squid squid(x, y, rSpriteWrapper);
  return squid;
}
