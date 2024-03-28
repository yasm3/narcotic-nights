#ifndef _TILESET_H
#define _TILESET_H

#include <memory>
#include <map>
#include <string>
#include "Texture.h"

class Tileset {
	public:
		Tileset(int tileWidth, int tileHeight);

		void loadFromFile(SDL_Renderer* renderer, const std::string& filePath, int tilePadding);
		void printTiles();
		std::shared_ptr<Texture> getTile(int id);
	private:
		std::map<int, std::shared_ptr<Texture>> m_tiles;
		int m_tileWidth, m_tileHeight;
};

#endif
