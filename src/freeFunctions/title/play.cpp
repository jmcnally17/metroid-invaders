#include "../../../include/wrappers/iSound.hpp"
#include "../../../include/wrappers/iClock.hpp"

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme, IClock &movementClock)
{
  isPlaying = true;
  titleTheme.stop();
  battleTheme.play();
  movementClock.restart();
}
