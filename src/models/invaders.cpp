#include "../../include/models/invaders.hpp"

Crab::Crab(float x, float y, ISprite *sprite) : Invader(66, 48, x, y, sprite, 20) {}

Octopus::Octopus(float x, float y, ISprite *sprite) : Invader(72, 48, x, y, sprite, 10) {}

Squid::Squid(float x, float y, ISprite *sprite) : Invader(48, 48, x, y, sprite, 30) {}
