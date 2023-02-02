#include "../include/wrappers/renderWindowWrapper.hpp"
#include "../include/wrappers/spriteWrapper.hpp"
#include "../include/models/laserCannon.hpp"

int main()
{
  RenderWindowWrapper window(sf::VideoMode(1536, 1344), "Space Invaders");

  sf::Texture cannonTexture;
  cannonTexture.loadFromFile("public/images/laserCannon.png");
  sf::Sprite cannonSprite(cannonTexture);
  SpriteWrapper cannonSpriteWrapper(cannonSprite);
  LaserCannon laserCannon(cannonSpriteWrapper);

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

    window.clear();
    window.draw(cannonSpriteWrapper);
    laserCannon.draw(window);
    window.display();
  }

  return 0;
}
