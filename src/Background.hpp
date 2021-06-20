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
  sf::RenderWindow& mWindow;
  std::vector<std::vector<Ground>> mGround;
};
