#include "../../../include/wrappers/iSound.hpp"

void play(bool &isPlaying, ISound &titleTheme, ISound &battleTheme)
{
  isPlaying = true;
  titleTheme.stop();
  battleTheme.play();
}
