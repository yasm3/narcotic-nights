#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameObject.h"
#include "Input.h"

class Player : public GameObject {
    public:
        Player(Texture* texture, Vector2D<int> position, Graphics& graphics);
        void update(float deltaTime, Input& input) override;
        void handleCollision(GameObject& other);
    private:
        Vector2D<float> m_speed;
        float m_maxSpeed;
        float m_acceleration;
        float m_friction;
        bool m_blocked = false;
        float mid(float first, float second, float third);
        float m_hp = 100;
};

#endif
