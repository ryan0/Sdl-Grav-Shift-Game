//
// Created by ryan on 5/15/2023.
//

#include "Vec2f.h"

Vec2f::Vec2f() = default;

Vec2f::Vec2f(float value) : x(value), y(value) {}

Vec2f::Vec2f(float x, float y) : x(x), y(y) {}

Vec2f operator+(const Vec2f& left, const Vec2f& right) {
    return {left.x + right.x, left.y + right.y};
}

Vec2f operator-(const Vec2f& left, const Vec2f& right) {
    return {left.x - right.x, left.y - right.y};
}