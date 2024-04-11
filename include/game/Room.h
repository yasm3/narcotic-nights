#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include "Tilemap.h"

enum RoomType {
    NORMAL,
    TREASURE,
    SHOP,
    SECRET,
    BOSS
};

class Room {
    public:
        Room(const std::string& filename, Tileset& tileset);
        Tilemap& getTilemap() const;
    private:
        int m_id;
        RoomType m_type;
        Tileset& m_tileset;
        std::unique_ptr<Tilemap> m_tilemap;

        RoomType strToType(const std::string& roomType) const;
        void loadFromFile(const std::string& filename);
};

#endif
