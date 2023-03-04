#include "../../../include/wrappers/iSound.hpp"

void play(bool &isPlaying, ISound &titleTheme)
{
  isPlaying = true;
  titleTheme.stop();
}
