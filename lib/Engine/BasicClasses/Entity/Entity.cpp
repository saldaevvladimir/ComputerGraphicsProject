#include "Entity.h"
#include "../../../Exceptions/EngineExceptions/EngineException.h"


namespace Engine
{
    Entity::Entity(CoordinateSystem cs)
	{
		this->cs = cs;
	}

	void Entity::SetProperty(const std::string& key, const PropertyType& value)
	{
		properties[key] = value;
	}

	const PropertyType& Entity::GetProperty(const std::string& key)
	{
		if (properties.find(key) != properties.end())
			return properties.find(key)->second;
			
		throw EntityException::IncorrectPropertyKey(key);
	}

	void Entity::RemoveProperty(const std::string& key)
	{
		properties.erase(key);
	}

	PropertyType& Entity::operator [] (const std::string& key)
	{
		if (properties.find(key) == properties.end())
			properties[key] = "";

		return properties.find(key)->second;
	}

}