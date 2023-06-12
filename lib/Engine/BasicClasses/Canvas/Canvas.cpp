#include "Canvas.h"

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
    Canvas::Canvas(int height, int width, Game game, Game::Camera camera, std::string charmap)
    {
        if (!Matrix::CorrectSizes(height, width))
            throw CanvasException::IncorrectSizes(height, width);

        this->height = height;
        this->width = width;
        this->distances = Matrix(height, width);
        this->game = game;
        this->camera = camera;
        this->charmap = charmap;
    }

    void Canvas::Draw()
    {
        
    }

    // float Canvas::GetIntersectionDistance(HyperPlane entity, Ray ray)
    // {
    //     return entity.IntersectionDistance(ray);
    // }

    // float Canvas::GetIntersectionDistance(HyperEllipsoid entity, Ray ray)
    // {
    //     return entity.IntersectionDistance(ray);
    // }

    float Canvas::GetIntersectionDistance(Entity entity, Ray ray)
    {
        if (entity.HasProperty("type"))
        {
            std::string type = std::any_cast<std::string>(entity["type"]);

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
                return INF;
            }
        }
        else
        {
            return entity.Entity::IntersectionDistance(ray);
        }
    }

    void Canvas::Update()
    {
        Canvas& self = *this;

        std::vector<std::vector<Ray>> rayMatrix = self.camera.GetRaysMatrix(self.height, self.width);

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
