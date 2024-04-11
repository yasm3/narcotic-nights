#include "Room.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Room::Room(const std::string& filename, Tileset& tileset) :
    m_tileset(tileset),
    m_leftDoor(nullptr),
    m_rightDoor(nullptr),
    m_upDoor(nullptr),
    m_downDoor(nullptr)
{
    loadFromFile(filename);
}

RoomType Room::strToType(const std::string& roomType) const
{
    if(roomType == "normal") {
        return RoomType::NORMAL;
    } else if(roomType == "treasure") {
        return RoomType::TREASURE;
    } else if(roomType == "shop") {
        return RoomType::SHOP;
    } else if(roomType == "secret") {
        return RoomType::SECRET;
    } else if(roomType == "boss") {
        return RoomType::BOSS;
    } else {
        throw std::runtime_error("invalid room type"); 
    }
}

void Room::loadFromFile(const std::string& filename)
{
    std::ifstream roomFile(filename);
    if (!roomFile.is_open())
        throw std::runtime_error("Failed to open room file : " + filename);
    json roomData = json::parse(roomFile);
    roomFile.close();

    // parse

    m_id = roomData["id"].get<int>();
    m_type = strToType(roomData["type"].get<std::string>());

    int width = roomData["width"].get<int>();
    int height = roomData["height"].get<int>();
    std::vector<int> data = roomData["tilemap"].get<std::vector<int>>();
    std::unique_ptr tilemap = std::make_unique<Tilemap>(width, height, m_tileset, data);
    m_tilemap = std::move(tilemap);
}


Tilemap& Room::getTilemap() const
{
    return *m_tilemap;
}

int Room::getID() const
{
    return m_id;
}

void Room::loadDoors(Texture& texture)
{
    m_leftDoor.setTexture(&texture);
    m_rightDoor.setTexture(&texture);
    m_upDoor.setTexture(&texture);
    m_downDoor.setTexture(&texture);
    m_leftDoor.setActive(true);
}

void Room::openDoor(RoomDirection direction)
{
    switch (direction) {
    case RoomDirection::LEFT:
        m_leftDoor.setActive(true);
        break;
    case RoomDirection::UP:
        m_upDoor.setActive(true);
        break;
    case RoomDirection::RIGHT:
        m_rightDoor.setActive(true);
        break;
    case RoomDirection::DOWN:
        m_downDoor.setActive(true);
        break;
    }
}
