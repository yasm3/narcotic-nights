#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Graphics.h"
#include "Input.h"
#include "Vector2D.h"

class GameObject {
    public:
        GameObject(Texture* texture, Vector2D<int> position);

        virtual void update(float deltaTime, Input& input) = 0;
        virtual void draw(Graphics& graphics);
        virtual bool collidesWith(GameObject& other) = 0;
        virtual void handleCollision(GameObject& other) = 0;

        void setTexture(Texture* texture);
        Vector2D<int> getPosition() const;
        void setPosition(Vector2D<int> newPosition);

        void show();
        void hide();

    protected:
        Vector2D<int> m_position;
        Vector2D<int> m_size;
        Texture* m_texture;
        bool m_visible;
};

#endif
