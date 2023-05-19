#include "Game.h"


namespace Engine
{
    Game::Game(CoordinateSystem cs, EntitiesList gameEntities)
	{
		this->cs = cs;
		this->gameEntities = gameEntities;
	}

	void Game::Run()
	{

	}
	
	void Game::Update()
	{

	}

	void Game::Exit()
	{

	}

	Entity Game::GetEntityClass()
	{
		return Entity(this->cs);
	}

	Ray Game::GetRayClass()
	{
		return Ray(this->cs);
	}
}