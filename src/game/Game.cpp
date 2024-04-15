#include "Game.h"
#include <iostream>
#include <filesystem>

Game::Game() : m_running(true),
    m_gamestate(GameState::PLAYING),
    m_window("Narcotic Nights", 1200, 1000),
    m_renderer(nullptr),
    m_devMenu(*this),
    m_last_frame_time(0),
    m_player(nullptr, Vector2D<int>(0), m_graphics),
    m_dungeon(9, 6, m_assetManager, m_graphics)
{}

Game::~Game() {}

void Game::init()
{
    std::cout << "Window initialization..." << std::endl;
    m_window.init();
    m_renderer = m_window.getRenderer();
    m_graphics.attachWindow(&m_window);
    m_graphics.setScale(5);
    m_assetManager.attachRenderer(m_renderer);

    std::cout << "Loading assets..." << std::endl;
    m_assetManager.loadTexture("player", "data/img/player.png");
    m_assetManager.loadTexture("door", "data/img/door.png");
    m_assetManager.loadTexture("mob", "data/img/mob.png");
    m_assetManager.loadTileset("data/img/tileset.png", 18, 18, 1, 4, 1);

    m_window.setWidth(12 * m_assetManager.getTileset().getTileWidth() * m_graphics.getScale());
    m_window.setHeight(9 * m_assetManager.getTileset().getTileHeight() * m_graphics.getScale());

    // player init
    std::cout << "Player creation..." << std::endl;
    m_player.setTexture(m_assetManager.getTexture("player").get());
    m_player.setPosition(Vector2D<int>(m_window.getWidth() / 2, m_window.getHeight() / 2));

    // dungeon
    m_dungeon.randomGenerate(10);
}

void Game::cleanup()
{

}

void Game::update(float deltaTime)
{
    m_player.update(deltaTime, m_input);
    m_dungeon.update(deltaTime, m_input, m_player);
}

void Game::draw()
{
    m_graphics.clear();
    switch (m_gamestate) {
    case GameState::PLAYING:
        m_dungeon.draw();
        m_player.draw();
        break;
    }
}

void Game::run()
{
    try {
        init();
        float desiredDelta = 1000 / 60;
        while (m_running)
        {
            float deltaTime = (SDL_GetTicks() - m_last_frame_time) / 1000.0;
            m_last_frame_time = SDL_GetTicks();

            // update game logic
            update(deltaTime);

            // process inputs
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0)
            {
                ImGui_ImplSDL2_ProcessEvent(&e);
                if (e.type == SDL_QUIT) m_running = false;
                else if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    m_window.setWidth(e.window.data1);
                    m_window.setHeight(e.window.data2);
                }
                if (e.type == SDL_KEYDOWN) {
                    m_input.update();
                }
                if (e.type == SDL_KEYUP) {
                    m_input.update();
                }
            }

            if (m_input.isKeyDown(SDL_SCANCODE_T)) m_devMenu.toggleMenu();

            // start ImGUI frame
            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            ImGuiIO& io = ImGui::GetIO();

            if (m_devMenu.isOpen()) m_devMenu.render();

            // rendering
            ImGui::Render();
            SDL_RenderSetScale(m_renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
            draw();
            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
            m_graphics.present();

            if (deltaTime < desiredDelta) {
                SDL_Delay(desiredDelta - deltaTime);
            }
        }
        cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}
