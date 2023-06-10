#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"


int main()
{
    using namespace std;

    int dim = 3;

    Point init({0, 0, 0});

    Vector* b = new Vector[dim];
    b[0] = Vector({1, 0, 0});
    b[1] = Vector({0, 1, 0});
    b[2] = Vector({0, 0, 1});

    VectorSpace vs(b, dim);

    CoordinateSystem cs(init, vs);

    Engine::Game game(cs, Engine::EntitiesList());

    Engine::Game::GameEntity gameEntity(game);

    Vector objDir({1, 0, 0});
    Point objPos({0, 0, 0});

    Engine::Game::Object obj(gameEntity, objPos, objDir);

    Point elPos({0, 0, 4});
    Vector elDir({0, 0, 0});
    Vector semiAxes({1, 1, 1});

    Engine::HyperEllipsoid ellipsoid(obj, elPos, elDir, semiAxes);

    Point rayPos({0, 0, 0});
    Vector rayDir({0, 0, 1});

    Engine::Ray ray(cs, rayPos, rayDir);

    float dist2 = ellipsoid.HyperEllipsoid::IntersectionDistance(ray); // it should be equal to 2.0

    Vector par;
    par = ellipsoid.FindParams(ray);
    cout << par << endl;
    cout << dist2 << endl;


    return 0;
}


