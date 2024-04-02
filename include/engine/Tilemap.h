#ifndef _TILEMAP_H
#define _TILEMAP_H

#include <vector>
#include "Tileset.h"

class Tilemap {
    public:
        Tilemap();
        Tilemap(int width, int height, Tileset* tileset);
        int getWidth() const;
        int getHeight() const;
        [[nodiscard]] Tileset* getTileset() const;
        void setTile(int x, int y, int tileIndex);
        int getTileIndex(int x, int y) const;
        [[nodiscard]] std::shared_ptr<Texture> getTile(int x, int y) const;
    private:
        int m_width, m_height;
        std::vector<int> m_tiles;
        Tileset* m_tileset;
};

#endif
