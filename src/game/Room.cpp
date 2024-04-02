#include "Room.h"

#include <utility>

Room::Room(std::string name, RoomType roomType) : m_name(std::move(name)), leftRoom(nullptr), rightRoom(nullptr), upRoom(nullptr), downRoom(nullptr)
{

}