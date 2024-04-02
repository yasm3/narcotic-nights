#ifndef _ROOM_H
#define _ROOM_H

#include <string>

enum RoomType {
    NORMAL,
    TREASURE,
    SHOP,
    SECRET,
    BOSS
};

class Room {
    public:
        Room* leftRoom;
        Room* rightRoom;
        Room* upRoom;
        Room* downRoom;
        RoomType roomType;

        Room(std::string  name, RoomType roomType);
    private:
        std::string m_name;
};

#endif
