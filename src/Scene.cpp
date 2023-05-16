//
// Created by ryan on 5/13/2023.
//

#include <iostream>
#include "Scene.h"
#include "component/PositionComponent.h"
#include "component/VelocityComponent.h"
#include "component/RectGeometryGraphicComponent.h"

Scene::Scene() {
    auto e = std::make_shared<Entity>();

    auto positionComponent = std::make_unique<PositionComponent>(20, 50.0f);
    e->addComponent<PositionComponent>(std::move(positionComponent));

    auto velocityComponent = std::make_unique<VelocityComponent>(0.05f, 0.4f);
    e->addComponent<VelocityComponent>(std::move(velocityComponent));

    auto rectGeometry = std::make_unique<RectGeometryGraphicComponent>(0.0, 0.0f, 20.0f, 20.0f);
    e->addComponent<RectGeometryGraphicComponent>(std::move(rectGeometry));

    velocitySystem.registerEntity(e);
    geometricRenderSystem.registerEntity(e);
    addEntity(e);
}

void Scene::update() {
    velocitySystem.updateVelocity();
}

void Scene::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    geometricRenderSystem.render(renderer);

    SDL_RenderPresent(renderer);
}

void Scene::handleEvent(const SDL_Event &event) {
    for(auto& entity : entities) {
        // handle event for i
    }
}

void Scene::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}