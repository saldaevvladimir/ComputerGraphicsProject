#include "Identifier.h"


namespace Engine
{
	std::unordered_set<std::string> Identifier::existingIdentifiers;

	Identifier::Identifier()
	{
		value = Identifier::Generate();
		existingIdentifiers.insert(value);
	}

	std::string Identifier::GetValue() const 
	{
		return this->value;
	}

	void Identifier::PrintExistingIdentifiers(std::ostream& output)
	{
		for (const auto& identifier : Identifier::existingIdentifiers)
			output << identifier << '\n';
	}

	std::string Identifier::Generate()
	{
		std::stringstream ss;
		bool uniqueIdFound = false;

		while (!uniqueIdFound)
		{
			long long currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now().time_since_epoch()).count();

			ss.str("");
			ss << std::hex << std::setfill('0') << std::setw(16) << currentTime;

			if (!existingIdentifiers.count(ss.str()))
				uniqueIdFound = true;
		}

		return ss.str();
	}
}