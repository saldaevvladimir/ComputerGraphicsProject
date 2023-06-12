#include "Console.h"
#include "../../../../Math/Accuracy/Accuracy.h"

#include <iostream>
#include <fstream>


Console::Console(int height, int width, Engine::Game game, Engine::Game::Camera camera, std::string charmap) : 
    Canvas(height, width, game, camera, charmap)
{

}

void Console::Draw()
{
    Console& console = *this;

    console.Clear();

    float drawDist = std::any_cast<float>(console.camera.GetProperty("drawDistance"));

    int charmapSize = console.charmap.size();

    float delta = drawDist / charmapSize;

    for (int r = 0; r < console.height; r++)
    {
        for(int c = 0; c < console.width; c++)
        {
            if (console.distances[r][c] > drawDist || console.distances[r][c] == INF)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << charmap[charmapSize - 1 - int(console.distances[r][c] / delta)];
            }
        }

        std::cout << std::endl;
    }
}

void Console::Clear()
{
    std::cout << "\033[2J\033[1;1H";
}

void Console::SetCursorPosition(int x, int y)
{
    if (x > 0 && y > 0)
    {
        std::cout << "\033[" << y << ";" << x << "H";
    }
}



