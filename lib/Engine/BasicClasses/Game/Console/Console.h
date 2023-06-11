#pragma once

#include "../../../../Math/Matrix/Matrix.h"

#include <string>


namespace Engine
{
    class Console
    {
    public:
        std::string charmap = " .:;><+r*zsvfwqkP694VOGbUAKXH8RD#$B0MNWQ%&@";

        Console(std::string charmap);

        void Draw(Matrix distances, float drawDistance);

    };
}