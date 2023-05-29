#include "EntitiesList.h"
#include "../../../Exceptions/EngineExceptions/EngineException.h"


namespace Engine
{
    EntitiesList::EntitiesList()
	{
		std::list<Entity> entities = {};
	}

	void EntitiesList::Append(Entity entity)
	{
		bool entityFound = false;

		for (const auto& en : this->entities)
			if (en.identifier.GetValue() == entity.identifier.GetValue())
			{
				entityFound = true;
				break;
			}

		if (!entityFound)
			this->entities.push_back(entity);
	}

	void EntitiesList::Remove(Identifier identifier)
	{
		std::list<Entity>::iterator it = this->entities.begin();

		while (it++ != this->entities.end())
			if ((*it).identifier.GetValue() == identifier.GetValue())
			{
				this->entities.erase(it);
				break;
			}
	}

	Entity EntitiesList::Get(Identifier identifier)
	{
		bool entityFound = false;

		for (const auto& entity : this->entities)
			if (entity.identifier.GetValue() == identifier.GetValue())
				return entity;

		throw EntitiesListException::IdentifierDoesNotExist(identifier.GetValue());
	}

	void EntitiesList::Execute()
	{
		
	}

	Entity EntitiesList::operator [] (Identifier identifier)
	{
		return EntitiesList::Get(identifier);
	}

}