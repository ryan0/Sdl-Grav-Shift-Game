//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_RECT_GEOMETRY_GRAPHIC_COMPONENT_H
#define SDL_GRAV_SHIFT_GAME_RECT_GEOMETRY_GRAPHIC_COMPONENT_H

#include "Component.h"
#include "../math/Vec2f.h"

class RectGeometryGraphicComponent : public Component {
public:
    Vec2f origin;
    float width = 0;
    float height = 0;

    RectGeometryGraphicComponent() = default;

    RectGeometryGraphicComponent(const Vec2f& origin, float width, float height)
        : origin(origin), width(width), height(height) {}

    RectGeometryGraphicComponent(float x, float y, float width, float height)
            : origin(x, y), width(width), height(height) {}
};

#endif //SDL_GRAV_SHIFT_GAME_RECT_GEOMETRY_GRAPHIC_COMPONENT_H
