#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"


int main()
{
    using namespace std;
    using namespace Engine;

    Vector* b = new Vector[3];
    b[0] = Vector({1,0,0}); b[1] = Vector({0,1,0}); b[2] = Vector({0,0,1});

    VectorSpace vs(b, 3);

    Point init({0,0,0});

    CoordinateSystem cs(init, vs);

    EntitiesList el;

    Game game(cs, el);

    Game::GameEntity gameE(game);
    Game::Object obj(gameE);

    HyperEllipsoid ellipsoid(game, Point({0,0,25}), Vector({0,1,0}), Vector({10,10,10}));
    HyperPlane plane(game, Point({0,0,25}), Vector({0,0,1}));

    game.gameEntities.Append(ellipsoid);

    Game::Camera camera(obj, M_PI / 2, 40.0f);
    camera.SetPosition(Point({0,0,0}));
    camera.SetDirection(Vector({0, 0, 1}));

    Console console(100, 100, game, camera);

    console.Update();
    console.Draw();


    return 0;
}

