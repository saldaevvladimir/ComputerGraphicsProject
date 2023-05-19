#include "Entity.h"


namespace Engine
{
    Entity::Entity(CoordinateSystem cs)
	{
		this->cs = cs;
	}

	void Entity::SetProperty(const int& key, const std::string& value)
	{
		properties[key] = value;
	}

	const std::string& Entity::GetProperty(const int& key)
	{
		if (properties.find(key) != properties.end())
			return properties.find(key)->second;
			
		// exception : incorrect property index
	}

	void Entity::RemoveProperty(const int& key)
	{
		properties.erase(key);
	}

	std::string& Entity::operator [] (const int& key)
	{
		if (properties.find(key) == properties.end())
			properties[key] = "";

		return properties.find(key)->second;
	}

	const std::map<int, std::string>::iterator Entity::Property(const int& key)
	{
		return properties.find(key);
	}
}