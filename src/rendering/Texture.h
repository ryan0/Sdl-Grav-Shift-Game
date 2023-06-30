//
// Created by ryan on 6/30/23.
//

#ifndef SDL_GRAV_SHIFT_GAME_TEXTURE_H
#define SDL_GRAV_SHIFT_GAME_TEXTURE_H


#include "glad/gl.h"
#include <string>

class Texture {
public:
    explicit Texture(const std::string& imgPath, bool flippedVertically = false, GLenum dataFormat = GL_RGB);

    void bind(GLenum activeTexture) const;

private:
    unsigned int id = 0;
    int imgWidth = 0;
    int imgHeight = 0;
    int nrChannels = 0;

};

#endif //SDL_GRAV_SHIFT_GAME_TEXTURE_H
