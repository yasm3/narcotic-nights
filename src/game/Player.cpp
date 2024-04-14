#include "Player.h"

Player::Player(Texture* texture, Vector2D<int> position) :
    GameObject(texture, position),
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
    if (m_texture != nullptr) {
        graphics.draw(*m_texture, m_position.x, m_position.y, 4);
    }
}

bool Player::collidesWith(GameObject& other)
{
    return false;
}

void Player::handleCollision(GameObject& other)
{

}
