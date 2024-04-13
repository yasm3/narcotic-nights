#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include "Tilemap.h"
#include "DoorObject.h"

enum RoomType {
    NORMAL,
    TREASURE,
    SECRET,
    BOSS
};

enum Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class Room {
    public:
        Room(const std::string& filename, Tileset& tileset);
        void loadFromFile(const std::string& filename);
        const Tilemap& getTilemap() const;
        int getID() const;

        void loadDoors(Texture& texture);
        void openDoor(Direction direction);
    private:
        int m_id;
        RoomType m_type;
        Tileset& m_tileset;
        std::shared_ptr<Tilemap> m_tilemap;

        DoorObject m_leftDoor;
        DoorObject m_rightDoor;
        DoorObject m_upDoor;
        DoorObject m_downDoor;
       
        RoomType strToType(const std::string& roomType) const;
};

#endif
