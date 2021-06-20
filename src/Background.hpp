#pragma once
#include "Ground.hpp"

inline constexpr int WIDTH = 1024;
inline constexpr int HEIGHT = 768;

class Background
{
public:
  Background(sf::RenderWindow& window);

  void draw();

private:
  inline static constexpr int M_WIDTH = WIDTH / GROUND_WIDTH;
  inline static constexpr int M_HEIGHT = HEIGHT / GROUND_HEIGHT;
  sf::RenderWindow& mWindow;
  std::vector<std::vector<Ground>> mGround;
};
