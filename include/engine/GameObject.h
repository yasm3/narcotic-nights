#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Graphics.h"
#include "Input.h"
#include "Vector2D.h"
#include <random>

class GameObject {
    public:
        GameObject(Texture* texture, Vector2D<int> position, Graphics& graphics);

        virtual void update(float deltaTime, Input& input) = 0;
        virtual void draw();
        virtual bool collidesWith(GameObject& other);
        virtual void handleCollision(GameObject& other) = 0;

        void setTexture(Texture* texture);
        Vector2D<int> getPosition() const;
        Vector2D<int> getSize() const;
        void setPosition(Vector2D<int> newPosition);

        void show();
        void hide();
        bool getShowHitbox() const;
        void showHitbox(bool show);
        void drawHitbox();

    protected:
        Vector2D<int> m_position;
        Vector2D<int> m_size;
        Texture* m_texture;
        bool m_visible;
        bool AABBCollision(GameObject& other);
        bool m_showHitbox;
        Graphics& m_graphics;

        int generateRandomNumber(int min, int max) const;
};

#endif
