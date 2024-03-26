#include "GameObject.h"

GameObject::GameObject(Texture* t, float x, float y, int w, int h) :
    m_texture(t),
    m_x(x), m_y(y),
    m_dx(0), m_dy(0),
    m_maxSpeed(1.f),
    m_accelleration(2.f),
    m_friction(0.95),
    m_w(w), m_h(h) {}
GameObject::~GameObject() {}

void GameObject::setTexture(Texture* t)
{
    m_texture = t;
}

void GameObject::draw(Graphics& graphics)
{
    if (m_texture != nullptr) {
       // graphics.draw(m_texture, m_x, m_y, m_w, m_h);
    }
}

void GameObject::update(Uint32 deltaTime, Input& input)
{
    // physique de deplacement simple
    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        m_dx += m_accelleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        m_dx += -1;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        m_dy += m_accelleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        m_dy += -m_accelleration;
    }
    

    if (abs(m_dx) > m_maxSpeed / 2 && abs(m_dy) > m_maxSpeed / 2) {
        m_dx *= m_friction;
        m_dy *= m_friction;
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
