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
		Engine::Entity& self = *this;

		if (self.HasProperty(key))
			return properties.find(key)->second;
			
		throw EntityException::IncorrectPropertyKey(key);
	}

	void Entity::RemoveProperty(const std::string& key)
	{
		properties.erase(key);
	}

	bool Entity::HasProperty(const std::string& key)
	{
		return (properties.find(key) != properties.end());
	}

	float Entity::IntersectionDistance(Ray ray)
	{
		return -100.0f;
	}

	PropertyType& Entity::operator [] (const std::string& key)
	{
		Engine::Entity& self = *this;

		if (!self.HasProperty(key))
			properties[key] = "";

		return properties.find(key)->second;
	}

}