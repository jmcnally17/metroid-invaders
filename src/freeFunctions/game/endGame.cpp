#include <vector>
#include <fstream>
#include "../../../include/models/iMetroid.hpp"
#include "../../../include/models/iRidley.hpp"
#include "../../../include/wrappers/iText.hpp"
#include "../../../include/wrappers/iSound.hpp"

bool haveMetroidsInvaded(const std::vector<std::vector<IMetroid *>> &metroids)
{
  for (auto vec : metroids)
  {
    for (auto metroid : vec)
    {
      if (metroid->isAlive() && metroid->getPosition().y >= 1128)
      {
        return true;
      }
    }
  }
  return false;
}

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, ISound &battleTheme, ISound &creditsTheme)
{
  isPlaying = false;
  gameOver = true;
  ridley.stopMovementSoundIfPlaying();
  battleTheme.stop();
  creditsTheme.play();
}

void updateHighScore(std::unordered_map<std::string, int> &variables, IText &scoreText, IText &highScoreText)
{
  if (variables["score"] > variables["highScore"])
  {
    variables["highScore"] = variables["score"];
    std::ofstream highScoreWriteFile("highScore.txt");
    highScoreWriteFile << variables["score"];
    highScoreWriteFile.close();
    scoreText.setString("New High Score! " + std::to_string(variables["score"]) + " points");
    highScoreText.setString("High Score: " + std::to_string(variables["score"]));
  }
  else
  {
    scoreText.setString("You scored " + std::to_string(variables["score"]) + " points");
  }
  scoreText.setPosition(sf::Vector2f(768, 600));
  sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
  scoreText.setOrigin(scoreTextRect.width / 2, 0);
}
