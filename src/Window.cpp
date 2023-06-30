//
// Created by ryan on 5/13/2023.
//

#include <iostream>
#include <utility>
#include "Window.h"

Window::Window(std::string  title, int width, int height, Uint32 flags)
    : title(std::move(title)), width(width), height(height), flags(flags)
{

}

void Window::open() {
    if(windowPtr != nullptr) {
        std::cout<<"Failed to open Window, associated SDL_Window already instantiated"<<std::endl;
    } else {
        windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, width, height, flags);
        if (windowPtr == nullptr) {
            std::cout<<"Failed to open window! SDL Error: "<<SDL_GetError();
        }
    }
}

void Window::createRenderer(int logicalWidth, int logicalHeight, Uint32 renderFlags) {
    if(windowPtr == nullptr) {
        std::cout<<"Failed to create renderer, associated SDL_Window is null!"<<std::endl;
    } else if (rendererPtr != nullptr) {
        std::cout<<"Failed to create renderer, associated SDL_Renderer already instantiated"<<std::endl;
    } else if (glContext != nullptr) {
        std::cout<<"Failed to create renderer, associated Context already instantiated"<<std::endl;
    } else {
        rendererPtr = SDL_CreateRenderer(windowPtr, -1, renderFlags);
        SDL_RenderSetLogicalSize(rendererPtr, logicalWidth, logicalHeight);
    }
}

void Window::createGLContext() {
    if(windowPtr == nullptr) {
        std::cout<<"Failed to create context, associated SDL_Window is null!"<<std::endl;
    } else if (rendererPtr != nullptr) {
        std::cout<<"Failed to create context, associated SDL_Renderer already instantiated"<<std::endl;
    } else if (glContext != nullptr) {
        std::cout<<"Failed to create context, associated Context already instantiated"<<std::endl;
    } else {
        glContext = SDL_GL_CreateContext(windowPtr);
    }
}

void Window::glSwapWindow() {
    SDL_GL_SwapWindow(windowPtr);
}

void Window::close() {
    if (rendererPtr != nullptr) {
        SDL_DestroyRenderer(rendererPtr);
        rendererPtr = nullptr;
    }
    if (glContext != nullptr) {
        SDL_GL_DeleteContext(glContext);
        glContext = nullptr;
    }
    if (windowPtr != nullptr) {
        SDL_DestroyWindow(windowPtr);
        windowPtr = nullptr;
    }
}

SDL_Renderer* Window::getRendererRef() {
    return rendererPtr;
}

SDL_GLContext Window::getGLContext() {
    return glContext;
}

int Window::getWidth() const {
    return width;
}

int Window::getHeight() const {
    return height;
}

Window::~Window() {
    Window::close();
}
