//
// Created by ryan on 6/30/23.
//

#ifndef SDL_GRAV_SHIFT_GAME_SHADER_PROGRAM_H
#define SDL_GRAV_SHIFT_GAME_SHADER_PROGRAM_H

#include <string>
#include "glad/gl.h"

class ShaderProgram {
public:
    ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);

    void use() const;
    void setUniform(const std::string& name, bool value) const;

private:
    unsigned int id;

    static std::string loadFileIntoString(const std::string& fileName);
    static unsigned int loadAndCompileShaderFile(const std::string& filename, GLuint glShaderType);
    static unsigned int linkProgramFromShaders(unsigned int vertexShaderID, unsigned int fragmentShaderId);

};

#endif //SDL_GRAV_SHIFT_GAME_SHADER_PROGRAM_H
