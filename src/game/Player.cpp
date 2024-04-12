#include "Player.h"

Player::Player(Texture& texture, int posX, int posY) :
    GameObject(texture, posX, posY),
    m_dx(0.f),
    m_dy(0.f),
    m_maxSpeed(300.f),
    m_acceleration(400.f),
    m_friction(0.95f)
{}

void Player::update(float deltaTime, Input& input, const GameObject* otherObject)
{
    float accelerationX = 0.f;
    float accelerationY = 0.f;

    if (input.isKeyDown(SDL_SCANCODE_RIGHT)) {
        accelerationX += m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_LEFT)) {
        accelerationX -= m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_DOWN)) {
        accelerationY += m_acceleration;
    }
    if (input.isKeyDown(SDL_SCANCODE_UP)) {
        accelerationY -= m_acceleration;
    }

    // Apply friction
    if (accelerationX == 0.f) {
        m_dx *= m_friction;
    }
    if (accelerationY == 0.f) {
        m_dy *= m_friction;
    }

    // Update velocities
    m_dx += accelerationX;
    m_dy += accelerationY;

    // Limit velocities
    if (m_dx < -m_maxSpeed) m_dx = -m_maxSpeed;
    if (m_dx > m_maxSpeed) m_dx = m_maxSpeed;
    if (m_dy < -m_maxSpeed) m_dy = -m_maxSpeed;
    if (m_dy > m_maxSpeed) m_dy = m_maxSpeed;

    // Update position
    setPosition( getPosX() + m_dx * deltaTime, getPosY() + m_dy * deltaTime);
 
}


void Player::draw(Graphics& graphics)
{
    graphics.draw(m_texture, m_x, m_y, 4);
}

bool Player::collidesWith(const GameObject& other) {
    // Coordonnées et dimensions du premier objet
    int playerX1 = m_x;
    int playerY1 = m_y;
    int playerX2 = m_x + m_w;
    int playerY2 = m_y + m_h;

    // Coordonnées et dimensions de l'autre objet
    int otherX1 = other.getPosX();
    int otherY1 = other.getPosY();
    int otherX2 = other.getPosX() + other.getWidth();
    int otherY2 = other.getPosY() + other.getHeight();

    bool collision = (playerX1 < otherX2) &&
                     (playerX2 > otherX1) &&
                     (playerY1 < otherY2) &&
                     (playerY2 > otherY1);

    std::cout << "Collision: " << collision << std::endl;

    return collision;
}


void Player::handleCollision(GameObject& other)
{
   

}
