//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_SYSTEM_H
#define SDL_GRAV_SHIFT_GAME_SYSTEM_H

#include <vector>
#include <memory>
#include "../Entity.h"

class System {
public:
    void registerEntity(std::weak_ptr<Entity> entity);

protected:
    std::vector<std::weak_ptr<Entity>> entities;
};

#endif //SDL_GRAV_SHIFT_GAME_SYSTEM_H
