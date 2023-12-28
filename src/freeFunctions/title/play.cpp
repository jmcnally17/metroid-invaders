#include "../../../include/adaptors/ISound.hpp"
#include "../../../include/adaptors/IClock.hpp"

void play(bool &isPlaying, const std::unordered_map<std::string, ISound*> &themes, IClock &movementClock)
{
  auto titleTheme {themes.find("title")->second};
  auto battleTheme {themes.find("battle")->second};
  isPlaying = true;
  titleTheme->stop();
  battleTheme->play();
  movementClock.restart();
}
