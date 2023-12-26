#include "../../../include/adaptors/ISound.hpp"
#include "../../../include/adaptors/IClock.hpp"

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme, IClock &movementClock)
{
  isPlaying = true;
  titleTheme.stop();
  battleTheme.play();
  movementClock.restart();
}
