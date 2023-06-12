#pragma once

#include "../../../../Math/Matrix/Matrix.h"
#include "../Game.h"
#include "../../Canvas/Canvas.h"

#include <string>


namespace Engine
{
    class Console : public Canvas
    {
    public:
        Console(int height, int width, Game game, Game::Camera camera, std::string charmap = DEFAULT);

        void Draw() override;

        void Clear();

        void SetCursorPosition(int x, int y);

    };
}