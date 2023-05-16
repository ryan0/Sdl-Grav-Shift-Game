//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_GEOMETRIC_RENDER_SYSTEM_H
#define SDL_GRAV_SHIFT_GAME_GEOMETRIC_RENDER_SYSTEM_H


#include "System.h"
#include "../Entity.h"
#include "SDL_render.h"

class GeometricRenderSystem : public System {
public:
    void render(SDL_Renderer *rendererRef);

private:
};


#endif //SDL_GRAV_SHIFT_GAME_GEOMETRIC_RENDER_SYSTEM_H
