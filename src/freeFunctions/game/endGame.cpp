#include <vector>
#include <iostream>
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

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, int score, IText &scoreText, ISound &battleTheme, ISound &creditsTheme)
{
  isPlaying = false;
  gameOver = true;
  ridley.stopMovementSoundIfPlaying();
  scoreText.setString("You scored " + std::to_string(score) + " points");
  scoreText.setPosition(sf::Vector2f(768, 600));
  sf::FloatRect scoreTextRect = scoreText.getLocalBounds();
  scoreText.setOrigin(scoreTextRect.width / 2, 0);
  battleTheme.stop();
  creditsTheme.play();
}

void updateHighScore(int score, IText &highScoreText)
{
  std::string highScore;
  std::ifstream highScoreReadFile("highScore.txt");
  getline(highScoreReadFile, highScore);
  highScoreReadFile.close();
  if (highScore == "" || score > std::stoi(highScore))
  {
    std::ofstream highScoreWriteFile("highScore.txt");
    highScoreWriteFile << score;
    highScoreWriteFile.close();
  }
  highScoreText.setString("High Score: " + std::to_string(score));
}
