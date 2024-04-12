#ifndef _Projectile_H
#define _Projectile_H

#include "GameObject.h"
#include "Input.h"
#include <utility>

class Projectile : public GameObject {
    public:
        Projectile(Texture& texture, int posX, int posY);
        void update(float deltaTime, Input& input, const GameObject* OtherObject) override;
        void draw(Graphics& graphics) override;
        bool collidesWith(const GameObject& other) override;
        void handleCollision(GameObject& other) override;
        std::pair<int, int> getMousePosition() const;
        bool isActive() const;

    private:
        float m_dx, m_dy;
        float m_maxSpeed;
        bool m_isActive;
        bool m_directionSet;
};

#endif