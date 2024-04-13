#include "Game.h"
#include <iostream>
#include <filesystem>

Game::Game() : m_running(true),
    m_gamestate(GameState::PLAYING),
    m_window("Narcotic Nights", 1200, 1000),
    m_renderer(nullptr),
    m_devMenu(*this),
    m_last_frame_time(0),
    m_player(nullptr, 0, 0),
    m_dungeon(9, 9, m_assetManager, m_graphics)
{}

Game::~Game() {}

void Game::init()
{
    std::cout << "Window initialization..." << std::endl;
    m_window.init();
    m_renderer = m_window.getRenderer();
    m_graphics.attachWindow(&m_window);
    m_assetManager.attachRenderer(m_renderer);

    std::cout << "Loading assets..." << std::endl;
    m_assetManager.loadTexture("sprite", "assets/img/Sprite1.png");
    m_assetManager.loadTexture("door", "assets/img/door.png");
    m_assetManager.loadTileset("assets/img/tileset.png", 18, 18, 1, 20, 9);

    // player init
    std::cout << "Player creation..." << std::endl;
    m_player.setTexture(&m_assetManager.getTexture("sprite"));
    m_player.setPosX(m_window.getWidth() / 2);
    m_player.setPosY(m_window.getHeight() / 2);

    // dungeon
    m_dungeon.addRoom("assets/room/room0.json");
    m_dungeon.addRoom("assets/room/room1.json");
    m_dungeon.addRoom("assets/room/room2.json");

    m_dungeon.setRoom(1, 1, 2);
    m_dungeon.setRoom(1, 2, 1);
    m_dungeon.printText();
}

void Game::cleanup()
{

}

void Game::update(float deltaTime)
{
    m_player.update(deltaTime, m_input);
}

void Game::draw()
{
    m_graphics.clear();
    switch (m_gamestate) {
    case GameState::PLAYING:
        m_dungeon.drawCurrentRoom();
        m_player.draw(m_graphics);
        break;
    }
}

void Game::run()
{
    try {
        init();
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
        }
        cleanup();
    }
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }
}
