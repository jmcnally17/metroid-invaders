#include "../../include/models/metroids.hpp"

Alpha::Alpha(float x, float y, ISprite *sprite) : Metroid(x, y, sprite, 20) {}

Gamma::Gamma(float x, float y, ISprite *sprite) : Metroid(x, y, sprite, 10) {}

Larva::Larva(float x, float y, ISprite *sprite) : Metroid(x, y, sprite, 30) {}
