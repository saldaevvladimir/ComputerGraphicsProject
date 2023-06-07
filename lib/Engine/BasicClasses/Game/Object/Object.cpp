#include "../Game.h"
#include "../../../../Exceptions/EngineExceptions/EngineException.h"


namespace Engine
{
	Game::Object::Object()
	{
		this->cs = CoordinateSystem();
	}

	Game::Object::Object(GameEntity& gameEntity)
	{
		this->cs = gameEntity.cs;
		this->properties = gameEntity.properties;
	}

    Game::Object::Object(GameEntity& gameEntity, Point position, Vector direction)
	{
		this->cs = gameEntity.cs;
		this->properties = gameEntity.properties;

		properties["position"] = position;
		properties["direction"] = direction;
	}

	void Game::Object::Move(float distance)
	{
		Game::Object& object = *this;
		
		Point position = std::get<Point>(object.GetProperty("position"));
		Vector direction = this->cs.space.Normalize(std::get<Vector>(object.GetProperty("direction")));

		position = position + direction * distance;
		
		object.SetPosition(position);
	}

	void Game::Object::PlanarRotate(int axisIndex1, int axisIndex2, float angle)
	{
		Game::Object& object = *this;

		Vector direction = std::get<Vector>(object.GetProperty("direction"));

		object.SetDirection(direction.Rotate(axisIndex1, axisIndex2, angle));
	}

	void Game::Object::Rotate3D(float angle1, float angle2, float angle3)
	{
		Game::Object& object = *this;

		Vector direction = std::get<Vector>(object.GetProperty("direction"));

		object.SetDirection(direction.Rotate3D(angle1, angle2, angle3));
	}

	void Game::Object::SetPosition(Point position)
	{
		Game::Object& object = *this;

		object.SetProperty("position", position);	
	}

	void Game::Object::SetDirection(Vector direction)
	{
		Game::Object& object = *this;

		object.SetProperty("direction", direction);
	}
}