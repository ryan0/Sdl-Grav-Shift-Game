//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_COMPONENT_H
#define SDL_GRAV_SHIFT_GAME_COMPONENT_H

#include <type_traits>

class Component {
public:
    static const int MAX_TYPES = 16;

    template<class type>
    static int typeId();

private:
    static int nextTypeId;
};

template<class type>
int Component::typeId() {
    static_assert(std::is_base_of<Component, type>(), "Type passed to Component::typeId() must be derived from Component");
    static const int id = nextTypeId++;
    return id;
}

#endif //SDL_GRAV_SHIFT_GAME_COMPONENT_H
