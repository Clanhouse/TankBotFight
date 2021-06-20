#include "Background.hpp"
#include "Files.hpp"

Background::Background(sf::RenderWindow& window)
  : mWindow(window)
  , mGround(M_HEIGHT)
{
  for (int i = 0; i < M_HEIGHT; ++i) {
    sf::Texture t;
    t.loadFromFile(files::default_size_path() + "tileGrass1.png");
    mGround[i] = std::vector(M_WIDTH, Ground(mWindow, t, GroundType::Grass));
  }
}

void
Background::draw()
{
  for (int i = 0; i < M_HEIGHT; ++i) {
    for (int j = 0; j < M_WIDTH; ++j) {
      mGround[i][j].draw(j * GROUND_HEIGHT, i * GROUND_WIDTH);
    }
  }
}
