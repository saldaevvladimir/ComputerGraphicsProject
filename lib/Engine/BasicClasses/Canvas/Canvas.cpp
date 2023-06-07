#include "Canvas.h"

#define INF 9999999.0f

#include "../../../Math/Accuracy/Accuracy.h"
#include "../../../Math/Matrix/Matrix.h"
#include "../../../Exceptions/EngineExceptions/EngineException.h"
#include "../../../Exceptions/MathExceptions/MathException.h"

#include <vector>
#include <cmath>

namespace Engine
{
    Canvas::Canvas(int height, int width, Game game)
    {
        if (!Matrix::CorrectSizes(height, width))
            throw CanvasException::IncorrectSizes(height, width);

        this->height = height;
        this->width = width;
        this->game = game;
    }

    void Canvas::Update(Game::Camera camera)
    {
        Canvas& self = *this;
        std::size_t w = self.width;

        std::vector<std::vector<Engine::Ray>> rayMatrix;
        
        rayMatrix = camera.GetRaysMatrix(self.height, self.width);

        for (int r = 0; r < self.height; r++)
        {
            for (int c = 0; c < self.width; c++)
            {
                float distance = INF;
                
                for (auto obj : self.game.gameEntities.entities)
                {
                    float dist = 10.0f;
                    // float dist = obj.IntersectionDistance(rayMatrix[r][c]);
                    distance = std::min(distance, dist);
                }
                
                if (fabs(distance - INF) < PRECISION)
                    self.distances[r][c] = -1.0f;
                else
                    self.distances[r][c] = distance;
            }
        }
    }
}