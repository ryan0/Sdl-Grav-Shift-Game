//
// Created by ryan on 5/13/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_SCENE_H
#define SDL_GRAV_SHIFT_GAME_SCENE_H

#include <vector>
#include <SDL.h>
#include "Entity.h"

#include "system/GeometricRenderSystem.h"
#include "system/VelocitySystem.h"

class Scene {
public:
    Scene();

    virtual void update();
    virtual void render(SDL_Renderer* renderer);
    virtual void handleEvent(const SDL_Event& event);

    void addEntity(std::shared_ptr<Entity> entity);

    virtual ~Scene() = default;

private:
    std::vector<std::shared_ptr<Entity>> entities;
    GeometricRenderSystem geometricRenderSystem;
    VelocitySystem velocitySystem;
};


#endif //SDL_GRAV_SHIFT_GAME_SCENE_H
