#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Scene.h"
#include "Entity.h"

#include "component/PositionComponent.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(IMG_INIT_PNG );
    SDL_Init(SDL_INIT_AUDIO);

    std::cout << "Hello, World!" << std::endl;

    Window window = Window("Grav Shift", 1920, 1080, SDL_WINDOW_SHOWN );
    window.open();
    window.createRenderer(640, 360, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


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
        scene.render(window.getRendererRef());
    }

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 0;
}
