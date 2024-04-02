#ifndef _DUNGEON_H
#define _DUNGEON_H

#include "Room.h"
#include <vector>

class Dungeon {
    public:
        Dungeon(std::vector<Room>& poolRooms);

        int getCurrentRoomX() const;
        int getCurrentRoomY() const;
        Room* getCurrentRoom() const;

        bool moveRight();
        bool moveLeft();
        bool moveUp();
        bool moveDown();

        void randomGenerate();

    private:
        std::vector<Room*> m_rooms;
        int m_currentRoom;
        int m_maxHeight;
        int m_maxWidth;
        int m_numberRooms;
        std::vector<Room>& m_poolRooms;
};

#endif