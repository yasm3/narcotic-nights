#ifndef _ASSETMANAGER_H
#define _ASSETMANAGER_H

#include <string>
#include <unordered_map>
#include <memory>
#include "Texture.h"
#include "Tileset.h"
#include "SDL2/SDL.h"

/**
 * @class AssetManager
 * 
 * @brief Classe permettant de gérer les assets du jeu
 */
class AssetManager {
    public:
        void attachRenderer(SDL_Renderer* renderer); ///< Permet de lier le renderer
        
        void loadTexture(const std::string& name, const std::string& filename); ///< Permet de charger une texture à partir d'un fichier avec un nom unique
        Texture& getTexture(const std::string& name) const; ///< Obtenir une réference vers la texture
        std::shared_ptr<Texture> getTexture(const std::string& name); ///< Obtenir un pointeur vers la texture 
        
        void loadTileset(const std::string& filename, int tileWidth, int tileHeight, int tilePadding, int totalWidth, int totalHeight); ///< Charger un tileset
        Tileset& getTileset() const; ///< Obtenir réference du tileset
        
    private:
        SDL_Renderer* m_renderer;
        std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
        std::unique_ptr<Tileset> m_tileset;
};

#endif
