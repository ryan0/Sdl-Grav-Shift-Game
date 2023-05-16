//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_ENTITY_H
#define SDL_GRAV_SHIFT_GAME_ENTITY_H


#include <array>
#include <memory>
#include <iostream>
#include "component/Component.h"

class Entity {
public:
    template<class T>
    void addComponent(std::unique_ptr<Component> component);

    template<class T>
    T* getComponent();

private:
    std::array<std::unique_ptr<Component>, Component::MAX_TYPES> components{nullptr};
};

template<class T>
void Entity::addComponent(std::unique_ptr<Component> component) {
    components[Component::typeId<T>()] = std::move(component);
}

template<class T>
T* Entity::getComponent() {
    T* t = static_cast<T*>(components[Component::typeId<T>()].get());
    return  t;
}

#endif //SDL_GRAV_SHIFT_GAME_ENTITY_H
