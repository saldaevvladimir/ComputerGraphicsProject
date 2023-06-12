#include "HyperEllipsoid.h"
#include "../../../../Math/Accuracy/Accuracy.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"

#include <cmath>
#include <vector>
#include <algorithm>


namespace Engine
{
    HyperEllipsoid::HyperEllipsoid(Game::Object object, Point position, Vector direction, Vector semiAxes)
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

        Vector direction = std::any_cast<Vector>(self["direction"]);

        direction = direction.Rotate(axisIndex1, axisIndex2, angle);

        self.SetDirection(direction);
    }

    void HyperEllipsoid::Rotate3D(float angle1, float angle2, float angle3)
    {
        HyperEllipsoid& self = *this;

        Vector direction = std::any_cast<Vector>(self["direction"]);

        direction = direction.Rotate3D(angle1, angle2, angle3);

        self.SetDirection(direction);
    }

    float HyperEllipsoid::IntersectionDistance(Ray ray)
    {
        HyperEllipsoid& self = *this;

        Vector dir= ray.direction;
        Point pos = ray.initialPoint - std::any_cast<Point>(self["position"]);
        int dim = dir.Dim();

        Vector semiAxes = std::any_cast<Vector>(self["semiAxes"]);

        float p1 = 0.0f;
        float p2 = 0.0f;
        float p3 = -1.0f;

        for (int i = 0; i < dim; i++)
        {
            p1 += std::pow(dir[i], 2) / std::pow(semiAxes[i], 2);
            p2 += 2 * pos[i] * dir[i] / std::pow(semiAxes[i], 2);
            p3 += std::pow(pos[i], 2) / std::pow(semiAxes[i], 2);
        }

        float t1 = (-p2 + std::sqrt(std::pow(p2, 2)-4*p1*p3)) / 2 * p1;
        float t2 = (-p2 - std::sqrt(std::pow(p2, 2)-4*p1*p3)) / 2 * p1;

        std::vector<float> t;

        for (auto y : {t1, t2}) 
            if (typeid(y) == typeid(int) || typeid(y) == typeid(float)) 
              t.push_back(y);

        for (auto it = t.begin(); it != t.end();) 
        {
            if (*it <= 0) 
              it = t.erase(it);
            else 
              ++it;
        }

        if (t.size() == 0)
            return INF;

        float tMin = *std::min_element(t.begin(), t.end());

        Vector intersection(dim);
        for (int i = 0; i < dim; i++)
        intersection[i] = pos[i] + dir[i] * tMin;

        Vector temp = self.cs.space.AsVector(pos);

        return Round((intersection - temp).Length());
    }

    void HyperEllipsoid::operator = (Entity entity)
    {
        if (entity.HasProperty("type"))
        {
            if (std::any_cast<std::string>(entity["type"]) != "HyperEllipsoid")
            {
                throw EngineException::IncorrectArgumentType("HyperEllipsoid", std::any_cast<std::string>(entity["type"]));
            }
            else
            {
                this->cs = entity.cs;
                this->properties = entity.properties;
            }
        }
        else
        {
            throw EngineException::IncorrectArgumentType("HyperEllipsoid", "type_not_specified");
        }
    }
}