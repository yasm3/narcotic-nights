#include "Tilemap.h"

Tilemap::Tilemap(int width, int height, Tileset& tileset) : m_width(width), m_height(height), m_tileset(tileset)
{
    m_tiles.resize(width * height, 0);
}

Tilemap::Tilemap(int width, int height, Tileset& tileset, std::vector<int>& data) : m_width(width), m_height(height), m_tileset(tileset)
{
    m_tiles.resize(width * height, 0);
    if (data.size() != width * height)
        throw std::runtime_error("Invalid size for data tilemap");
    m_tiles = data;
}

int Tilemap::getWidth() const
{
    return m_width;
}

int Tilemap::getHeight() const
{
    return m_height;
}

Tileset& Tilemap::getTileset() const
{
    return m_tileset;
}

void Tilemap::setTile(int x, int y, int tileIndex)
{
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        m_tiles[y * m_width + x] = tileIndex;
    }
}

int Tilemap::getTileIndex(int x, int y) const
{
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        return m_tiles[y * m_width + x];
    }
    std::cout << "try to access out of range of tilemap" << std::endl;
    return 0;
}

Texture& Tilemap::getTile(int x, int y) const
{
    int tileIndex = getTileIndex(x, y);
    return m_tileset.getTile(tileIndex);
}
