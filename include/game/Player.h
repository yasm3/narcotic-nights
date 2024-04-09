#ifndef _PLAYER_H
#define _PLAYER_H

#include "GameObject.h"
#include "Input.h"

class Player : public GameObject {
    public:
        Player(Texture& texture, int posX, int posY);
        void update(float deltaTime, Input& input) override;

    private:
        float m_dx, m_dy;
        float m_maxSpeed;
        float m_acceleration;
        float m_friction;
};

#endif
