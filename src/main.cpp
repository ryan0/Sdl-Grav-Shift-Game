#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <glad/gl.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Scene.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(IMG_INIT_PNG );
    SDL_Init(SDL_INIT_AUDIO);
    SDL_GL_LoadLibrary(nullptr);

    // Request an OpenGL 4.5 context (should be core)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

    Window glWindow = Window("Gl Window", 400, 500, SDL_WINDOW_OPENGL);
    glWindow.open();
    glWindow.createGLContext();

    //Load OpenGL function pointers using GLAD
    int version = gladLoadGL((GLADloadfunc) SDL_GL_GetProcAddress);
    std::cout<<"Glad loadGL version: "<<version<<std::endl;

    // Check OpenGL properties;
    std::cout<<"OpenGL loaded\n";
    std::cout<<"Vendor:    "<<glGetString(GL_VENDOR)<<std::endl;
    std::cout<<"Renderer:  "<<glGetString(GL_RENDERER)<<std::endl;
    std::cout<<"Version:   "<<glGetString(GL_VERSION)<<std::endl;

    Scene scene = Scene();

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event) != 0) { //process events
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        scene.update();
        scene.render(nullptr);
        glWindow.glSwapWindow();
    }

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
