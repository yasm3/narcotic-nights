#include "Player.h"

Player::Player(Texture* texture, Vector2D<int> position, Graphics& graphics) :
    GameObject(texture, position, graphics),
    m_speed(0.f),
    m_maxSpeed(1.f),
    m_acceleration(6.f),
    m_friction(0.95f)
{}

void Player::update(float deltaTime, Input& input)
{
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        m_position.y -= m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        m_position.y += m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        m_position.x -= m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_position.x += m_acceleration;
    }

    /*
    m_position.x += m_speed.x;
    m_position.y += m_speed.y;

    // accelerate with input keys
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        m_speed.y -= m_acceleration * deltaTime;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        m_speed.y += m_acceleration * deltaTime;
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        m_speed.x -= m_acceleration * -deltaTime;
    }
    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_speed.x += m_acceleration * -deltaTime;
        std::cout << m_speed << std::endl;
    }

   // std::cout << m_speed << std::endl;

    // resolve diagonal problem about too acceleration (pythagore)
    if (abs(m_speed.x) > m_maxSpeed / 2 && abs(m_speed.y) > m_maxSpeed / 2) {
        m_speed = m_speed * 0.75;
    }

    // limit speed
    m_speed.x = mid(-m_maxSpeed, m_speed.x, m_maxSpeed);
    m_speed.y = mid(-m_maxSpeed, m_speed.y, m_maxSpeed);

    // check collisions here !!!!!!

    // move player


    // apply friction
    if (abs(m_speed.x) > 0) m_speed.x *= m_friction;
    if (abs(m_speed.y) > 0) m_speed.y *= m_friction;
    if (abs(m_speed.x) < 0.02) m_speed.x = 0;
    if (abs(m_speed.y) < 0.02) m_speed.y = 0; */
}

bool Player::collidesWith(GameObject& other)
{
    return false;
}

float Player::mid(float first, float second, float third)
{
    if ((first <= second && first >= third) || (first >= second && first <= third))
        return first;
    else if ((second <= first && second >= third) || (second >= first && second <= third))
        return second;
    else
        return third;
}
