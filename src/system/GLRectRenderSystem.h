//
// Created by ryan on 6/30/23.
//

#ifndef SDL_GRAV_SHIFT_GAME_GL_RECT_RENDER_SYSTEM_H
#define SDL_GRAV_SHIFT_GAME_GL_RECT_RENDER_SYSTEM_H

#include "System.h"
#include "../rendering/ShaderProgram.h"
#include "../rendering/VertexArray.h"

class GLRectRenderSystem : public System {
public:
    GLRectRenderSystem();
    void render();

private:
    static float rectVertices[];
    static int rectIndices[];
    ShaderProgram shaderProgram;
    VertexArray vertexArray;
};


#endif //SDL_GRAV_SHIFT_GAME_GL_RECT_RENDER_SYSTEM_H
