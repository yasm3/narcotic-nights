#include "Entity.h"

Entity::Entity(){}
Entity::~Entity(){}

void Entity::draw (Graphics& graphics) 
{
    if (m_texture != nullptr) 
       graphics.draw( m_texture, m_x, m_y, m_w, m_h);
    
}

void Entity::update(Uint32 deltaTime, Input& input){}
bool Entity::checkCollision(const Entity& otherEntity) const {
        int otherX1 = otherEntity.m_x;
        int otherY1 = otherEntity.m_y;
        int otherX2 = otherEntity.m_x + otherEntity.m_w;
        int otherY2 = otherEntity.m_y + otherEntity.m_h;

        bool overlapX = (m_x <= otherX2 && m_x + m_w >= otherX1) || (otherX1 <= m_x + m_w && otherX2 >= m_x);

        bool overlapY = (m_y <= otherY2 && m_y + m_h >= otherY1) || (otherY1 <= m_y + m_h && otherY2 >= m_y);

        bool collision = overlapX && overlapY;

    return collision;
 }


