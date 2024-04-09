#include "Player.h"

Player::Player(Texture& texture, int posX, int posY) :
    GameObject(texture, posX, posY),
    m_dx(0.f),
    m_dy(0.f),
    m_maxSpeed(1.f),
    m_acceleration(2.f),
    m_friction(0.95f)
{}

void Player::update(float deltaTime, Input& input)
{

}

void Player::draw(Graphics& graphics)
{
    graphics.draw(m_texture, m_x, m_y, 4);
}

bool Player::collidesWith(GameObject& other)
{
    return false;
}

void Player::handleCollision(GameObject& other)
{

}
