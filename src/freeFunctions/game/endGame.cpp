#include "../../../include/wrappers/iText.hpp"

void endGame(bool &isPlaying, bool &gameOver, int score, IText &scoreText)
{
  isPlaying = false;
  gameOver = true;
  scoreText.setString("You scored " + std::to_string(score) + " points");
  scoreText.setPosition(sf::Vector2f(0, 550));
}
