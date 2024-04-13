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

    if (ImGui::CollapsingHeader("Dungeon")) {
        Dungeon& dun = m_game.m_dungeon;

        // print actual room
        ImGui::Text("X: %d", dun.getCurrentX());
        ImGui::SameLine();
        ImGui::Text("Y: %d", dun.getCurrentY());

        // move in dungeon
        if (ImGui::Button("Left")) {
            dun.move(Direction::LEFT);
        }

        ImGui::SameLine();
        if (ImGui::Button("Right")) {
            dun.move(Direction::RIGHT);
        }

        ImGui::SameLine();
        if (ImGui::Button("Up")) {
            dun.move(Direction::UP);
        }

        ImGui::SameLine();
        if (ImGui::Button("Down")) {
            dun.move(Direction::DOWN);
        }

        if (ImGui::Button("Random Generate")) {
            dun.randomGenerate(6);
        }

        // print dungeon
        ImVec4 col;
        for (int j = 0; j < dun.getHeight(); ++j) {
            for (int i = 0; i < dun.getWidth(); ++i) {
                int roomId = dun.getRoomId(i, j);

                if (roomId == -1) col = ImVec4(255, 0, 0, 255);
                else col = ImVec4(0, 255, 0, 255);

                if (i == dun.getCurrentX() && j == dun.getCurrentY()) col = ImVec4(255, 0, 255, 255);

                std::string labelButton = "Room " + std::to_string(roomId);
                ImGui::ColorButton(labelButton.c_str(), col);
                ImGui::SameLine();
            }
            ImGui::NewLine();
        }
    }

    ImGui::End();
}
