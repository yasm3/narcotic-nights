#include "Dungeon.h"
#include <cassert>
#include <queue>
#include <filesystem>
#include "DoorObject.h"

Dungeon::Dungeon(int w, int h, AssetManager& aM, Graphics& graphics) :
    m_size(w,h),
    m_currentPos(0,0),
    m_assetManager(aM),
    m_graphics(graphics),
    m_mt((std::random_device())())
{
    m_roomsGrid.resize(h, std::vector<int>(w, -1));
}

int Dungeon::getRoomId(Vector2D<int> pos) const
{
    assert(pos.x >= 0 && pos.x < m_size.x && pos.y >= 0 && pos.y < m_size.y);
    return m_roomsGrid[pos.y][pos.x];
}

void Dungeon::setRoom(Vector2D<int> pos, int roomId)
{
    assert(pos.x >= 0 && pos.x < m_size.x && pos.y >= 0 && pos.y < m_size.y);
    m_roomsGrid[m_currentPos.y][m_currentPos.x] = roomId;
}

bool Dungeon::move(Direction direction)
{
    Vector2D<int> newPos = m_currentPos + getMoveVec(direction);
    if (!isOverEdge(newPos)) {
        m_currentPos = newPos;
        return true;
    }
    return false;
}

bool Dungeon::move(Vector2D<int> newPos)
{
    if (!isOverEdge(newPos)) {
        m_currentPos = newPos;
        return true;
    }
    return false;
}

int Dungeon::addRoom(int id)
{
    std::string filename = "assets/room/room" + std::to_string(id) + ".json";
    m_rooms.push_back(Room(filename, m_assetManager.getTileset()));
    return m_rooms.size() - 1;
}

void Dungeon::randomGenerate(int maxRooms)
{
    // reset dungeon
    for (int j = 0; j < m_size.y; ++j) {
        for (int i = 0; i < m_size.x; ++i) {
            m_roomsGrid[j][i] = -1;
        }
    }
    m_rooms.clear();

    // init generation at random place
    Vector2D<int> m_firstPos(generateRandomNumber(0, m_size.x - 1), generateRandomNumber(0, m_size.y - 1));
    m_currentPos = Vector2D<int>(m_firstPos);
    setRoom(m_currentPos, addRoom(0));   

    // queue of room to place
    std::queue<int> roomQueue;
    for (int i = 0; i < maxRooms; ++i) {
        int roomId = generateRandomNumber(1, getAvailableRoom() - 1);
        roomQueue.push(roomId);
    }

    // place rooms
    while (!roomQueue.empty()) {
        Direction directionToGo = static_cast<Direction>(generateRandomNumber(0, 3));
        Vector2D<int> currentPos = m_currentPos;
        if (move(directionToGo) && !isOccupied(m_currentPos)) {

            setRoom(m_currentPos, addRoom(roomQueue.front()));

            std::shared_ptr<DoorObject> firstDoor = std::make_shared<DoorObject>(m_assetManager.getTexture("door").get(), directionToGo, m_currentPos, m_graphics, *this);
            std::shared_ptr<DoorObject> nextDoor = std::make_shared<DoorObject>(m_assetManager.getTexture("door").get(), oppositeDirection(directionToGo), currentPos, m_graphics, *this);
   
            m_rooms[getRoomId(currentPos)].addGameObject(std::move(firstDoor));
            m_rooms[getRoomId(m_currentPos)].addGameObject(std::move(nextDoor));
            roomQueue.pop();
        }
    }

    // go to first room
    m_currentPos = m_firstPos;
}

void Dungeon::draw()
{
    int roomId = getRoomId(m_currentPos);
    if (roomId != -1) {
        assert(roomId < m_rooms.size());
        m_rooms[roomId].draw(m_graphics);
    }
}

void Dungeon::update(Player& player)
{
    int roomId = getRoomId(m_currentPos);
    if (roomId != -1) {
        assert(roomId < m_rooms.size());
        m_rooms[roomId].update(player);
    }
}

void Dungeon::printText() const
{
    std::cout << "Dungeon printing:" << std::endl;
    for (int j = 0; j < m_size.y; ++j) {
        for (int i = 0; i < m_size.x; ++i) {
            std::cout << getRoomId(Vector2D<int>(i,j)) << " ";
        }
        std::cout << std::endl;
    }
}

Vector2D<int> Dungeon::getMoveVec(Direction direction) const
{
    switch (direction) {
    case Direction::LEFT:
        return Vector2D(-1, 0);
    case Direction::UP:
        return Vector2D(0, -1);
    case Direction::RIGHT:
        return Vector2D(1, 0);
    case Direction::DOWN:
        return Vector2D(0, 1);
    default:
        return Vector2D(0);
    }
}

bool Dungeon::isOccupied(Vector2D<int> pos) const
{
    if (!(pos.x >= 0 && pos.x < m_size.x && pos.y >= 0 && pos.y < m_size.y))
        return true;
    return getRoomId(pos) != -1;
}

bool Dungeon::isOverEdge(Vector2D<int> pos) const
{
    if (!(pos.x >= 0 && pos.x < m_size.x && pos.y >= 0 && pos.y < m_size.y))
        return true;
    return false;
}

int Dungeon::generateRandomNumber(int min, int max)
{
    std::uniform_int_distribution<int> dis(min, max);
    return dis(m_mt);
}

int Dungeon::getAvailableRoom() const
{
    int count = 0;
    std::filesystem::path p = "data/room";
    for (auto& p : std::filesystem::directory_iterator(p)) count++;
    return count;
}

Direction Dungeon::oppositeDirection(Direction direction) const
{
    switch (direction) {
    case Direction::LEFT:
        return Direction::RIGHT;
    case Direction::UP:
        return Direction::DOWN;
    case Direction::RIGHT:
        return Direction::LEFT;
    case Direction::DOWN:
        return Direction::UP;
    default:
        return direction;
    }
}

