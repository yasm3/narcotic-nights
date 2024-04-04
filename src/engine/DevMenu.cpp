#include "DevMenu.h"
#include "Game.h"
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

DevMenu::DevMenu(Game& game) : m_game(game), m_showMainMenu(true)
{}

void DevMenu::toggleMenu()
{
    if(m_showMainMenu) m_showMainMenu = false;
    else m_showMainMenu = true;
}

bool DevMenu::isOpen()
{
    return m_showMainMenu;
}

void DevMenu::render()
{
    ImGuiIO& io = ImGui::GetIO();
    ImGui::Begin("Development Menu");

    ImGui::Text("FPS: %.1f", io.Framerate);
    ImGui::Text("Window: %dx%d", m_game.m_window.getWidth(), m_game.m_window.getHeight());

    std::ifstream room("assets/room/room0.json");
    json data = json::parse(room);
    room.close();


    ImGui::End();
}