#include "..\Game.h"


namespace Engine
{
    Game::Object::Object(Game& game, Point position, Vector direction) : Entity(game.cs)
	{
		this->properties["position"] = position;
		this->properties["direction"] = direction;
	}

	Game::Object::Object(Game& game) : Entity(game.cs)
	{
		this->properties["position"] = game.cs.initialPoint;
		this->properties["direction"] = game.cs.space.basis[0];
	}

	void Game::Object::Move(float distance)
	{
		this->properties["position"] = this->properties["position"] + this->properties["direction"].Normalize() * distance;
	}

	void Game::Object::PlanarRotate(int axisIndex1, int axisIndex2, float angle)
	{
		this->properties["direction"] = this->properties["direction"].Rotate(axisIndex1, axisIndex2, angle);
	}

	void Game::Object::Rotate3D(float angle1, float angle2, float angle3)
	{
		Vector direction = this->properties["direction"];
		direction = direction.Rotate3D(angle1, angle2, angle3);
		this->properties["direction"] = direction;
	}

	void Game::Object::SetPosition(Point position)
	{
		this->properties["position"] = position;
	}

	void Game::Object::SetDirection(Vector direction)
	{
		this->properties["direction"] = direction;
	}
}