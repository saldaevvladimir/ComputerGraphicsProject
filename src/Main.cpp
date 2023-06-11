#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"


int main()
{
    using namespace std;

    Engine::Configuration config;

    std::any obj = Matrix({{1, 1, 1}});

    bool compare = (obj.type() == typeid(Matrix)); // true



    return 0;
}


