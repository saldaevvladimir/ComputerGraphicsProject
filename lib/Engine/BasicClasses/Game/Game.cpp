#include "Game.h"
#include "../../../Exceptions/MathExceptions/MathException.h"


namespace Engine
{

	Game::Game()
	{
		this->cs = CoordinateSystem();
		this->gameEntities = EntitiesList();
	}

    Game::Game(CoordinateSystem cs, EntitiesList gameEntities)
	{
		if (!cs.IsInitialized())
			throw CoordinateSystemException::NotInitialized();
			
		this->cs = cs;
		this->gameEntities = gameEntities;
	}

	void Game::Append(Entity entity)
	{
		Game& self = *this;
		self.gameEntities.Append(entity);
	}

	void Game::operator = (Game game)
	{
		Game& self = *this;

		self.cs = game.cs;
		self.gameEntities = game.gameEntities;
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