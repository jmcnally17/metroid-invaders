#include <fstream>
#include "../../../include/models/IRidley.hpp"
#include "../../../include/adaptors/IText.hpp"
#include "../../../include/adaptors/ISound.hpp"

void endGame(bool &isPlaying, bool &gameOver, IRidley &ridley, std::unordered_map<std::string, ISound*> &themes)
{
  isPlaying = false;
  gameOver = true;
  ridley.stopMovementSoundIfPlaying();
  auto battleTheme {themes.find("battle")->second};
  auto creditsTheme {themes.find("credits")->second};
  battleTheme->stop();
  creditsTheme->play();
}

void updateHighScore(std::unordered_map<std::string, int> &variables, const std::unordered_map<std::string, IText*> &textObjects)
{
  auto scoreText {textObjects.find("score")->second};
  auto highScoreText {textObjects.find("highScore")->second};
  if (variables["score"] > variables["highScore"])
  {
    variables["highScore"] = variables["score"];
    std::ofstream highScoreWriteFile("highScore.txt");
    highScoreWriteFile << variables["score"];
    highScoreWriteFile.close();
    scoreText->setString("New High Score! " + std::to_string(variables["score"]) + " points");
    highScoreText->setString("High Score: " + std::to_string(variables["score"]));
  }
  else
  {
    scoreText->setString("You scored " + std::to_string(variables["score"]) + " points");
  }
  scoreText->setPosition(sf::Vector2f(768, 600));
  sf::FloatRect scoreTextRect {scoreText->getLocalBounds()};
  scoreText->setOrigin(scoreTextRect.width / 2, 0);
}
