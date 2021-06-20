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
  Ground(sf::RenderWindow& window, sf::Texture texture, GroundType type);
  void draw(const int x, const int y);

  Ground(const Ground&);
  Ground& operator=(Ground&);

  Ground(Ground&&);
  Ground& operator=(Ground&&);
  ~Ground() = default;

private:
  const GroundType mGroundType;
  const sf::Texture mTexture;
  sf::RenderWindow& mWindow;
  sf::Sprite mSprite;
};

