//
// Created by ryan on 5/15/2023.
//

#include "GeometricRenderSystem.h"
#include "../component/PositionComponent.h"
#include "../component/RectGeometryGraphicComponent.h"

//GeometricRenderSystem::GeometricRenderSystem(SDL_Renderer *rendererRef) : rendererRef(rendererRef) {}

void GeometricRenderSystem::render(SDL_Renderer *rendererRef) {

    SDL_SetRenderDrawColor(rendererRef, 0x00, 0xFF, 0x00, 0xFF);

    for(auto& e: entities) {
        auto ptr = e.lock();
        if(ptr) {

            auto *p = ptr->getComponent<PositionComponent>();
            auto *g = ptr->getComponent<RectGeometryGraphicComponent>();

            float x = p->x + g->origin.x;
            float y = p->y + g->origin.y;

            SDL_FRect rect = {x, y, g->width, g->height};
            SDL_RenderDrawRectF(rendererRef, &rect);
        }
    }
}