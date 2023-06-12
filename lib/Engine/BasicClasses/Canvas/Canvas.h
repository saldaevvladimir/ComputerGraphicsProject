# pragma once

#define DEFAULT ".:;><+r*zsvfwqkP694VOGbUAKXH8RD#$B0MNWQ%&@"

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
        Game::Camera camera;
        std::string charmap;

        Canvas(int height, int width, Game game, Game::Camera camera, std::string charmap = DEFAULT);

        virtual void Draw();

        float GetIntersectionDistance(Entity entity, Ray ray);

        void Update();

    };
}