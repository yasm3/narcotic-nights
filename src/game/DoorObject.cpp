#include "DoorObject.h"
#include "Player.h"

DoorObject::DoorObject(Texture* texture, Direction direction, Vector2D<int> destination, Graphics& graphics, Dungeon& dungeon) :
    GameObject(texture, Vector2D<int>(0,0), graphics),
    m_direction(direction),
    m_active(false),
    m_destination(destination),
    m_dungeon(dungeon)
{
    setPosition(getDoorPosition(direction));
}

void DoorObject::update(float deltaTime, Input& input)
{
}

void DoorObject::handleCollision(GameObject& other)
{
    if (Player* player = dynamic_cast<Player*>(&other)) {
        player->setPosition(getNextPlayerPosition(Dungeon::oppositeDirection(m_direction)));
        m_dungeon.move(m_destination);
    }
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
        return Vector2D<int>(10, windowHeight / 2);
    case Direction::UP:
        return Vector2D<int>(windowWidth / 2, 10);
    case Direction::RIGHT:
        return Vector2D<int>(windowWidth - 90, windowHeight / 2);
    case Direction::DOWN:
        return Vector2D<int>(windowWidth / 2, windowHeight - 90);
    default:
        return Vector2D<int>(0);
    }
}

Vector2D<int> DoorObject::getNextPlayerPosition(Direction direction) const
{
    int windowWidth = m_graphics.getWindow()->getWidth();
    int windowHeight = m_graphics.getWindow()->getHeight();
    switch (direction) {
    case Direction::LEFT:
        return Vector2D<int>(250, windowHeight / 2);
    case Direction::UP:
        return Vector2D<int>(windowWidth / 2, 250);
    case Direction::RIGHT:
        return Vector2D<int>(windowWidth - 250, windowHeight / 2);
    case Direction::DOWN:
        return Vector2D<int>(windowWidth / 2, windowHeight - 250);
    }
    return Vector2D<int>(0);
}
