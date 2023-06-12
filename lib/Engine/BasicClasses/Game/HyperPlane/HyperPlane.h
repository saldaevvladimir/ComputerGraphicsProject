#pragma once

#include "../Game.h"


namespace Engine
{
    class HyperPlane : public Game::Object
    {
    public:
        HyperPlane(Game game, Point position, Vector normal);

        HyperPlane(Game::Object object, Point position, Vector normal);

        HyperPlane(Entity entity);

        void PlanarRotate(int axisIndex1, int axisIndex2, float angle);

        void Rotate3D(float angle1, float angle2, float angle3);

        float IntersectionDistance(Ray ray) override;

        void operator = (Entity entity);

    };
}