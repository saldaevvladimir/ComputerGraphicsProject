#pragma once

#include "../Game.h"


namespace Engine
{
    class HyperEllipsoid : public Game::Object
    {
    public:
        HyperEllipsoid(Game::Object object, Point position, Vector diriction, std::vector<float> semiAxes);

        void PlanarRotate(int axisIndex1, int axisIndex2, float angle);

        void Rotate3D(float angle1, float angle2, float angle3);

        float IntersectionDistance(Ray ray) override;
        
    };
}