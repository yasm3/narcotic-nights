#include "Tileset.h"

Tileset::Tileset(int tw, int th) : m_tileWidth(tw), m_tileHeight(th) {}

int Tileset::getTileWidth() const
{
	return m_tileWidth;
}

int Tileset::getTileHeight() const
{
	return m_tileHeight;
}

void Tileset::loadFromFile(SDL_Renderer* r, const std::string& filePath, int tilePadding, int totalWidth, int totalHeight)
{
	std::unique_ptr<Texture> defaultTile = std::make_unique<Texture>(r, m_tileWidth, m_tileHeight);
	m_tiles.push_back(std::move(defaultTile));

	Texture tileset(r, filePath);

	SDL_Rect src;
	SDL_Rect dst;
	for (int i = 0; i < totalHeight; i++) {
		for (int j = 0; j < totalWidth; j++) {
			std::unique_ptr<Texture> tile = std::make_unique<Texture>(r, m_tileWidth, m_tileHeight);
			src = {j * m_tileWidth + j * tilePadding, i * m_tileHeight + i * tilePadding, m_tileWidth, m_tileHeight};
			SDL_SetRenderTarget(r, tile->getNativeTexture());
			SDL_RenderCopy(r, tileset.getNativeTexture(), &src, nullptr);
			SDL_SetRenderTarget(r, nullptr);
			m_tiles.push_back(std::move(tile));
		}
	}
}

Texture& Tileset::getTile(int tileIndex)
{
	return *m_tiles[tileIndex];
}

int Tileset::getTilesNumber() const
{
	return m_tiles.size();
}
