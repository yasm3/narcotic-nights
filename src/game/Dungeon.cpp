#include "Dungeon.h"
#include <cassert>
#include <random>

Dungeon::Dungeon(int w, int h, AssetManager& aM, Graphics& graphics) : m_width(w), m_height(h), m_currentX(0), m_currentY(0), m_assetManager(aM), m_graphics(graphics)
{
    m_roomsGrid.resize(h, std::vector<int>(w, -1));
}

int Dungeon::getWidth() const
{
    return m_width;
}

int Dungeon::getHeight() const
{
    return m_height;
}

int Dungeon::getCurrentX() const
{
    return m_currentX;
}

int Dungeon::getCurrentY() const
{
    return m_currentY;
}

int Dungeon::getRoomId(int x, int y) const
{
    assert(x >= 0 && x < m_width && y >= 0 && y < m_height);
    return m_roomsGrid[y][x];
}

void Dungeon::setRoom(int x, int y, int roomId)
{
    assert(x >= 0 && x < m_width && y >= 0 && y < m_height);
    m_roomsGrid[y][x] = roomId;
}

void Dungeon::move(Direction direction)
{
    switch (direction) {
    case Direction::LEFT:
        assert(m_currentX > 0);
        m_currentX--;
        break;
    case Direction::UP:
        assert(m_currentY > 0);
        m_currentY--;
        break;
    case Direction::RIGHT:
        assert(m_currentX < m_width - 1);
        m_currentX++;
        break;
    case Direction::DOWN:
        assert(m_currentY < m_height - 1);
        m_currentY++;
        break;
    }
}

void Dungeon::addRoom(const std::string& filename)
{
    m_rooms.push_back(Room(filename, m_assetManager.getTileset()));
}

void Dungeon::randomGenerate(int maxRooms)
{
    for (int i = 0; i < m_width; ++i) {
        m_roomsGrid[i].assign(m_height, - 1);
    }
    // set at center of dungeon grid
    m_currentX = m_width / 2;
    m_currentY = m_height / 2;

    // room 0 is always the first room
    setRoom(m_currentX, m_currentY, 0);

    // init random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> disRoom(2, m_rooms.size() - 1);
    std::uniform_int_distribution<int> disDirection(0, 3);

    for (int i = 0; i < maxRooms; i++) {
        Direction randomDirection = static_cast<Direction>(disDirection(rd));
        move(randomDirection);

        // check if room already placed
        if (getRoomId(m_currentX, m_currentY) != -1) {
            switch (randomDirection) {
            case Direction::LEFT:
                move(Direction::RIGHT);
                break;
            case Direction::RIGHT:
                move(Direction::LEFT);
                break;
            case Direction::UP:
                move(Direction::DOWN);
                break;
            case Direction::DOWN:
                move(Direction::UP);
                break;
            }
            i--;
        }

        setRoom(m_currentX, m_currentY, disRoom(rd));
    }

    // set boss room
    setRoom(m_currentX, m_currentY, 1);

    // set at center of dungeon grid
    m_currentX = m_width / 2;
    m_currentY = m_height / 2;
}

void Dungeon::drawCurrentRoom() const
{
    int roomId = getRoomId(m_currentX, m_currentY);
    if (roomId != -1) {
        assert(roomId < m_rooms.size());
        m_graphics.drawTilemap(m_rooms[roomId].getTilemap());
    }
}

void Dungeon::printText() const
{
    std::cout << "Dungeon printing:" << std::endl;
    for (int j = 0; j < m_height; ++j) {
        for (int i = 0; i < m_width; ++i) {
            std::cout << getRoomId(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

