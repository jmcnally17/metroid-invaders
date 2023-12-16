#include "../../include/wrappers/iRenderWindow.hpp"

void adjustView(IRenderWindow &window, int windowWidth, int windowHeight)
{
  float widthRatio {(float)windowWidth / 1536};
  float heightRatio {(float)windowHeight / 1334};

  float newXOrigin {0};
  float newYOrigin {0};
  float newWidth {1536};
  float newHeight {1344};

  if (widthRatio < heightRatio)
  {
    newHeight *= heightRatio / widthRatio;
    newYOrigin = (1344 - newHeight) / 2;
  }
  else
  {
    newWidth *= widthRatio / heightRatio;
    newXOrigin = (1536 - newWidth) / 2;
  }

  sf::FloatRect visibleArea(newXOrigin, newYOrigin, newWidth, newHeight);
  window.setView(sf::View(visibleArea));
}
