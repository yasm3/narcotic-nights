#ifndef _ENTITY_H_
#define _ENTITY_H_

#include <iostream>
#include "Texture.h"
#include "Graphics.h"
#include "Input.h"

class Entity {
public:
    Entity();
    virtual ~Entity();
    virtual void update(Uint32 deltaTime, Input& input);
    void draw(Graphics& graphics); 
    virtual bool checkCollision(const Entity& otherEntity) const;

    // Mutateurs
    void setPosition(float x, float y) { m_x = x; m_y = y; }
    void setSize(int width, int height) { m_w = width; m_h = height; }
    void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }
    void setAcceleration(float acceleration) { m_acceleration = acceleration; }
    void setFriction(float friction) { m_friction = friction; }
    void setTexture(Texture* t){ 
        if (t != nullptr) 
            m_texture=t;
    }

    // Accesseurs pour les membres privés
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    float getWidth() const { return m_w; }
    float getHeight() const { return m_h; }
    float getMaxSpeed() const { return m_maxSpeed; }
    float getAcceleration() const { return m_acceleration; }
    float getFriction() const { return m_friction; }

protected:
    float m_x, m_y;
    int m_w, m_h;
    float m_maxSpeed;
    float m_acceleration;
    float m_friction;
    Texture* m_texture=nullptr;
};

#endif

 