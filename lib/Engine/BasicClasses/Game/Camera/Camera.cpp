#include "../Game.h"
#include "../../../../Math/Accuracy/Accuracy.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"

#include <cmath>


namespace Engine
{
    Game::Camera::Camera(Game::Object& object, float hfov, float drawDistance)
	{
		this->cs = object.cs;
		this->properties = object.properties;

		this->properties["hfov"] = hfov;
		this->properties["drawDistance"] = drawDistance;
	}

	Game::Camera::Camera(Game::Object& object, float hfov, float vfov, float drawDistance)
	{
		this->cs = object.cs;
		this->properties = object.properties;

		this->properties["hfov"] = hfov;
		this->properties["vfov"] = vfov;
		this->properties["drawDistance"] = drawDistance;
	}

	Game::Camera::Camera(Game::Object& object, float hfov, Point lookAt, float drawDistance)
	{
		this->cs = object.cs;
		this->properties = object.properties;

		this->properties["hfov"] = hfov;
		this->properties["lookAt"] = lookAt;
		this->properties["drawDistance"] = drawDistance;
	}

	Game::Camera::Camera(Game::Object& object, float hfov, float vfov, Point lookAt, float drawDistance)
	{
		this->cs = object.cs;
		this->properties = object.properties;

		this->properties["hfov"] = hfov;
		this->properties["vfov"] = vfov;
		this->properties["lookAt"] = lookAt;
		this->properties["drawDistance"] = drawDistance;
	}

	std::vector<std::vector<Ray>> Game::Camera::GetRaysMatrix(int height, int width)
	{
		Game::Camera& self = *this;

		float deltaAlpha = Round(std::get<float>(self.GetProperty("hfov")) / float(height));
	
		float deltaBetta = Round(std::get<float>(self.GetProperty("vfov")) / float(width));
	
		float zeroAngleX = Round(std::get<float>(self.GetProperty("hfov")) / 2.0f);

		float zeroAngleY = Round(std::get<float>(self.GetProperty("vfov")) / 2.0f);

		Vector direction;
		Point position = std::get<Point>(self.GetProperty("position"));

		if (self.HasProperty("direction"))
		{
			direction = std::get<Vector>(self.GetProperty("direction"));
		}
		else
		{
			Point lookAt = std::get<Point>(self.GetProperty("lookAt"));

			direction = position.GetDirectionToPoint(lookAt);
		}

		std::vector<std::vector<Ray>> rayMatrix(height, std::vector<Ray>(width));

		for (int r = 0; r < width; r++)
		{
			float curAngleX = deltaAlpha * r - zeroAngleX;
			
			for (int c = 0; c < width; c++)
			{
				float curAngleY = deltaBetta * c - zeroAngleY;

				Vector projectionDir = direction.Rotate(RxAxis, Matrix::ConvertToRadian(curAngleX));

				projectionDir = projectionDir.Rotate(RyAxis, Matrix::ConvertToRadian(curAngleY));

				projectionDir = float(std::pow(direction.Length(), 2)) / Vector::ScalarProduct(direction, projectionDir) * projectionDir;
			
				rayMatrix[r][c] = Ray(self.cs, position, projectionDir);
			}
		}

		return rayMatrix;
	}
}