#include "Input.h"

Input::Input() : m_keystate(nullptr) {}
Input::~Input() {}

void Input::update()
{
    m_keystate = SDL_GetKeyboardState(nullptr);
}

bool Input::isKeyDown(SDL_Scancode key) const
{
    if (m_keystate != nullptr)
        if (m_keystate[key]) return true;
    return false;
}
