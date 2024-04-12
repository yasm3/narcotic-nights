#include "Game.h"
#include <iostream>
#include <filesystem>
#include "Dungeon.h"

Game::Game() : m_running(true),
m_gamestate(GameState::PLAYING),
m_window("Narcotic Nights", 1200, 800),
m_renderer(nullptr),
m_devMenu(*this),
m_last_frame_time(0),
m_projectiles(),
room(nullptr)
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
    m_assetManager.loadTileset("assets/img/tileset.png", 18, 18, 1, 20, 9);
    m_assetManager.loadTexture("enemy", "assets/img/enemy.png");
    m_assetManager.loadTexture("bullet", "assets/img/attack.png");//bullet Temporaire

    room = new Room("assets/room/room0.json", m_assetManager.getTileset());
    std::cout << "Player creation..." << std::endl;

    m_player = std::make_unique<Player>(m_assetManager.getTexture("sprite"), m_window.getWidth()/2, m_window.getHeight()/2);
    m_enemy = std::make_unique<Enemy>(m_assetManager.getTexture("enemy"), 300, 200);
    
    
}

void Game::cleanup()
{
    for (auto& projectile : m_projectiles) 
    {
        if (projectile->isActive()) {
            // Supprimer le projectile s'il est inactif
            projectile.reset(); // Libérer la mémoire du projectile
        }
    }

    // Effacer les projectiles inactifs du vecteur
    m_projectiles.erase(std::remove_if(m_projectiles.begin(), m_projectiles.end(),
                                   [](const std::unique_ptr<Projectile>& projectile) {
                                       return !projectile; 
                                   }),
                    m_projectiles.end());
}

void Game::update(float deltaTime)
{   
    m_input.update();
    m_player->update(deltaTime, m_input);
    
    m_enemy->update(deltaTime, m_input, m_player.get());
    
    // Mettre à jour la position de chaque projectile
    for (auto& projectile : m_projectiles) {
        projectile->update(deltaTime, m_input, m_player.get()); // Supposons que vous avez une fonction update dans la classe Projectile
        projectile->handleCollision(*m_enemy.get());
    }
    std::cout << "update projectile fait..." << std::endl;
}

void Game::draw()
{
    m_graphics.clear();
    switch (m_gamestate) {
    case GameState::PLAYING:
        m_graphics.drawTilemap(room->getTilemap());
        m_player->draw(m_graphics);
        m_enemy->draw(m_graphics);
        for (auto& projectile : m_projectiles) {
            if(projectile->isActive())
            projectile->draw(m_graphics); // Supposons que vous avez une fonction draw dans la classe Projectile
        }
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
                else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_T) {
                    m_devMenu.toggleMenu();
                }
                else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                        m_projectiles.push_back(std::make_unique<Projectile>(m_assetManager.getTexture("bullet"), 100, 100));  
                    
                }
                
            
            }
            
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
