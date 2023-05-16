//
// Created by ryan on 5/15/2023.
//

#include "System.h"

void System::registerEntity(std::weak_ptr<Entity> entity) {
    entities.push_back(entity);
}