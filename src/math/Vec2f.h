//
// Created by ryan on 5/15/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_VEC2F_H
#define SDL_GRAV_SHIFT_GAME_VEC2F_H


class Vec2f {
public:
    float x = 0;
    float y = 0;

    Vec2f();
    explicit Vec2f(float value);
    Vec2f(float x, float y);
};

Vec2f operator+(const Vec2f& left, const Vec2f& right);
Vec2f operator-(const Vec2f& left, const Vec2f& right);


#endif //SDL_GRAV_SHIFT_GAME_VEC2F_H
