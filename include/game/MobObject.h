#ifndef _MOBOBJECT_H
#define _MOBOBJECT_H

#include "GameObject.h"
#include <random>

class MobObject : public GameObject {
	public:
		MobObject(Texture* texture, Vector2D<int> position, Graphics& graphics);
		void update(float deltaTime, Input& input);
		void handleCollision(GameObject& other);
	private:
};

#endif
