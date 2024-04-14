#include "Room.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "DoorObject.h"

using json = nlohmann::json;

Room::Room(const std::string& filename, Tileset& tileset) :
    m_tileset(tileset),
    m_id(-1),
    m_type(RoomType::NORMAL)
{
    loadFromFile(filename);
}

RoomType Room::strToType(const std::string& roomType) const
{
    if(roomType == "normal") {
        return RoomType::NORMAL;
    }
    else if (roomType == "treasure") {
        return RoomType::TREASURE;
    }
    else if(roomType == "secret") {
        return RoomType::SECRET;
    }
    else if(roomType == "boss") {
        return RoomType::BOSS;
    }
    else {
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


const Tilemap& Room::getTilemap() const
{
    return *m_tilemap;
}

int Room::getID() const
{
    return m_id;
}

void Room::addGameObject(std::shared_ptr<GameObject> object)
{
    m_gameObjects.push_back(object);
}

void Room::draw(Graphics& graphics)
{
    graphics.drawTilemap(*m_tilemap);
    for (auto& object : m_gameObjects) {
        object->draw();
    }
}

void Room::update(Player& player)
{
    for (auto& object : m_gameObjects) {
        if (DoorObject* door = dynamic_cast<DoorObject*>(object.get())) {
            if (door->collidesWith(player)) {
                door->handleCollision(player);
            }
        }
    }
}

Vector2D<int> Room::changeRoom()
{
    return Vector2D<int>();
}
