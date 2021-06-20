#include "Background.hpp"
#include "Files.hpp"

Background::Background(sf::RenderWindow& window)
  : mWindow(window)
  , mGround(HEIGHT / GROUND_HEIGHT)
{
  for (int i = 0; i < HEIGHT / GROUND_HEIGHT; ++i) {
    mGround[i] = std::vector(WIDTH / GROUND_WIDTH, Ground(mWindow));
  }
}

void
Background::draw()
{
  for (int i = 0; i < HEIGHT / GROUND_HEIGHT; ++i) {
    for (int j = 0; j < WIDTH / GROUND_WIDTH; ++j) {
      mGround[i][j].draw(j * GROUND_WIDTH, i * GROUND_HEIGHT);
    }
  }
}
