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
        Room(std::string name, RoomType roomType);
        Room(std::string filename);
    private:
        std::string m_name;
        RoomType m_roomType;

        RoomType strToType(const std::string& roomType);
};

#endif
