#include "HyperPlane.h"


namespace Engine
{
    HyperPlane::HyperPlane(Game::Object object, Point position, Vector normal)
    {
        this->cs = object.cs;
        this->properties = object.properties;
        
        this->properties["position"] = position;
        this->properties["normal"] = normal;

        Vector direction = std::get<Vector>(object.GetProperty("direction"));
        direction = direction.Normalize();

        this->properties["direction"] = direction;

        this->properties["type"] = "HyperPlane";
    }

    HyperPlane::HyperPlane(Entity entity)
    {
        *this = entity;
    }

    void HyperPlane::PlanarRotate(int axisIndex1, int axisIndex2, float angle)
    {
        HyperPlane& self = *this;
        Vector direction = std::get<Vector>(self.GetProperty("direction"));

        direction = direction.Rotate(axisIndex1, axisIndex2, angle);

        self.SetDirection(direction);
    }

    void HyperPlane::Rotate3D(float angle1, float angle2, float angle3)
    {
        HyperPlane& self = *this;
        Vector direction = std::get<Vector>(self.GetProperty("direction"));

        direction = direction.Rotate3D(angle1, angle2, angle3);

        self.SetDirection(direction);
    }

    float HyperPlane::IntersectionDistance(Ray ray)
    {
        HyperPlane& self = *this;

        Point rayPoint = ray.initialPoint;
        Vector rayDir = ray.direction;

        Point planePoint = std::get<Point>(self["position"]);
        Vector planeDir = std::get<Vector>(self["direction"]);

        if (planeDir % rayDir == 0.0f)
        {
            if ((planeDir % (rayPoint - planePoint)) != 0.0f)
                throw std::exception();
            else
                return 0.0f;
        }
        else
        {
            float tmp = - (planeDir % (rayPoint - planePoint)) / (planeDir % rayDir);

            if (tmp < 0.0f)
                return -1.0f;
            else
                return (rayDir * tmp).Length();
        }
    }

    void HyperPlane::operator = (Entity entity)
    {
        if (entity.HasProperty("type"))
        {
            if (std::get<std::string>(entity["type"]) == "HyperPlane")
            {
                this->cs = entity.cs;
                this->properties = entity.properties;

                return;
            }
        }

        // exception: entity is not a HyperPlane
    }
}