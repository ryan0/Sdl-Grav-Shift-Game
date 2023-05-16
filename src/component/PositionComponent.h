//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_POSITION_COMPONENT_H
#define SDL_GRAV_SHIFT_GAME_POSITION_COMPONENT_H

#include "Component.h"
#include "../math/Vec2f.h"

class PositionComponent : public Component, public Vec2f {
public:
    PositionComponent() = default;
    explicit PositionComponent(float value) : Vec2f(value) {}
    PositionComponent(float x, float y) : Vec2f(x, y) {}
};


#endif //SDL_GRAV_SHIFT_GAME_POSITION_COMPONENT_H
