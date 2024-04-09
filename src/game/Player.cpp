#include "Player.h"

Player::Player(Texture* texture, float x, float y, int w, int h) :
    Entity(),
    m_dx(0), m_dy(0),
    score(0), isAlive(true)
{
    setPosition(x, y);
    setSize(w, h);
    setTexture(texture);
    setMaxSpeed(1.f);
    setAcceleration(2.f);
    setFriction(0.95f);
}



Player::~Player() {}


void Player::update(Uint32 deltaTime, Input& input)
{
    // physique de déplacement simple
    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_dx += getAcceleration();
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        m_dx += -1;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        m_dy += getAcceleration();
    }
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        m_dy += -getAcceleration();
    }

    if (abs(m_dx) > getMaxSpeed() / 2 && abs(m_dy) > getMaxSpeed() / 2) {
        m_dx *= getFriction();
        m_dy *= getFriction();
    }

    if (m_dx < -getMaxSpeed()) m_dx = -getMaxSpeed();
    if (m_dx > getMaxSpeed()) m_dx = getMaxSpeed();
    if (m_dy < -getMaxSpeed()) m_dy = -getMaxSpeed();
    if (m_dy > getMaxSpeed()) m_dy = getMaxSpeed();

     setPosition(getX() + m_dx * deltaTime, getY() + m_dy * deltaTime);


    if (abs(m_dx) > 0) m_dx *= getFriction();
    if (abs(m_dy) > 0) m_dy *= getFriction();

    if (abs(m_dx) < 0.05) m_dx = 0;
    if (abs(m_dy) < 0.05) m_dy = 0;
}
