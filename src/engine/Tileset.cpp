#include "Tileset.h"

Tileset::Tileset(int tw, int th) : m_tileWidth(tw), m_tileHeight(th), m_tilesNumber(0){}

Tileset::~Tileset()
{
	for (auto const& [key, val] : m_tiles) {
		val->~Texture();
		m_tiles.erase(key);
	}
}

void Tileset::load(SDL_Renderer* r, const std::string& filePath, int tilePadding)
{
	Texture tileset(r, filePath);

	SDL_Rect src;
	SDL_Rect dst;
	for (int i = 0; i < tileset.getWidth() / m_tileWidth; i++) {
		for (int j = 0; j < tileset.getHeight() / m_tileHeight; j++) {
			Texture tile(r, m_tileWidth, m_tileHeight);
			src = {i*m_tileWidth+tilePadding, j*m_tileHeight+tilePadding, m_tileWidth, m_tileHeight};
			dst = { 0,0,0,0 };
			SDL_SetRenderTarget(r, tile.getTexture());
			SDL_RenderCopy(r, tileset.getTexture(), &src, &dst);
			SDL_SetRenderTarget(r, nullptr);

			m_tiles.insert({ m_tilesNumber, &tile });
			m_tilesNumber++;
		}
	}
}

void Tileset::print()
{
	for (auto const& [key, val] : m_tiles) {
		std::cout << "ID: " << key << " texture: " << val << std::endl;
	}
}

std::map<int, Texture*> Tileset::get()
{
	return m_tiles;
}
