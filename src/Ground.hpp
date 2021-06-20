#pragma once
#include <SFML/Graphics.hpp>

enum class GroundType
{
  Sand,
  Grass,
};

inline constexpr int GROUND_WIDTH = 64;
inline constexpr int GROUND_HEIGHT = 64;

class Ground
{
public:
  Ground(sf::RenderWindow& window);

  void draw(const int x, const int y);

  sf::Texture mTexture;

private:
  sf::RenderWindow& mWindow;
  sf::Sprite mSprite;
};
