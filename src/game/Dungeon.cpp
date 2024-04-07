#include "Dungeon.h"

Dungeon::Dungeon(std::vector<Room>& poolRooms) : m_currentRoom(0), m_maxHeight(9), m_maxWidth(8), m_poolRooms(poolRooms), m_numberRooms(0)
{

}

Room* Dungeon::getCurrentRoom() const
{
    return m_rooms[m_currentRoom];
}

int Dungeon::getCurrentRoomX() const
{
    return m_currentRoom % 10;
}

int Dungeon::getCurrentRoomY() const
{
    return (m_currentRoom / 10) % 10;
}

bool Dungeon::moveRight()
{
    if(getCurrentRoomX() < m_maxWidth) {
        m_currentRoom += 1;
        return true;
    }
    return false;
}

bool Dungeon::moveLeft()
{
    if(getCurrentRoomX() > 0) {
        m_currentRoom -= 1;
        return true;
    }
    return false;
}

bool Dungeon::moveUp()
{
    if(getCurrentRoomY() > 0) {
        m_currentRoom -= 10;
        return true;
    }
    return false;
}

bool Dungeon::moveDown()
{
    if(getCurrentRoomY() < m_maxHeight) {
        m_currentRoom += 10;
        return true;
    }
    return false;
}

void Dungeon::randomGenerate()
{

}

