#include "Ground.hpp"
#include "Files.hpp"

Ground::Ground(sf::RenderWindow& w, sf::Texture t, GroundType gt)
  : mGroundType(gt), mTexture(std::move(t)),  mWindow(w) 
{
  mSprite.setTexture(mTexture);
}

Ground::Ground(const Ground& other): Ground(other.mWindow, other.mTexture, other.mGroundType) 
{
}

Ground& Ground::operator=(Ground& other) 
{
    Ground copy(other);
    std::swap(*this, copy);
    mSprite.setTexture(mTexture);
    return *this;
}

Ground& Ground::operator=(Ground&& other) 
{
    Ground copy(std::move(other));
    std::swap(*this, copy);
    mSprite.setTexture(mTexture);
    return *this;
}

Ground::Ground(Ground&& other): Ground(other.mWindow, std::move(other.mTexture), std::move(other.mGroundType)) {
}

void
Ground::draw(const int x, const int y)
{
  mSprite.setPosition(static_cast<float>(x), static_cast<float>(y));
  mWindow.draw(mSprite);
}
