#ifndef _DOOROBJECT_H
#define _DOOROBJECT_H

#include "GameObject.h"

class DoorObject : public GameObject {
    public:
        DoorObject(Texture* texture, Vector2D<int> pos);
        void update(float deltaTime, Input& input);
        void draw(Graphics& graphics);
        bool collidesWith(GameObject& other);
        void handleCollision(GameObject& other);

        void setActive(bool active);
    private:
        bool m_active;
};

#endif
