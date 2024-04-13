#ifndef _DUNGEON_H
#define _DUNGEON_H

#include <vector>
#include "AssetManager.h"

class Dungeon {
    public:
        Dungeon(int width, int height, AssetManager& assetManager, Graphics& graphics);

        int getWidth() const;
        int getHeight() const;
        int getCurrentX() const;
        int getCurrentY() const;

        int getRoomId(int x, int y) const;
        void setRoom(int x, int y, int roomId);
        void move(Direction direction);

        void addRoom(const std::string& filename);

        void drawCurrentRoom() const;
        void printText() const;
    private:
        std::vector<std::vector<int>> m_roomsGrid;
        std::vector<Room> m_rooms;
        int m_width, m_height;
        AssetManager& m_assetManager;
        Graphics& m_graphics;
        int m_currentX, m_currentY;
};

#endif
