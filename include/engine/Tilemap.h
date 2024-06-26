#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <vector>
#include "Tileset.h"

/**
 * @class Tilemap
 * 
 * @brief Classe representant une Tilemap
 */
class Tilemap {
    public:
        Tilemap(int width, int height, Tileset& tileset);
        Tilemap(int width, int height, Tileset& tileset, std::vector<int>& data);
        int getWidth() const;
        int getHeight() const;
        Tileset& getTileset() const;

        void setTile(int x, int y, int tileIndex);
        int getTileIndex(int x, int y) const;

        Texture& getTile(int x, int y) const;

    private:
        int m_width, m_height;
        std::vector<int> m_tiles;
        Tileset& m_tileset;
};

#endif
