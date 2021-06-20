#include "Ground.hpp"
#include "Files.hpp"

Ground::Ground(sf::RenderWindow& window)
  : mWindow(window)
{
  if (!mTexture.loadFromFile(files::default_size_path() + "tileGrass1.png")) {
    throw std::runtime_error("Cannot a read graphic file!");
  }
}

void
Ground::draw(const int x, const int y)
{
  mSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
  mSprite.setTexture(mTexture);
  mWindow.draw(mSprite);
}
