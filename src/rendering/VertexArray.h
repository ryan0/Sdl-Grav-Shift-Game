//
// Created by ryan on 6/30/23.
//

#ifndef SDL_GRAV_SHIFT_GAME_VERTEX_ARRAY_H
#define SDL_GRAV_SHIFT_GAME_VERTEX_ARRAY_H

#include "glad/gl.h"

class VertexArray {
public:
    VertexArray(float arrayData[], int arrayDataSize, int elementData[], int elementDataSize);

    void attribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* offset) const;

    void bind() const;
    [[nodiscard]] unsigned int getArrayBufferId() const;
    [[nodiscard]] unsigned int getElementBufferId() const;

private:
    unsigned int vertexArrayId = 0;
    unsigned int arrayBufferId = 0;
    unsigned int elementBufferId = 0;
};

#endif //SDL_GRAV_SHIFT_GAME_VERTEX_ARRAY_H
