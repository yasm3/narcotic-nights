#ifndef _ROOM_H
#define _ROOM_H

#include <string>
#include "Tilemap.h"
#include "GameObject.h"
#include "Player.h"

enum RoomType {
    NORMAL,
    TREASURE,
    SECRET,
    BOSS
};

class Room {
    public:
        Room(const std::string& filename, Tileset& tileset);
        void loadFromFile(const std::string& filename);
        const Tilemap& getTilemap() const;
        int getID() const;
        void addGameObject(std::shared_ptr<GameObject> object);
        void draw(Graphics& graphics);
        void update(Player& player);
        void addColliders(Graphics& graphics);
    private:
        int m_id;
        RoomType m_type;
        Tileset& m_tileset;
        std::unique_ptr<Tilemap> m_tilemap;

        std::vector<std::shared_ptr<GameObject>> m_gameObjects;
       
        RoomType strToType(const std::string& roomType) const;
};

#endif
