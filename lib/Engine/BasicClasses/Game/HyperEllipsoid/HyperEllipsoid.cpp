#include "HyperEllipsoid.h"

#include <cmath>


namespace Engine
{
    HyperEllipsoid::HyperEllipsoid(Game::Object object, Point position, Vector direction, std::vector<float> semiAxes)
    {
        this->cs = object.cs;
        this->properties = object.properties;

        this->properties["position"] = position;
        this->properties["direction"] = direction.Normalize();
        this->properties["semiAxes"] = semiAxes;

        this->properties["type"] = "HyperEllipsoid";
    }

    HyperEllipsoid::HyperEllipsoid(Entity entity)
    {
        *this = entity;
    }

    void HyperEllipsoid::PlanarRotate(int axisIndex1, int axisIndex2, float angle)
    {
        HyperEllipsoid& self = *this;

        Vector direction = std::get<Vector>(self["direction"]);

        direction = direction.Rotate(axisIndex1, axisIndex2, angle);

        self.SetDirection(direction);
    }

    void HyperEllipsoid::Rotate3D(float angle1, float angle2, float angle3)
    {
        HyperEllipsoid& self = *this;

        Vector direction = std::get<Vector>(self["direction"]);

        direction = direction.Rotate3D(angle1, angle2, angle3);

        self.SetDirection(direction);
    }

    float HyperEllipsoid::IntersectionDistance(Ray ray)
    {
        HyperEllipsoid& self = *this;

        Point rayPoint = ray.initialPoint;
        Vector rayDir = ray.direction;

        Vector ellipsoidDir = std::get<Vector>(self["direction"]);

        float alpha = (std::pow(rayDir[0], 2)) / (std::pow(ellipsoidDir[0], 2)) + 
            (std::pow(rayDir[1], 2)) / (std::pow(ellipsoidDir[1], 2)) + 
            (std::pow(rayDir[2], 2)) / (std::pow(ellipsoidDir[2], 2));

        float betta = 2 * ((rayDir[0] * rayPoint[0]) / (std::pow(ellipsoidDir[0], 2)) + 
            (rayDir[1] * rayPoint[1]) / (std::pow(ellipsoidDir[1], 2)) + 
            (rayDir[2] * rayPoint[2]) / (std::pow(ellipsoidDir[2], 2)));

        float gamma = (std::pow(rayPoint[0], 2)) / (std::pow(ellipsoidDir[0], 2)) + 
            (std::pow(rayPoint[1], 2)) / (std::pow(ellipsoidDir[1], 2)) + 
            (std::pow(rayPoint[2], 2)) / (std::pow(ellipsoidDir[2], 2));

        float disc = std::pow(betta, 2) - 4.0f * alpha * gamma;

        if (disc < 0.0f)
        {
            return -1.0f;
        }
        else
        {
            float t1 = (-betta + std::sqrt(disc)) / (2 * alpha);
            float t2 = (-betta - std::sqrt(disc)) / (2 * alpha);

            Vector vec1 = rayDir * t1;
            Vector vec2 = rayDir * t2;

            if (t1 > 0 && t2 > 0)
                return std::min(vec1.Length(), vec2.Length());
            else if  (t1 > 0 && t2 <= 0)
                return vec1.Length();
            else if (t1 <= 0 && t2 < 0)
                return vec2.Length();
            else
                return -1.0f;
        }
    }

    void HyperEllipsoid::operator = (Entity entity)
    {
        if (entity.HasProperty("type"))
        {
            if (std::get<std::string>(entity["type"]) == "HyperEllipsoid")
            {
                this->cs = entity.cs;
                this->properties = entity.properties;

                return;
            }
        }

        // exception: entity is not a HyperEllipsoid
    }
}