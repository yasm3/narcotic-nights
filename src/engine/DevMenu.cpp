#include "DevMenu.h"
#include "Game.h"

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
    ImGui::Begin("Development Menu");

    ImGui::Text("This is some useful text."); 
    ImGui::Text("Largeur: %d", m_game.m_window.getWidth());

    ImGui::End();
}