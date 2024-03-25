#include "Tileset.h"

Tileset::Tileset(int tw, int th) : m_tileWidth(tw), m_tileHeight(th), m_tilesNumber(0){}

Tileset::~Tileset()
{
	for (auto const& [key, val] : m_tiles) {
		delete val;
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
			Texture* tile = new Texture(r, m_tileWidth, m_tileHeight);
			src = {i*m_tileWidth, j*m_tileHeight, m_tileWidth, m_tileHeight};
			SDL_SetRenderTarget(r, tile->getTexture());
			SDL_RenderCopy(r, tileset.getTexture(), &src, nullptr);
			SDL_SetRenderTarget(r, nullptr);

			m_tiles.insert({ m_tilesNumber, tile });
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
