//
// Created by ryan on 5/13/2023.
//

#ifndef SDL_GRAV_SHIFT_GAME_SCENE_MANAGER_H
#define SDL_GRAV_SHIFT_GAME_SCENE_MANAGER_H

#include <unordered_map>
#include <memory>
#include <string>
#include "Scene.h"

class SceneManager {
public:
    void addScene(std::string key, std::unique_ptr<Scene> scene);
    void removeScene(std::string key);

    void setActiveScene(std::string key);
    void getActiveSceneRef();

private:
    std::unordered_map<std::string, std::unique_ptr<Scene>> sceneMap;
};


#endif //SDL_GRAV_SHIFT_GAME_SCENE_MANAGER_H
