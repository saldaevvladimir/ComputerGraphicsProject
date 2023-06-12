#include "HyperEllipsoid.h"
#include "../../../../Math/Accuracy/Accuracy.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"

#include <cmath>
#include <vector>
#include <algorithm>


namespace Engine
{
    HyperEllipsoid::HyperEllipsoid(Game game, Point position, Vector direction, Vector semiAxes)
    {
        this->cs = game.cs;

        this->properties["position"] = position;
        this->properties["direction"] = direction.Normalize();
        this->properties["semiAxes"] = semiAxes;

        this->properties["type"] = std::string("HyperEllipsoid");
    }

    HyperEllipsoid::HyperEllipsoid(Game::Object object, Point position, Vector direction, Vector semiAxes)
    {
        this->cs = object.cs;
        this->properties = object.properties;

        this->properties["position"] = position;
        this->properties["direction"] = direction.Normalize();
        this->properties["semiAxes"] = semiAxes;

        this->properties["type"] = std::string("HyperEllipsoid");
    }

    HyperEllipsoid::HyperEllipsoid(Entity entity)
    {
        this->cs = entity.cs;
        this->properties = entity.properties;
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

        Vector params = self.FindParams(ray);

        if (params[2] == 0)
            return INF;

        Vector rayDir = ray.direction;

        float distance1 = 0.0f;
        float distance2 = 0.0f;

        for (int i = 0; i < rayDir.Dim(); i++)
        {
            distance1 += (float)std::pow(params[0] * rayDir[i], 2);
            distance2 += (float)std::pow(params[1] * rayDir[i], 2);
        }
        if (distance1 < distance2)
            return Round(std::sqrt(distance1));
        else
            return Round(std::sqrt(distance2));
    }

    Vector HyperEllipsoid::FindParams(Ray ray)
    {
        HyperEllipsoid& self = *this;

        Vector result(3);

        float a = 0.0f;
        float b = 0.0f;
        float c = 0.0f;

        float freeCoef = 1.0f;

        Point startRay = ray.initialPoint;
        Vector rayDir = ray.direction;
        Vector semiAxes = std::any_cast<Vector>(self.GetProperty("semiAxes"));
        Point pos = std::any_cast<Point>(self.GetProperty("position"));

        int dim = startRay.Dim();

        if (rayDir.Dim() != dim || semiAxes.Dim() != dim)
            throw HyperEllipsoidException::IncorrectDimensions(startRay.Dim(), rayDir.Dim(), semiAxes.Dim());

        for (int i = 0; i < dim; i++)
        {
            float coef = 1.0f;

            for (int j = 0; j < dim; j++)
            {
                if (i == j)
                    continue;
                coef *= std::pow(semiAxes[j], 2);
            }
            a += coef * std::pow(rayDir[i], 2);
            b += coef * (startRay[i] - pos[i]);
            c += coef * std::pow(startRay[i] - pos[i], 2);

            freeCoef *= std::pow(semiAxes[i], 2);
        }

        c -= freeCoef;
        b = 2 * b;
        float Dis = std::pow(b, 2) - 4 * a * c;

        if (Dis < 0)
            return result;

        float ans1 = (-b + (float)std::sqrt(Dis)) / (2 * a);
        float ans2 = (-b - (float)std::sqrt(Dis)) / (2 * a);

        result[0] = ans1;
        result[1] = ans2;
        result[2] = 1.0f; // flag 

        return result;
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