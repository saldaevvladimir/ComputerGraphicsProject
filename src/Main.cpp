#include <iostream>
#include <iomanip>
#include <cmath>

#include "../lib/Math/AllMath/AllMath.h"

#include "../lib/Engine/BasicClasses/AllBasicClasses/AllBasicClasses.h"

int main()
{
	using namespace std;

	Engine::Entity entity;
   entity.SetProperty("num", 34);
   entity.SetProperty("some_str", "something");

   cout << std::get<int>(entity["num"]) << std::endl;
   entity["num"] = 54;
   cout << std::get<int>(entity["num"]) << std::endl;

   return 0;
}