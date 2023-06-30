cmake_minimum_required(VERSION 3.25)
project(SDL_Grav_Shift_Game)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/third-party/include)

add_executable(SDL_Grav_Shift_Game src/main.cpp src/Window.cpp src/Window.h src/SceneManager.cpp src/SceneManager.h src/Scene.cpp src/Scene.h src/Entity.cpp src/Entity.h src/math/Vec2f.cpp src/math/Vec2f.h src/component/PositionComponent.h src/component/VelocityComponent.h src/component/RectGeometryGraphicComponent.h src/component/Component.h src/component/Component.cpp src/system/GeometricRenderSystem.cpp src/system/GeometricRenderSystem.h src/system/System.cpp src/system/System.h src/system/VelocitySystem.cpp src/system/VelocitySystem.h third-party/include/stb/stb_image.h third-party/src/gl.c)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(
        SDL_Grav_Shift_Game
        PUBLIC
        SDL2::SDL2main
        SDL2::SDL2
        SDL2_image::SDL2_image-static
        SDL2_mixer::SDL2_mixer-static
        nlohmann_json::nlohmann_json
)
