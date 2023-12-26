#include "../../../include/wrappers/ISound.hpp"
#include "../../../include/wrappers/IClock.hpp"

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme, IClock &movementClock)
{
  isPlaying = true;
  titleTheme.stop();
  battleTheme.play();
  movementClock.restart();
}
