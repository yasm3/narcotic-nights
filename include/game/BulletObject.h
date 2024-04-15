#ifndef _BULLETOBJECT_H
#define _BULLETOBJECT_H

#include "GameObject.h"

/**
 * @class BulletObject
 * 
 * @brief Objet balle du jeu tiré par le joueur
 */
class BulletObject : public GameObject {
	public:
		BulletObject(Texture* texture, Vector2D<int> position, Graphics& graphics);
		void update(float deltaTime, Input& input);
		void handleCollision(GameObject& other);
	private:
		Vector2D<int> m_mousePos;
		bool m_alive = true;
};

#endif
