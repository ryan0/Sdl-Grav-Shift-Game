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
    } else {
        rendererPtr = SDL_CreateRenderer(windowPtr, -1, flags);
        SDL_RenderSetLogicalSize(rendererPtr, logicalWidth, logicalHeight);
    }
}

void Window::close() {
    if(rendererPtr != nullptr) {
        SDL_DestroyRenderer(rendererPtr);
        rendererPtr = nullptr;
    }
    if(windowPtr != nullptr) {
        SDL_DestroyWindow(windowPtr);
        windowPtr = nullptr;
    }
}

SDL_Renderer* Window::getRendererRef() {
    return rendererPtr;
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
