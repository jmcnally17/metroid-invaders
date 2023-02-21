#include "../../include/models/iInvader.hpp"

IInvader::IInvader() {}

IInvader::IInvader(float width, float height, float x, float y, ISprite *sprite) : ObjectInterface(width, height, x, y, sprite) {}
