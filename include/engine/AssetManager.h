#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Tileset.h"
#include "SDL2/SDL.h"

class AssetManager {
    public:
        void attachRenderer(SDL_Renderer* renderer);
        
        void loadTexture(const std::string& name, const std::string& filename);
        Texture& getTexture(const std::string& name);
        
        void loadTileset(int tileWidth, int tileHeight, int tilePadding, const std::string& filename);
        Tileset& getTileset();
    private:
        SDL_Renderer* m_renderer;
        std::unordered_map<std::string, std::unique_ptr<Texture>> m_textures;
        std::unique_ptr<Tileset> m_tileset;
};

#endif