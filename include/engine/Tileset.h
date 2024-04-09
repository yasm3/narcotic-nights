#ifndef _TILESET_H
#define _TILESET_H

#include <memory>
#include <map>
#include <vector>
#include <string>
#include "Texture.h"

class Tileset {
	public:
		Tileset(int tileWidth, int tileHeight);

		int getTileWidth() const;
		int getTileHeight() const;

		void loadFromFile(SDL_Renderer* renderer, const std::string& filePath, int tilePadding, int totalWidth, int totalHeight);
		Texture& getTile(int tileIndex);
		int getTilesNumber() const;
	private:
		std::vector<std::unique_ptr<Texture>> m_tiles;
		int m_tileWidth, m_tileHeight;
};

#endif
