#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"

#include "../lib/Engine/BasicClasses/Game/Console/Console.h"

using namespace std;
using namespace Engine;

void scene_1()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    HyperEllipsoid ellipsoid(game, Point({0,0,28}), Vector({0,1,0}), Vector({15,15,15}));
    HyperPlane plane(game, Point({0,0,25}), Vector({0,0,1}));

    game.gameEntities.Append(ellipsoid);

    Game::Camera camera(game, M_PI * 2.0f / 3, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 100, game, camera);

    console.Update();
    console.Draw();
}

void scene_2()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    // 
    HyperEllipsoid ellipsoid(game, Point({0,0,50}), Vector({0,1,0}), Vector({20,20,20}));
    HyperPlane plane(game, Point({0,0,23}), Vector({0,0,1}));

    game.gameEntities.Append(plane);

    Game::Camera camera(game, M_PI / 2, 35.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 300, game, camera, ".:;><+*sfwP694VOGbUAKXH8RD#$B0MNWQ%&@");
    //

    console.Update();
    console.Draw();
}

void scene_3()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    // 
    HyperEllipsoid ellipsoid(game, Point({23,5,0}), Vector({0,1,0}), Vector({10,10,10}));
    HyperPlane plane(game, Point({0,0,20}), Vector({0,0,1}));

    game.Append(plane);
    //game.Append(ellipsoid);

    Game::Camera camera(game, M_PI / 2, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 300, game, camera, ".:;><+*sfwP694VOGbUAKXH8RD#$B0MNWQ%&@");
    //

    console.Update();
    console.Draw();
}

void scene_4()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    HyperEllipsoid ellipsoid(game, Point({0,0,28}), Vector({0,1,0}), Vector({15,15,15}));
    HyperPlane plane(game, Point({0,6,10}), Vector({0,6,10}));

    game.gameEntities.Append(plane);

    Game::Camera camera(game, M_PI * 2.0f / 3, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 100, game, camera);

    console.Update();
    console.Draw();
}

void scene_5()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    HyperEllipsoid ellipsoid(game, Point({0,0,12}), Vector({0,1,0}), Vector({4,3,2}));
    HyperPlane plane(game, Point({0,12,6}), Vector({0,12,6}));

    game.Append(plane);
    game.Append(ellipsoid);

    Game::Camera camera(game, M_PI * 2.0f / 3, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 100, game, camera);

    console.Update();
    console.Draw();
}

void scene_6()
{
    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);

    HyperEllipsoid ellipsoid(game, Point({0,0,12}), Vector({0,1,0}), Vector({4,3,2}));
    HyperPlane plane(game, Point({0,3,0}), Vector({0,1,0}));

    game.Append(plane);
    game.Append(ellipsoid);

    Game::Camera camera(game, M_PI * 2.0f / 3, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0,0,1}));

    Console console(100, 100, game, camera);

    console.Update();
    console.Draw();
}

int main()
{
    scene_6();

    return 0;
}
