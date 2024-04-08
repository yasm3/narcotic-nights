#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Entity.h"

class Player : public Entity{
    public:
        Player(Texture* texture, float x, float y, int w, int h);
        ~Player();

        void update(Uint32 deltaTime, Input& input) override;


    private:
        float m_dx, m_dy;
        int score;
        bool isAlive;
};

#endif
