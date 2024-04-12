#include "Enemy.h"

Enemy::Enemy(Texture& texture, int x, int y): 
                    GameObject(texture, x, y), 
                    m_dx(0), m_dy(0),
                    m_maxSpeed(150.f), 
                    m_isAlive(true) 
{
    
}

void Enemy::update(float deltaTime, Input& m_input,const GameObject* OtherObject) {
   

    // Récupérer la position actuelle du joueur
    /*float playerX = OtherObject->getPosX();
    float playerY = OtherObject->getPosY();


    float dx = playerX - getPosX();
    float dy = playerY - getPosY();

    float distance = sqrt(dx * dx + dy * dy);

    if (distance != 0) {
        dx /= distance;
        dy /= distance;
    }

    setPosition(getPosX() + dx * m_maxSpeed * deltaTime, getPosY() + dy * m_maxSpeed * deltaTime);*/
}

void Enemy::draw(Graphics& graphics)
{
    graphics.draw(m_texture, m_x, m_y, 70, 95);
}

bool Enemy::collidesWith(const GameObject& other)
{
    return false;
}

void Enemy::handleCollision(GameObject& other)
{

}