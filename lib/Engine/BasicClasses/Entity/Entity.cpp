#include "Entity.h"


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
			
		// exception : incorrect property index
	}

	template <typename T>
	T GetProp(const std::map<std::string, std::variant<PropertyType>>& prop, const std::string& key)
	{
		auto iter = prop.find(key);
		if (iter != prop.end())
		{
			return std::get<T>(iter->second);
		}
		else
		{
			
		}
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