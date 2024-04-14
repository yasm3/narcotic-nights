#include "DoorObject.h"
#include "Player.h"

DoorObject::DoorObject(Texture* texture, Direction direction, Vector2D<int> destination, Graphics& graphics, Dungeon& dungeon) :
    GameObject(texture, Vector2D<int>(0,0), graphics),
    m_direction(direction),
    m_active(false),
    m_destination(destination),
    m_dungeon(dungeon)
{
    showHitbox(true);
    setPosition(getDoorPosition(direction));
}

void DoorObject::update(float deltaTime, Input& input)
{
}

void DoorObject::handleCollision(Player& player)
{
    std::cout << "porte: collision avec un joueur" << std::endl;
    std::cout << m_destination << std::endl;
    m_dungeon.move(m_destination);
}

void DoorObject::setActive(bool active)
{
    m_active = active;
}

Vector2D<int> DoorObject::getDestination() const
{
    return m_destination;
}

Vector2D<int> DoorObject::getDoorPosition(Direction direction) const
{
    int windowWidth = m_graphics.getWindow()->getWidth();
    int windowHeight = m_graphics.getWindow()->getHeight();
    switch (direction) {
    case Direction::LEFT:
        return Vector2D<int>(0, windowHeight / 2);
    case Direction::UP:
        return Vector2D<int>(windowWidth / 2, 0);
    case Direction::RIGHT:
        return Vector2D<int>(windowWidth - 90, windowHeight / 2);
    case Direction::DOWN:
        return Vector2D<int>(windowWidth / 2, windowHeight - 90);
    default:
        return Vector2D<int>(0);
    }
}
