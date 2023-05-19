#include "..\Game.h"


namespace Engine
{
    Game::Object::Object(Game& game, Point position, Vector direction) : Entity(game.cs)
	{
		this->position = position;
		this->direction = direction;
	}

	Game::Object::Object(Game& game) : Entity(game.cs)
	{
		this->position = game.cs.initialPoint;
		this->direction = game.cs.space.basis[0];
	}

	void Game::Object::Move(float distance)
	{
		this->position = this->position + this->direction.Normalize() * distance;
	}

	void Game::Object::PlanarRotate(int axisIndex1, int axisIndex2, float angle)
	{
		this->direction = this->direction.Rotate(axisIndex1, axisIndex2, angle);
	}

	void Game::Object::Rotate3D(float angle1, float angle2, float angle3)
	{
		this->direction = this->direction.Rotate3D(angle1, angle2, angle3);
	}

	void Game::Object::SetPosition(Point position)
	{
		this->position = position;
	}

	void Game::Object::SetDirection(Vector direction)
	{
		this->direction = direction;
	}
}