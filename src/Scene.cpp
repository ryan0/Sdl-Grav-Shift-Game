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

    velocitySystem.registerEntity(e);
    addEntity(e);
}

void Scene::update() {
    velocitySystem.updateVelocity();
}

void Scene::render(SDL_Renderer *renderer) {
    glClearColor(0.0f, 0.35f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glRectRenderSystem.render();
}

void Scene::handleEvent(const SDL_Event &event) {
    for(auto& entity : entities) {
        // handle event for i
    }
}

void Scene::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}