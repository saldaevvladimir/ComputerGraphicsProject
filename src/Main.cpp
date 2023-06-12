#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"


int main()
{
    using namespace std;

    int dim = 3;
    Vector* b = new Vector[dim];
    b[0] = Vector({1, 0, 0}); b[1] = Vector({0, 0, 1}); b[2] = Vector({0, 0, 1});

    Engine::Game game(CoordinateSystem(Point({0, 0, 0}), VectorSpace(b, dim)), Engine::EntitiesList(), Engine::EventSystem());

    CoordinateSystem cs(Point({0, 0, 0}), VectorSpace(b, dim));

    Engine::Game::GameEntity g(game);

    Engine::Game::Object obj(g, Point({6, 0, 0}), Vector({1, 0, 0}));

    Engine::HyperEllipsoid ellipsoid(obj, Point({6, 0, 0}), Vector({1, 0, 0}), Vector({1, 1, 1}));

    Engine::HyperPlane plane(obj, Point({0, 6, 0}), Vector({0, 1, 0}));

    game.gameEntities.Append(ellipsoid);


    float hfov = 1.75f;
    float drawDist = 10.0f;
    Point camPos({0, 0, 0});
    Vector camDir({1, 0, 0});

    Engine::Game::Camera camera(obj, hfov, drawDist);
    camera.SetPosition(Point({0, 0, 0}));
    camera.SetDirection(Vector({1, 0, 0}));

    int h = 30, w = 100;
    Engine::Console console(h, w, game, camera); // charmap = default
    console.Canvas::Update();

    console.Draw();

    cout << endl << endl << endl;
    cout << "**********************************************" << endl;
    cout << "***** end ***** end ****** end ***** end *****" << endl;
    cout << "**********************************************" << endl;

    return 0;
}


