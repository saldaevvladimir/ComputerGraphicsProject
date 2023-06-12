#pragma once

#include "../../../../Math/Matrix/Matrix.h"
#include "../Game.h"
#include "../../Canvas/Canvas.h"

#include <string>



class Console : public Canvas
{
public:
    Console(int height, int width, Engine::Game game, Engine::Game::Camera camera, std::string charmap = DEFAULT);

    void Draw() override;

    void Clear();

    void SetCursorPosition(int x, int y);

};