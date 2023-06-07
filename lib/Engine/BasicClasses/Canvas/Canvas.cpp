#include "Canvas.h"

#define INF 9999999.0f

#include "../../../Math/Accuracy/Accuracy.h"
#include "../../../Math/Matrix/Matrix.h"
#include "../../../Exceptions/EngineExceptions/EngineException.h"
#include "../../../Exceptions/MathExceptions/MathException.h"
#include "../../../Engine/BasicClasses/Game/HyperPlane/HyperPlane.h"
#include "../../../Engine/BasicClasses/Game/HyperEllipsoid/HyperEllipsoid.h"

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

    float Canvas::GetIntersectionDistance(Entity entity, Ray ray)
    {
        if (entity.HasProperty("type"))
        {
            std::string type = std::get<std::string>(entity["type"]);

            if (type == "HyperPlane")
            {
                HyperPlane plane(entity);
                return plane.Engine::HyperPlane::IntersectionDistance(ray);
            }
            else if (type == "HyperEllipsoid")
            {
                HyperEllipsoid ellipsoid(entity);
                return ellipsoid.Engine::HyperEllipsoid::IntersectionDistance(ray);
            }
            else
            {
                // there are only 2 types now
                return -1.0f;
            }
        }
        else
        {
            return entity.Entity::IntersectionDistance(ray);
        }
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
                
                for (auto entity : self.game.gameEntities.entities)
                {
                    float dist = GetIntersectionDistance(entity, rayMatrix[r][c]);
                    distance = std::min(distance, dist);
                }
                
                self.distances[r][c] = distance;
            }
        }
    }
}
