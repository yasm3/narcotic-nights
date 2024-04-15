#ifndef _DOOROBJECT_H
#define _DOOROBJECT_H

#include "GameObject.h"
#include "Dungeon.h"

class DoorObject : public GameObject {
    public:
        DoorObject(Texture* texture, Direction direction, Vector2D<int> destination, Graphics& graphics, Dungeon& dungeon);
        void update(float deltaTime, Input& input);
        void handleCollision(GameObject& other);

        void setActive(bool active);
        Vector2D<int> getDestination() const;
        Vector2D<int> getDoorPosition(Direction direction) const;
        Vector2D<int> getNextPlayerPosition(Direction direction) const;
    private:
        bool m_active;
        Vector2D<int> m_destination;
        Direction m_direction;
        Dungeon& m_dungeon;
};

#endif
