#include "Game.h"
#include "../../../Exceptions/MathExceptions/MathException.h"


namespace Engine
{
    Game::Game(CoordinateSystem cs, EntitiesList gameEntities)
	{
		if (!cs.IsInitialized())
			throw CoordinateSystemException::NotInitialized();
			
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
		return Engine::Entity(this->cs);
	}

	Ray Game::GetRayClass()
	{
		return Engine::Ray(this->cs);
	}
}