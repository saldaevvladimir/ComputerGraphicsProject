#include "Accuracy.h"
#include <cmath>


float Round(float number, float precision) 
{
    return round(number / precision) * precision + 0.0f; 
}