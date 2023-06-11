#define _USE_MATH_DEFINES
#include <cmath>

#include "../../lib/Math/AllMath/AllMath.h"
#include "../../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"
#include "../../googletest/googletest/include/gtest/gtest.h"
//#include <gtest/gtest.h>


TEST(ObjectTests, MoveTest)
{   
    int dim = 3;

    Vector* basis = new Vector[dim];
    basis[0] = Vector({ 1, 0, 0 });
    basis[1] = Vector({ 0, 1, 0 });
    basis[2] = Vector({ 0, 0, 1 });

    VectorSpace vs(basis, dim);

    Point initPoint({ 0, 0, 0 });

    CoordinateSystem cs(initPoint, vs);

    Engine::EntitiesList lst;

    Engine::Game game(cs, lst);

    Engine::Game::GameEntity gameEntity(game);

    Point pos({ 0, 0, 0 });
    Vector dir({ 1, 0, 0 });

    Engine::Game::Object obj(gameEntity, pos, dir);

    obj.Move(4.0f);

    Point testNewPos = std::get<Point>(obj.GetProperty("position"));

    Point newPos({ 4, 0, 0 });

    bool correctPos = (testNewPos == newPos);

    ASSERT_TRUE(correctPos);
}

TEST(ObjectTests, PlanarRotate)
{   
    int dim = 3;

    Vector* basis = new Vector[dim];
    basis[0] = Vector({ 1, 0, 0 });
    basis[1] = Vector({ 0, 1, 0 });
    basis[2] = Vector({ 0, 0, 1 });

    VectorSpace vs(basis, dim);

    Point initPoint({ 0, 0, 0 });

    CoordinateSystem cs(initPoint, vs);

    Engine::EntitiesList lst;

    Engine::Game game(cs, lst);

    Engine::Game::GameEntity gameEntity(game);

    Point pos({ 0, 0, 0 });
    Vector dir({ 1, 0, 0 });

    Engine::Game::Object obj(gameEntity, pos, dir);

    obj.PlanarRotate(0, 1, M_PI / 2.0);

    Vector newDir({ 0, -1, 0 });

    Vector testDir = std::get<Vector>(obj.GetProperty("direction"));

    bool correctDir = (testDir == newDir);

    ASSERT_TRUE(correctDir);
}

TEST(ObjectTests, Rotate3D)
{   
    int dim = 3;

    Vector* basis = new Vector[dim];
    basis[0] = Vector({ 1, 0, 0 });
    basis[1] = Vector({ 0, 1, 0 });
    basis[2] = Vector({ 0, 0, 1 });

    VectorSpace vs(basis, dim);

    Point initPoint({ 0, 0, 0 });

    CoordinateSystem cs(initPoint, vs);

    Engine::EntitiesList lst;

    Engine::Game game(cs, lst);

    Engine::Game::GameEntity gameEntity(game);

    Point pos({ 0, 0, 0 });
    Vector dir({ 1, 0, 0 });

    Engine::Game::Object obj(gameEntity, pos, dir);

    obj.Rotate3D(M_PI, M_PI, M_PI);

    Vector newDir({ 1, 0, 0 });

    Vector testDir = std::get<Vector>(obj.GetProperty("direction"));

    bool correctDir = (testDir == newDir);

    ASSERT_TRUE(correctDir);
}

TEST(HyperPlaneTests, IntersectionDistanceTest)
{
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

    float distance = 3.0f;
    float testDistance = plane.HyperPlane::IntersectionDistance(ray); 

    bool correctIntersectionDistance = (testDistance == distance);

    ASSERT_TRUE(correctIntersectionDistance);
}

TEST(HyperEllipsoidTests, IntersectionDistanceTest)
{
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
    Vector elDir({0, 0, 1});
    Vector semiAxes({1, 1, 1});

    Engine::HyperEllipsoid ellipsoid(obj, elPos, elDir, semiAxes);

    Point rayPos({0, 0, 0});
    Vector rayDir({0, 0, 1});

    Engine::Ray ray(cs, rayPos, rayDir);

    float distance = 3.0f;
    float testDistance = ellipsoid.HyperEllipsoid::IntersectionDistance(ray);

    bool correctIntersectionDistance = (true);

    ASSERT_TRUE(correctIntersectionDistance);
}

