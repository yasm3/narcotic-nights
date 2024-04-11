#include "AssetManager.h"
#include <filesystem>

namespace fs = std::filesystem;

void AssetManager::attachRenderer(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

void AssetManager::loadTexture(const std::string& name, const std::string& filename)
{
    std::unique_ptr<Texture> texture = std::make_unique<Texture>(m_renderer, filename);
    m_textures[name] = std::move(texture);
}

Texture& AssetManager::getTexture(const std::string& name) const
{
    auto it = m_textures.find(name);
    if(it == m_textures.end()) {
        throw std::runtime_error("Texture not found: " + name);
    }
    return *it->second;
}

void AssetManager::loadTileset(const std::string& filename, int tileWidth, int tileHeight, int tilePadding, int totalWidth, int totalHeight)
{
    std::unique_ptr<Tileset> tileset = std::make_unique<Tileset>(tileWidth, tileHeight);
    tileset->loadFromFile(m_renderer, filename, tilePadding, totalWidth, totalHeight);
    m_tileset = std::move(tileset);
}

Tileset& AssetManager::getTileset() const
{
    return *m_tileset;
}

void AssetManager::loadRooms()
{
    std::string roomFolder = "assets/room";
    if (fs::exists(roomFolder) && fs::is_directory(roomFolder)) {
        for (const auto& entry : fs::directory_iterator(roomFolder)) {
            std::unique_ptr<Room> room = std::make_unique<Room>(entry.path().string(), getTileset());
            m_rooms.push_back(std::move(room));
        }
    }
    else {
        throw std::runtime_error("Room folder not found");
    }
    
}

const std::vector<std::unique_ptr<Room>>& AssetManager::getRooms() const
{
    return m_rooms;
}
