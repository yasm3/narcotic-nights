#include "GameObject.h"

GameObject::GameObject(Texture& texture, int posX, int posY) : m_texture(texture), m_x(posX), m_y(posY), m_visible(true)
{}

void GameObject::update(float deltaTime)
{

}

void GameObject::draw(Graphics& graphics)
{
    graphics.draw(m_texture, m_x, m_y);
}

int GameObject::getPosX() const
{
    return m_x;
}

int GameObject::getPosY() const
{
    return m_y;
}
