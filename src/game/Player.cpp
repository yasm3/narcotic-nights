#include "Player.h"

Player::Player(Texture* texture, Vector2D<int> position, Graphics& graphics) :
    GameObject(texture, position, graphics),
    m_dx(0.f),
    m_dy(0.f),
    m_maxSpeed(1.f),
    m_acceleration(2.f),
    m_friction(0.95f)
{}

void Player::update(float deltaTime, Input& input)
{

}

bool Player::collidesWith(GameObject& other)
{
    return false;
}
