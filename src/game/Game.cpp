#include "Game.h"
#include <iostream>
#include <filesystem>
#include "Dungeon.h"

Game::Game() : m_running(true),
               m_gamestate(GameState::PLAYING),
               m_window("Narcotic Nights", 1200, 800),
               m_renderer(nullptr),
               m_devMenu(*this),
               room(nullptr)
{}

Game::~Game()
{
}

void Game::init()
{
    m_window.init();
    m_renderer = m_window.getRenderer();
    m_graphics.attachWindow(&m_window);
    m_assetManager.attachRenderer(m_renderer);

    m_assetManager.loadTexture("sprite", "assets/img/sprite.png");
    m_assetManager.loadTileset("assets/img/tileset.png", 18, 18, 1, 20, 9);

    room = new Room("assets/room/room0.json", m_assetManager.getTileset());
}

void Game::cleanup()
{

}

void Game::update()
{
    float deltaTime = (SDL_GetTicks() - m_last_frame_time) / 1000.0;
    m_last_frame_time = SDL_GetTicks();
}

void Game::draw()
{
    m_graphics.clear();
    switch (m_gamestate) {
    case GameState::PLAYING:
        m_graphics.drawTilemap(room->getTilemap());
        break;
    }
}

void Game::run()
{
    try {
        init();
        while (m_running)
        {
            // update game logic
            update();

            // process inputs
            SDL_Event e;
            while(SDL_PollEvent(&e) != 0)
            {
                ImGui_ImplSDL2_ProcessEvent(&e);
                if(e.type == SDL_QUIT) m_running = false; 
                else if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
                {
                    m_window.setWidth(e.window.data1);
                    m_window.setHeight(e.window.data2);
                }
                if(e.type == SDL_KEYDOWN) {
                    // if(e.key.keysym.scancode == SDL_SCANCODE_T) m_devMenu.toggleMenu();
                }
            }

            if(m_input.isKeyDown(SDL_SCANCODE_T)) m_devMenu.toggleMenu();

            // start ImGUI frame
            ImGui_ImplSDLRenderer2_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            ImGuiIO& io = ImGui::GetIO();

            if(m_devMenu.isOpen()) m_devMenu.render();

            // rendering
            ImGui::Render();
            SDL_RenderSetScale(m_renderer, io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
            draw();
            ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
            m_graphics.present();
        }
        cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}
