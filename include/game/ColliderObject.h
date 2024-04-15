#ifndef _COLLIDEROBJECT_H
#define _COLLIDEROBJECT_H

#include "GameObject.h"
#include "AssetManager.h"

/**
 * @class ColliderObject
 * 
 * @brief Objet de jeu invisible pour delimiter la map
 */
class ColliderObject : public GameObject {
	public:
		ColliderObject(Vector2D<int> position, Vector2D<int> size, Graphics& graphics);
		void update(float deltaTime, Input& input);
		void handleCollision(GameObject& other);
};

#endif
