#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Graphics.h"
#include "Input.h"

class GameObject {
    public:
        GameObject(Texture* texture, float x, float y, int w, int h);
        ~GameObject();

        void setTexture(Texture* texture);

        void draw(Graphics& graphics);
        void update(Uint32 deltaTime, Input& input);
    private:
        float m_x, m_y;
        float m_dx, m_dy;
        float m_maxSpeed;
        float m_accelleration;
        float m_friction;
        int m_w, m_h;
        Texture* m_texture;
};

#endif
