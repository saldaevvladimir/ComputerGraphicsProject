# pragma once

#define DEFAULT ".:;><+r*zsvfwqkP694VOGbUAKXH8RD#$B0MNWQ%&@"

#include "../../../../lib/Math/Matrix/Matrix.h"
#include "../Game/Game.h"
#include "../Game/HyperEllipsoid/HyperEllipsoid.h"
#include "../Game/HyperPlane/HyperPlane.h"



class Canvas
{
public:
    int height;
    int width;
    Matrix distances;
    Engine::Game game;
    Engine::Game::Camera camera;
    std::string charmap;

    Canvas(int height, int width, Engine::Game game, Engine::Game::Camera camera, std::string charmap = DEFAULT);

    virtual void Draw();

    float GetIntersectionDistance(Engine::Entity entity, Engine::Ray ray);

    void Update();

};

