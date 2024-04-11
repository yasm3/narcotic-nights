#ifndef _ENEMY_H
#define _ENEMY_H

#include "GameObject.h"
#include "Input.h"

class Enemy : public GameObject {
    public:
        Enemy(Texture& texture, int posX, int posY);
        void update(float deltaTime, Input& input, const GameObject* OtherObject) override;
        void draw(Graphics& graphics) override;
        bool collidesWith(GameObject& other) override;
        void handleCollision(GameObject& other) override;
    private:
        float m_dx, m_dy;
        float m_maxSpeed;
        bool m_isAlive;
};

#endif