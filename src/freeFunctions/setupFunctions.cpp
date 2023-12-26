#include <fstream>
#include "../../include/adaptors/TextAdaptor.hpp"

void pullHighScore(std::unordered_map<std::string, int> &variables, IText &highScoreText)
{
  std::string highScoreString;
  std::ifstream highScoreFile("highScore.txt");
  getline(highScoreFile, highScoreString);
  highScoreFile.close();
  if (!(highScoreString == ""))
  {
    variables["highScore"] = std::stoi(highScoreString);
    highScoreText.setString("HighScore: " + highScoreString);
  }
}
