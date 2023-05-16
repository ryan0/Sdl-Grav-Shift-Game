//
// Created by ryan on 5/15/2023.
//

#include "VelocitySystem.h"
#include "../component/VelocityComponent.h"
#include "../component/PositionComponent.h"

void VelocitySystem::updateVelocity() {
    for(auto& e : entities) {
        auto ptr = e.lock();
        if(ptr) {
            auto *velocity = ptr->getComponent<VelocityComponent>();
            auto *position = ptr->getComponent<PositionComponent>();

            position->x += velocity->x;
            position->y += velocity->y;
        }
    }
}