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

    Vector normal({0, 0, 1});
    Point planePos({0, 0, 3});

    Engine::HyperPlane plane(obj, planePos, normal);

    Point rayPos({0, 0, 0});
    Vector rayDir({0, 0, 1});

    Engine::Ray ray(cs, rayPos, rayDir);

    float dist1 = plane.IntersectionDistance(ray); // it should be equal to 3.0

    cout << dist1 << endl;

    Engine::EntitiesList lst;

    lst.Append<Engine::HyperPlane>(plane);

    for (auto& entity : lst.entities)
    {
        std::cout << "Distance: " << entity.IntersectionDistance(ray) << std::endl;
    }

    return 0;
}