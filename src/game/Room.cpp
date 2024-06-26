#include "Room.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "DoorObject.h"
#include "ColliderObject.h"
#include "MobObject.h"
#include "BulletObject.h"

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

void Room::addColliders(Graphics& graphics)
{
    for (int i = 0; i < m_tilemap->getWidth(); ++i) {
        std::shared_ptr<ColliderObject> collider = std::make_shared<ColliderObject>(
            Vector2D<int>(i * graphics.getScale() * m_tileset.getTileWidth(), 0),
            Vector2D<int>(m_tileset.getTileWidth(), m_tileset.getTileHeight()),
            graphics
        );
        addGameObject(std::move(collider));
    }

    for (int i = 0; i < m_tilemap->getWidth(); ++i) {
        std::shared_ptr<ColliderObject> collider = std::make_shared<ColliderObject>(
            Vector2D<int>(i * graphics.getScale() * m_tileset.getTileWidth(), (getTilemap().getHeight() - 1) * m_tileset.getTileHeight() * graphics.getScale()),
            Vector2D<int>(m_tileset.getTileWidth(), m_tileset.getTileHeight()),
            graphics
        );
        addGameObject(std::move(collider));
    }

    for (int i = 0; i < getTilemap().getHeight(); ++i) {
        std::shared_ptr<ColliderObject> collider = std::make_shared<ColliderObject>(
            Vector2D<int>(0, i * m_tileset.getTileHeight() * graphics.getScale()),
            Vector2D<int>(m_tileset.getTileWidth(), m_tileset.getTileHeight()),
            graphics
        );
        addGameObject(std::move(collider));
    }

    for (int i = 0; i < getTilemap().getHeight(); ++i) {
        std::shared_ptr<ColliderObject> collider = std::make_shared<ColliderObject>(
            Vector2D<int>((getTilemap().getWidth() - 1) * m_tileset.getTileWidth() * graphics.getScale(), i * m_tileset.getTileHeight() * graphics.getScale()),
            Vector2D<int>(m_tileset.getTileWidth(), m_tileset.getTileHeight()),
            graphics
        );
        addGameObject(std::move(collider));
    }
}

void Room::loadFromFile(const std::string& filename)
{
    std::cout << "Loading room from " + filename << std::endl;
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
    graphics.drawTilemap(getTilemap());
    for (auto& object : m_gameObjects) {
        object->draw();
    }
}

void Room::update(int deltaTime, Input& input, Player& player, AssetManager& assetManager, Graphics& graphics)
{
    for (auto& object : m_gameObjects) {
        if (DoorObject* door = dynamic_cast<DoorObject*>(object.get())) {
            if (door->collidesWith(player)) {
                door->handleCollision(player);
            }
        }
        else if (ColliderObject* collider = dynamic_cast<ColliderObject*>(object.get())) {
            if (collider->collidesWith(player)) {
                collider->handleCollision(player);
            }
        }
        else if (MobObject* mob = dynamic_cast<MobObject*>(object.get())) {
            mob->update(deltaTime, input);
            if (mob->collidesWith(player)) {
                mob->handleCollision(player);
            }
        }
        else {
            object->update(deltaTime, input);
        }
    }

    if (input.isKeyDown(SDL_SCANCODE_SPACE)) {
        
    }
}
