#include "../Game.h"
#include "../../../../Math/Accuracy/Accuracy.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"

#include <cmath>


namespace Engine
{
	Game::Camera::Camera()
	{

	}
	
    Game::Camera::Camera(Game::Object& object, float hfov, float drawDistance)
	{
		this->cs = object.cs;
		this->properties = object.properties;

		this->properties["hfov"] = hfov;
		this->properties["vfov"] = hfov * 9 / 16.0f;
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
		this->properties["vfov"] = hfov * 9 / 16.0f;
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

		float deltaAlpha = Round(std::any_cast<float>(self.GetProperty("hfov")) / float(height));
	
		float deltaBetta = Round(std::any_cast<float>(self.GetProperty("vfov")) / float(width));
	
		float zeroAngleX = Round(std::any_cast<float>(self.GetProperty("hfov")) / 2.0f);

		float zeroAngleY = Round(std::any_cast<float>(self.GetProperty("vfov")) / 2.0f);

		Vector direction;
		Point position = std::any_cast<Point>(self.GetProperty("position"));

		if (self.HasProperty("direction"))
		{
			direction = std::any_cast<Vector>(self.GetProperty("direction"));
		}
		else
		{
			Point lookAt = std::any_cast<Point>(self.GetProperty("lookAt"));

			direction = position.GetDirectionToPoint(lookAt);
		}

		std::vector<std::vector<Ray>> rayMatrix(height, std::vector<Ray>(width));

		for (int r = 0; r < height; r++)
		{
			float curAngleX = deltaAlpha * r - zeroAngleX;
			
			for (int c = 0; c < width; c++)
			{
				float curAngleY = deltaBetta * c - zeroAngleY;

				Vector projectionDir = direction.Rotate(RxAxis, curAngleX);

				projectionDir = projectionDir.Rotate(RyAxis, curAngleY);

				projectionDir = float(std::pow(direction.Length(), 2)) / Vector::ScalarProduct(direction, projectionDir) * projectionDir;
			
				rayMatrix[r][c] = Ray(self.cs, position, projectionDir);
			}
		}

		return rayMatrix;
	}
}