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

    if (ImGui::CollapsingHeader("Player")) {
        Player& player = m_game.m_player;
        int posX = player.getPosition().x;
        int posY = player.getPosition().y;

        if (ImGui::Button("Show Hitbox")) {
            player.showHitbox(true);
        }

        if (ImGui::Button("Hide Hitbox")) {
            player.showHitbox(false);
        }

        if (ImGui::SliderInt("Position X", &posX, 0, m_game.m_window.getWidth())) {
            player.setPosition(Vector2D<int>(posX, posY));
        }

        if (ImGui::SliderInt("Position Y", &posY, 0, m_game.m_window.getHeight())) {
            player.setPosition(Vector2D<int>(posX, posY));
        }
    }

    if (ImGui::CollapsingHeader("Dungeon")) {
        Dungeon& dun = m_game.m_dungeon;

        // print actual room
        ImGui::Text("X: %d", dun.m_currentPos.x);
        ImGui::SameLine();
        ImGui::Text("Y: %d", dun.m_currentPos.y);

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
            dun.randomGenerate(10);
        }

        // print dungeon
        ImVec4 col;
        for (int j = 0; j < dun.m_size.y; ++j) {
            for (int i = 0; i < dun.m_size.x; ++i) {
                int roomId = dun.getRoomId(Vector2D<int>(i,j));

                if (roomId == -1) col = ImVec4(0, 0, 0, 255);
                else col = ImVec4(0, 255, 0, 255);

                if (i == dun.m_currentPos.x && j == dun.m_currentPos.y) col = ImVec4(255, 0, 255, 255);

                ImGui::ColorButton("Room", col);
                ImGui::SameLine();
            }
            ImGui::NewLine();
        }
    }

    ImGui::End();
}
