#define _USE_MATH_DEFINES
#include <cmath>

#include "../../lib/Math/AllMath/AllMath.h"
#include "../../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"
#include "../../googletest/googletest/include/gtest/gtest.h"
//#include <gtest/gtest.h>


TEST(GameTests, MoveTest1)
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

TEST(GameTests, PlanarRotate)
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

TEST(GameTests, Rotate3D)
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