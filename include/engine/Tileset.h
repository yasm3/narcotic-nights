#ifndef _TILESET_H
#define _TILESET_H

#include "Texture.h"
#include <map>
#include <string>

class Tileset {
	public:
		Tileset(int tileWidth, int tileHeight);
		~Tileset();

		void load(SDL_Renderer* renderer, const std::string& filePath, int tilePadding);
		void print();
		std::map<int, Texture*> get();
	private:
		std::map<int, Texture*> m_tiles;
		int m_tileWidth, m_tileHeight;
		int m_tilesNumber;
};

#endif
