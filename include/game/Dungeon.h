#ifndef _DUNGEON_H
#define _DUNGEON_H

#include <vector>
#include <random>
#include "AssetManager.h"
#include "DevMenu.h"
#include "Vector2D.h"

enum class Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class Dungeon {
    public:
        Dungeon(int width, int height, AssetManager& assetManager, Graphics& graphics);

        int getRoomId(Vector2D<int> pos) const;
        void setRoom(Vector2D<int> pos, int roomId);
        bool move(Direction direction);
        bool move(Vector2D<int> newPos);

        int addRoom(int id);
        void randomGenerate(int maxRooms);

        void draw();
        void update(Player& player);
        void printText() const;
    private:

        // private data
        std::vector<std::vector<int>> m_roomsGrid;
        std::vector<Room> m_rooms;
        Vector2D<int> m_size;
        Vector2D<int> m_currentPos;
        AssetManager& m_assetManager;
        Graphics& m_graphics;
        std::mt19937 m_mt;

        // private methods
        Vector2D<int> getMoveVec(Direction direction) const;
        bool isOccupied(Vector2D<int> pos) const;
        bool isOverEdge(Vector2D<int> pos) const;
        int generateRandomNumber(int min, int max);
        int getAvailableRoom() const;
        Direction oppositeDirection(Direction direction) const;

        friend class DevMenu;
};

#endif
