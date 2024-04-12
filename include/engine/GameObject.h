#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Graphics.h"
#include "Input.h"

class GameObject {
    public:
        GameObject(Texture& texture, int posX, int posY);

        virtual void update(float deltaTime, Input& input, const GameObject* OtherObject = nullptr) = 0;
        virtual void draw(Graphics& graphics) = 0;
        virtual bool collidesWith(const GameObject& other) = 0;
        virtual void handleCollision(GameObject& other) = 0;

        int getPosX() const;
        int getPosY() const;
        int getWidth() const;
        int getHeight() const;
        void setPosition(int x, int y);
        
    protected:
        int m_x, m_y;
        int m_w, m_h;
        Texture& m_texture;
        bool m_visible;
};

#endif
