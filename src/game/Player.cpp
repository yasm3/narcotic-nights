#include "Player.h"

Player::Player(Texture& texture, int posX, int posY) :
    GameObject(texture, posX, posY),
    m_dx(0.f),
    m_dy(0.f),
    m_maxSpeed(1.f)
    m_acceleration(2.f),
    m_friction(0.95f)
{}

void Player::update(float deltaTime, Input& input)
{
    // physique de déplacement simple
    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_dx += m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        m_dx -= m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        m_dy += m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        m_dy -= m_acceleration;
    }

    if (abs(m_dx) > m_maxSpeed / 2 && abs(m_dy) > m_maxSpeed / 2) {
        m_dx *= getFriction();
        m_dy *= getFriction();
    }

    if (m_dx < -m_maxSpeed) m_dx = -m_maxSpeed;
    if (m_dx > m_maxSpeed) m_dx = m_maxSpeed;
    if (m_dy < -m_maxSpeed) m_dy = -m_maxSpeed;
    if (m_dy > m_maxSpeed) m_dy = m_maxSpeed;

    m_x += m_dx * deltaTime;
    m_y += m_dy * deltaTime;

    if (abs(m_dx) > 0) m_dx *= m_friction;
    if (abs(m_dy) > 0) m_dy *= m_friction;

    if (abs(m_dx) < 0.05) m_dx = 0;
    if (abs(m_dy) < 0.05) m_dy = 0;
}
