#include "GameObject.h"

GameObject::GameObject(Texture* texture, Vector2D<int> position, Graphics& graphics) : m_texture(texture), m_position(position), m_size(0), m_visible(true), m_showHitbox(false), m_graphics(graphics)
{
    if (texture != nullptr) {
        m_size.x = texture->getWidth();
        m_size.y = texture->getHeight();
    }
}

void GameObject::draw()
{
    if (m_visible) {
        if (m_texture != nullptr) {
            m_graphics.draw(*m_texture, m_position.x, m_position.y, m_graphics.getScale());
        }
        if (m_showHitbox) {
            drawHitbox();
        }
    }
}

bool GameObject::collidesWith(GameObject& other)
{
    // default collision is AABB
    if (AABBCollision(other)) {
        return true;
    }
}

void GameObject::setTexture(Texture* texture)
{
    m_texture = texture;
    m_size.x = texture->getWidth();
    m_size.y = texture->getHeight();
}

Vector2D<int> GameObject::getPosition() const
{
    return m_position;
}

void GameObject::setPosition(Vector2D<int> newPosition)
{
    m_position = newPosition;
}

void GameObject::show()
{
    m_visible = true;
}

void GameObject::hide()
{
    m_visible = false;
}

bool GameObject::getShowHitbox() const
{
    return m_showHitbox;
}

void GameObject::showHitbox(bool show)
{
    m_showHitbox = show;
}

void GameObject::drawHitbox()
{
    m_graphics.drawRectangle(m_position, m_size, 255, 255, 255);
}

bool GameObject::AABBCollision(GameObject& other)
{
    Vector2D<int> pos1 = m_position;
    Vector2D<int> pos2 = other.m_position;
    Vector2D<int> size1 = m_size * m_graphics.getScale();
    Vector2D<int> size2 = other.m_size * m_graphics.getScale();

    int left1 = pos1.x;
    int right1 = pos1.x + size1.x;
    int top1 = pos1.y;
    int bottom1 = pos1.y + size1.y;

    int left2 = pos2.x;
    int right2 = pos2.x + size2.x;
    int top2 = pos2.y;
    int bottom2 = pos2.y + size2.y;

    if (left1 < right2 && right1 > left2 && top1 < bottom2 && bottom1 > top2)
        return true;
    return false;
}
