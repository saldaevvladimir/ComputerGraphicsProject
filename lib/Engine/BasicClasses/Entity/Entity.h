#pragma once

#include "..\Identifier\Identifier.h"
#include "..\..\..\Math\CoordinateSystem\CoordinateSystem.h"

#include <map>


namespace Engine
{
    class Entity
	{
	public:
		Identifier identifier;
		CoordinateSystem cs;
		std::map<int, std::string> properties;

		Entity() {};

		Entity(CoordinateSystem cs);

		void SetProperty(const int& key, const std::string& value);

		const std::string& GetProperty(const int& key);

		void RemoveProperty(const int& key);

		std::string& operator [] (const int& key);

		const std::map<int, std::string>::iterator Property(const int& key);
	};
}