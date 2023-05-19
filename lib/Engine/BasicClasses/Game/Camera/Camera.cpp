#include "..\Game.h"


namespace Engine
{
    Game::Camera::Camera(Game& game, float hfov, float drawDistance) : Game::Object(game)
	{
		this->hfov = hfov;
		this->hfov = hfov;
		this->drawDistance = drawDistance;
	}

	Game::Camera::Camera(Game& game, float hfov,float vfov, float drawDistance) : Game::Object(game)
	{
		this->hfov = hfov;
		this->vfov = vfov;
		this->drawDistance = drawDistance;
	}

	Game::Camera::Camera(Game& game, float hfov, Point lookAt, float drawDistance) : Game::Object(game)
	{
		this->hfov = hfov;
		this->vfov = hfov;
		this->drawDistance = drawDistance;
		this->direction = lookAt;
	}

	Game::Camera::Camera(Game& game, float hfov, float vfov, Point lookAt, float drawDistance) : Game::Object(game)
	{
		this->hfov = hfov;
		this->vfov = vfov;
		this->drawDistance = drawDistance;
		this->direction = lookAt;
	}
}