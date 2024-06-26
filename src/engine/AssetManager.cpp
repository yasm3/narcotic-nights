#include "AssetManager.h"
#include <filesystem>

namespace fs = std::filesystem;

void AssetManager::attachRenderer(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}

void AssetManager::loadTexture(const std::string& name, const std::string& filename)
{
    std::shared_ptr<Texture> texture = std::make_shared<Texture>(m_renderer, filename);
    m_textures[name] = std::move(texture);
}

Texture& AssetManager::getTexture(const std::string& name) const
{
    auto it = m_textures.find(name);
    if(it == m_textures.end())
        throw std::runtime_error("Texture not found: " + name);
    return *it->second;
}

std::shared_ptr<Texture> AssetManager::getTexture(const std::string& name)
{
    auto it = m_textures.find(name);
    if (it == m_textures.end())
        throw std::runtime_error("Texture not found: " + name);
    return it->second;
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

