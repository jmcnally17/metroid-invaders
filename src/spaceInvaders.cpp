#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/models/laser.hpp"
#include "../include/models/laserCannon.hpp"
#include "../include/spaceInvaders.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Space Invaders");

  sf::Texture cannonTexture;
  cannonTexture.loadFromFile("public/images/newSprites/laserCannon.png");
  sf::Sprite cannonSprite(cannonTexture);
  SpriteWrapper cannonSpriteWrapper(cannonSprite);

  sf::Texture laserTexture;
  laserTexture.loadFromFile("public/images/newSprites/laser.png");
  sf::Sprite laserSprite(laserTexture);
  SpriteWrapper laserSpriteWrapper(laserSprite);
  Laser laser(laserSpriteWrapper);

  LaserCannon laserCannon(cannonSpriteWrapper, laser);

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

    drawObjects(window, laserCannon, laser);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      moveLaserCannon(laserCannon, 0.25);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      moveLaserCannon(laserCannon, -0.25);
    }
    laser.move();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      fireLaser(laserCannon);
    }
  }

  return 0;
}
