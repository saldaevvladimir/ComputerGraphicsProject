#pragma once

#define PropertyType std::variant <int, float, bool, std::string, Matrix, Vector, Point, VectorSpace, CoordinateSystem, std::vector<float>>

#include "../Identifier/Identifier.h"
#include "../../../Math/CoordinateSystem/CoordinateSystem.h"
#include "../../../Engine/BasicClasses/Ray/Ray.h"

#include <map>
#include <any>
#include <variant>
#include <string>



namespace Engine
{
    class Entity
	{
	public:
		Identifier identifier;
		CoordinateSystem cs;
		std::map <std::string, std::any> properties;

		Entity() {};

		Entity(CoordinateSystem cs);

		void SetProperty(const std::string& key, const std::any& value);

		const std::any& GetProperty(const std::string& key);

		void RemoveProperty(const std::string& key);

		bool HasProperty(const std::string& key);
		
		virtual float IntersectionDistance(Ray ray);

		std::any& operator [] (const std::string& key);

		
	};
}