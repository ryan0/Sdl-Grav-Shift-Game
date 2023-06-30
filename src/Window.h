//
// Created by ryan on 5/13/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_WINDOW_H
#define SDL_GRAV_SHIFT_GAME_WINDOW_H

#include <SDL.h>
#include <string>

/**
 * Wrapper class for SDL_Window and SDL_Renderer
 */
class Window {
public:
    Window(std::string  title, int width, int height, Uint32 flags);

    void open();
    void close();

    void createRenderer(int logicalWidth, int logicalHeight, Uint32 flags);
    SDL_Renderer* getRendererRef();

    void createGLContext();
    SDL_GLContext getGLContext();

    void glSwapWindow();

    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    ~Window();

private:
    SDL_Window* windowPtr = nullptr;
    SDL_Renderer* rendererPtr = nullptr;
    SDL_GLContext glContext = nullptr;
    std::string title;

    Uint32 flags = SDL_WINDOW_SHOWN;
    int width = 0;
    int height = 0;
};


#endif //SDL_GRAV_SHIFT_GAME_WINDOW_H
