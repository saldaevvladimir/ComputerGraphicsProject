#include "Game.h"
#include "../../../Exceptions/MathExceptions/MathException.h"


namespace Engine
{

	Game::Game()
	{
		this->cs = CoordinateSystem();
		this->gameEntities = EntitiesList();
		this->es = EventSystem();
	}

    Game::Game(CoordinateSystem cs, EntitiesList gameEntities, EventSystem es)
	{
		if (!cs.IsInitialized())
			throw CoordinateSystemException::NotInitialized();
			
		this->cs = cs;
		this->gameEntities = gameEntities;
		this->es = es;
	}

	EventSystem Game::GetEventSystem()
	{
		return this->es;
	}

	void Game::ApplyConfiguration(Configuration config)
	{
		Game& self = *this;

		for (const auto& [key, val] : config.configuration)
		{
			//self[key] = val;
		}
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