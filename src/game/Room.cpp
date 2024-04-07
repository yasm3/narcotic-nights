#include "Room.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

Room::Room(const std::string& filename, Tileset& tileset) : m_tileset(tileset)
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

    m_name = roomData["name"].get<std::string>();
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
