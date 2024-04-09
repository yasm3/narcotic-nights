#include "DevMenu.h"
#include "Game.h"
#include "Room.h"

DevMenu::DevMenu(Game& game) : m_game(game), m_showMainMenu(false)
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
        if (ImGui::Button("Toggle Fullscreen")) m_game.m_window.toggleFullscreen();
    }

    if (ImGui::CollapsingHeader("Game State")) {
        if (ImGui::Button("Playing")) {
            m_game.m_gamestate = GameState::PLAYING;
        }
    }

    if (ImGui::CollapsingHeader("Tileset")) {
        Tileset& ts = m_game.m_assetManager.getTileset();
        for (int i = 0; i < ts.getTilesNumber(); ++i) {
            if (i % 5 != 0) ImGui::SameLine();
            ImGui::ImageButton(ts.getTile(i).getNativeTexture(), ImVec2(ts.getTileWidth() * 3, ts.getTileHeight() * 3));
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
                std::string id = "ID " + std::to_string(i);
                ImGui::SetTooltip(id.c_str());
            }
        }
    }

    ImGui::End();
}
