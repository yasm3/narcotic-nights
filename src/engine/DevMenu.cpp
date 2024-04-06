#include "DevMenu.h"
#include "Game.h"
#include "Room.h"

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

    if (ImGui::CollapsingHeader("Render Infos")) {
        ImGui::Text("FPS: %.1f", io.Framerate);
        ImGui::Text("Window: %dx%d", m_game.m_window.getWidth(), m_game.m_window.getHeight());

    }

    if (ImGui::CollapsingHeader("Game State")) {
        if (ImGui::Button("Playing")) {
            m_game.m_gamestate = GameState::PLAYING;
        }
        ImGui::SameLine();
        if (ImGui::Button("Room Editor")) {
            m_game.m_gamestate = GameState::ROOM_EDITOR;
        }
    }

    ImGui::End();
}
