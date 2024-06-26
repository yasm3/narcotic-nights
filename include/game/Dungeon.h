#ifndef _DUNGEON_H
#define _DUNGEON_H

#include <vector>
#include <random>
#include "AssetManager.h"
#include "DevMenu.h"
#include "Vector2D.h"
#include "Player.h"
#include "Room.h"

enum class Direction {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

/**
 * @class Dungeon
 * 
 * @brief Classe gérant la representation, l'affichage et la génération procédurale du donjon
 */
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
        void update(int deltaTime, Input& input, Player& player);
        void printText() const;
        static Direction oppositeDirection(Direction direction);
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

        friend class DevMenu;
};

#endif
