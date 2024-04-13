#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Tileset.h"
#include "Room.h"
#include "SDL2/SDL.h"

class AssetManager {
    public:
        void attachRenderer(SDL_Renderer* renderer);
        
        void loadTexture(const std::string& name, const std::string& filename);
        Texture& getTexture(const std::string& name) const;
        
        void loadTileset(const std::string& filename, int tileWidth, int tileHeight, int tilePadding, int totalWidth, int totalHeight);
        Tileset& getTileset() const;

        
    private:
        SDL_Renderer* m_renderer;
        std::unordered_map<std::string, std::unique_ptr<Texture>> m_textures;
        std::unique_ptr<Tileset> m_tileset;
        std::unordered_map<int, std::unique_ptr<Room>> m_rooms;
};

#endif
