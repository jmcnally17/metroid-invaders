#include "../../include/models/iMetroid.hpp"

IMetroid::IMetroid() {}

IMetroid::IMetroid(float width, float height, float x, float y, ISprite *sprite) : ObjectInterface(width, height, x, y, sprite) {}
