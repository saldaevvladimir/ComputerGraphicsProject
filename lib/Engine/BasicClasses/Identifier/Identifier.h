#pragma once

#include <unordered_set>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>


namespace Engine
{
    class Identifier
	{
	public:
		static std::unordered_set<std::string> existingIdentifiers;
		std::string value;

		Identifier();

		std::string GetValue() const;

		static void PrintExistingIdentifiers(std::ostream& output);

		static std::string Generate();
	};
}