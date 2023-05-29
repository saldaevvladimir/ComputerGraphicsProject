#include "../Game.h"


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
}