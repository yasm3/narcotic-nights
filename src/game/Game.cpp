#include "Game.h"
#include <iostream>
#include <filesystem>
#include "Dungeon.h"

Game::Game() : m_window("Narcotic Nights", 1200, 800),
               m_graphics(&m_window),
               m_renderer(nullptr),
               playerObject(nullptr, 320, 240, 72, 72) {}

Game::~Game() {}

void Game::init()
{
    m_window.init();
    m_renderer = m_window.getRenderer();
    m_graphics.attachWindow(&m_window);
}

void Game::cleanup()
{

}

void Game::update()
{
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    // std::cout << "mouseX: " << mouseX << " mouseY: " << mouseY << std::endl;
}

void Game::draw()
{

}

void Game::run()
{
    try {
        init();

        std::filesystem::path executablePath = std::filesystem::current_path();
        std::filesystem::path tilesetPath = executablePath / "assets" / "img" / "tileset.png";
        std::filesystem::path spritePath = executablePath / "assets" / "img" / "sprite.png";

        Tileset ts(18, 18);
        ts.loadFromFile(m_renderer, tilesetPath.string(), 1);
        // ts.printTiles();

        Tilemap tm(12, 8, &ts);

        for (int i = 0; i < tm.getHeight(); i++) {
            for (int j = 0; j < tm.getWidth(); j++) {
                tm.setTile(j, i, 109);
            }
        }

        Room introRoom("Intro Room", RoomType::NORMAL);
        Room normalRoom("Random normal room", RoomType::NORMAL);
        std::vector<Room> poolRooms {introRoom, normalRoom};

        Dungeon d;
        std::cout << "x: " << d.getCurrentRoomX() << " y: " << d.getCurrentRoomY() << std::endl;
        d.moveRight();
        d.moveRight();
        d.moveRight();
        d.moveDown();
        std::cout << "x: " << d.getCurrentRoomX() << " y: " << d.getCurrentRoomY() << std::endl;

        int fps = 60;
        int desiredDelta = 1000 / fps;

        // m_window.toggleFullscreen();

        while (m_window.isRunning()) {

            int startLoop = SDL_GetTicks();

            m_input.update();
            m_window.handleEvents();

            update();
            draw();

            m_graphics.clear();
            m_graphics.drawTilemap(tm);

            m_graphics.present();

            int delta = SDL_GetTicks() - startLoop;
            if (delta < desiredDelta) {
                SDL_Delay(desiredDelta - delta);
            }
        }
        cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}
