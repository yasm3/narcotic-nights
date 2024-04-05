#include "Room.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

Room::Room(std::string name, RoomType roomType) : m_name(std::move(name)), m_roomType(roomType)
{

}

Room::Room(std::string filename)
{
    // parse json file
    std::ifstream roomFile(filename);
    json roomData = json::parse(roomFile);
    roomFile.close();

    m_name = roomData["name"].get<std::string>();
    m_roomType = strToType(roomData["type"].get<std::string>());
    
}

RoomType Room::strToType(const std::string& roomType)
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