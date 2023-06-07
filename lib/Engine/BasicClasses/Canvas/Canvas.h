# pragma once

#include "../../../../lib/Math/Matrix/Matrix.h"
#include "../Game/Game.h"


namespace Engine
{
    class Canvas
        {
        public:
            int height;
            int width;
            Matrix distances;
            Game game;

            Canvas(int height, int width, Game game);

            void Draw();

            void Update(Game::Camera camera);

        };
}