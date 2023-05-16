//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_VELOCITY_SYSTEM_H
#define SDL_GRAV_SHIFT_GAME_VELOCITY_SYSTEM_H

#include <vector>
#include <memory>
#include "System.h"
#include "../Entity.h"

class VelocitySystem : public System {
public:
    void updateVelocity();
};


#endif //SDL_GRAV_SHIFT_GAME_VELOCITY_SYSTEM_H
