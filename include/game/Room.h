#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include "Tilemap.h"
#include "DoorObject.h"

enum RoomType {
    NORMAL,
    TREASURE,
    SHOP,
    SECRET,
    BOSS
};

enum RoomDirection {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class Room {
    public:
        Room(const std::string& filename, Tileset& tileset);
        Tilemap& getTilemap() const;
        int getID() const;

        void loadDoors(Texture& texture);
        void openDoor(RoomDirection direction);
    private:
        int m_id;
        RoomType m_type;
        Tileset& m_tileset;
        std::unique_ptr<Tilemap> m_tilemap;

        DoorObject m_leftDoor;
        DoorObject m_rightDoor;
        DoorObject m_upDoor;
        DoorObject m_downDoor;
       
        RoomType strToType(const std::string& roomType) const;
        void loadFromFile(const std::string& filename);
};

#endif
