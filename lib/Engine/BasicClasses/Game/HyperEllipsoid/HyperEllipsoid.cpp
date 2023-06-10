#include "HyperEllipsoid.h"
#include "../../../../Math/Accuracy/Accuracy.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"

#include <cmath>


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

        Vector params;
        params = self.FindParams(ray);

        if (params[2] < PRECISION)
            return INF;

        Vector rayDir = ray.direction;

        float dist1 = 0.0f;
        float dist2 = 0.0f;

        for (int i = 0; i < rayDir.Dim(); i++)
        {
            dist1 += params[0] * rayDir[i];
            dist2 += params[1] * rayDir[i];
        }

        return (std::min(fabs(dist1), fabs(dist2)));
    }

    Vector HyperEllipsoid::FindParams(Ray ray)
    {
        HyperEllipsoid& self = *this;

        float a = 0.0f;
        float b = 0.0f;
        float c = 0.0f;

        float freeCoef = 0.0f;
        Vector result({0, 0, 0});

        Point initPoint = ray.initialPoint;
        Vector dir = ray.direction;
        Vector semiAxes = std::get<Vector>(self["semiAxes"]);

        int dim = initPoint.Dim();

        if (dir.Dim() != dim || semiAxes.Dim() != dim)
            throw HyperEllipsoidException::IncorrectDimensions(initPoint.Dim(), dir.Dim(), semiAxes.Dim());

        for (int i = 0; i < dim; i++)
        {
            float coef = 1.0f;

            for (int j = 0; j < dim; j++)
            {
                if (i == j)
                    continue;

                coef *= std::pow(semiAxes[j], 2);
            }

            a += coef * std::pow(dir[i], 2);
            b += coef * initPoint[i];
            c += coef * std::pow(initPoint[i], 2);

            freeCoef *= std::pow(semiAxes[i], 2);
        }

        c -= freeCoef;
        b *= 2;
        float Dis = std::pow(b, 2) - 4 * a * c;

        if (Dis < 0)
        {
            result[2] = 0.0f; // flag
        }
        else
        {
            float sln1 = (-b + (float)std::sqrt(Dis)) / (2 * a);
            float sln2 = (-b - (float)std::sqrt(Dis)) / (2 * a);
            std::cout << a << " " << b << " " << Dis << std::endl;

            result[0] = sln1;
            result[1] = sln2;
            result[2] = 1.0f; // flag
        }
        
        return result;
    }

    void HyperEllipsoid::operator = (Entity entity)
    {
        if (entity.HasProperty("type"))
        {
            if (std::get<std::string>(entity["type"]) != "HyperEllipsoid")
            {
                throw EngineException::IncorrectArgumentType("HyperEllipsoid", std::get<std::string>(entity["type"]));
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