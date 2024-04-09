#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Graphics.h"

class GameObject {
    public:
        GameObject(Texture& texture, int posX, int posY);

        virtual void update(float deltaTime);
        virtual void draw(Graphics& graphics);
        virtual bool collidesWith(GameObject& other) = 0;
        virtual void handleCollision(GameObject& other) = 0;

        int getPosX() const;
        int getPosY() const;
    protected:
        int m_x, m_y;
        Texture& m_texture;
        bool m_visible;
};

#endif
