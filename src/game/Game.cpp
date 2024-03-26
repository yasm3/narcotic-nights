#include "Game.h"
#include <iostream>
#include <filesystem>

Game::Game() : m_window("Narcotic Nights", 640, 480),
               m_graphics(nullptr),
               m_renderer(nullptr),
               playerObject(nullptr, 320, 240, 72, 72), t(nullptr) {}
Game::~Game() {}

void Game::init()
{
    m_window.init();
    m_renderer = m_window.getRenderer();
    m_graphics.setRenderer(m_renderer);

    std::filesystem::path executablePath = std::filesystem::current_path();
    std::filesystem::path spritePath = executablePath / "assets" / "img" / "sprite.png";
    std::filesystem::path tilesetPath = executablePath / "assets" / "img" / "tileset.png";
    t = new Texture(m_renderer, spritePath.string());
    playerObject.setTexture(t);
    ts = new Tileset(18, 18);
    ts->load(m_renderer, tilesetPath.string(), 1);
    ts->print();
    
}

void Game::cleanup()
{
    delete t;
    delete ts;
}

void Game::update(Uint32 deltaTime)
{
    playerObject.update(deltaTime, m_input);
}

void Game::draw()
{
    m_graphics.clear(255, 255, 0, 255);
    m_graphics.draw(ts->get()[4], 16, 16, 64, 64);
    playerObject.draw(m_graphics);
    m_graphics.present();
}

void Game::run()
{
    try {
        init();

        Uint32 lastUpdateTime = SDL_GetTicks();

        while (m_window.isRunning()) {
            Uint32 currentTime = SDL_GetTicks();
            Uint32 deltaTime = currentTime - lastUpdateTime;
            lastUpdateTime = currentTime;

            m_input.update();
            m_window.handleEvents();

            update(deltaTime);
            draw();
        }
        cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}
