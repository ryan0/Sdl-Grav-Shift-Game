//
// Created by ryan on 6/30/23.
//

#include "GLRectRenderSystem.h"

float GLRectRenderSystem::rectVertices[] = {
        0.5f, 0.5f, 0.0f,  // top right
        0.5f, -0.5f, 0.0f,  // bottom right
        0.2f, -0.5f, 0.0f,  // bottom left
        0.2f, 0.5f, 0.0f   // top left
};
int GLRectRenderSystem::rectIndices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
};

GLRectRenderSystem::GLRectRenderSystem()
 : shaderProgram("../shaders/rectRenderSystemVert.glsl", "../shaders/rectRenderSystemFrag.glsl"),
 vertexArray(rectVertices, sizeof(rectVertices), rectIndices, sizeof(rectIndices))
{
    vertexArray.attribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float), nullptr);
}

void GLRectRenderSystem::render() {
    shaderProgram.use();
    vertexArray.bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}