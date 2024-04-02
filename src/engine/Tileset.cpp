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

void Tileset::loadFromFile(SDL_Renderer* r, const std::string& filePath, int tilePadding)
{
	Texture tileset(r, filePath);

	SDL_Rect src;
	SDL_Rect dst;
	for (int i = 0; i < tileset.getHeight() / m_tileHeight; i++) {
		for (int j = 0; j < tileset.getWidth() / m_tileWidth; j++) {
			std::shared_ptr<Texture> tile = std::make_shared<Texture>(r, m_tileWidth, m_tileHeight);

			src = {j * m_tileWidth + j * tilePadding, i * m_tileHeight + i * tilePadding, m_tileWidth, m_tileHeight};
			SDL_SetRenderTarget(r, tile->getNativeTexture());
			SDL_RenderCopy(r, tileset.getNativeTexture(), &src, nullptr);
			SDL_SetRenderTarget(r, nullptr);

			m_tiles.insert({ m_tiles.size(), tile });
		}
	}
}

void Tileset::printTiles()
{
	std::cout << "tileset content:" << std::endl;
	for (auto const& [key, val] : m_tiles) {
		std::cout << "ID: " << key << " texture: " << val << std::endl;
	}
}

std::shared_ptr<Texture> Tileset::getTile(int tileIndex)
{
	auto it = m_tiles.find(tileIndex);
	if (it != m_tiles.end()) {
		return it->second;
	}
	std::cerr << "texture undefined" << std::endl;
	return 0;
}
