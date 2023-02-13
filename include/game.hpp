#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "./wrappers/iRenderWindow.hpp"
#include "./wrappers/iSound.hpp"
#include "./wrappers/iClock.hpp"
#include "./wrappers/iText.hpp"
#include "./models/iLaserCannon.hpp"
#include "./models/iLaser.hpp"
#include "./models/iInvader.hpp"
#include "./interfaces/collisionInterface.hpp"

void drawObjects(IRenderWindow &window, const ILaserCannon &cannon, const ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders, const IText &scoreText);

void evaluateLaserInvaderCollision(const CollisionInterface &collision, ILaser &laser, const std::vector<std::vector<IInvader *>> &invaders, int &score, IText &scoreText);

bool invadersHaveInvaded(const std::vector<std::vector<IInvader *>> &invaders);

void moveLaserCannon(ILaserCannon &cannon, float x);

void moveLaser(ILaser &laser);

void moveInvaders(const std::vector<std::vector<IInvader *>> &invaders, IClock &clock, int &interval, int &step, std::vector<ISound *> &sounds, int &soundCounter);

void fireLaser(ILaserCannon &cannon);

void endGame(bool &isPlaying, bool &gameOver, int score, IText &scoreText);

#endif
