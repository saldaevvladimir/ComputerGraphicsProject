#pragma once

#define DEFAULT_CONFIGURATION_FILE_PATH "../config/DefaultConfiguration.json"

#include <any>
#include <map>
#include <string>


namespace Engine
{
    class Configuration
    {
    public:
        std::string filepath = "";
        
        std::map<std::string, std::any> configuration;

        Configuration(std::string filepath = DEFAULT_CONFIGURATION_FILE_PATH);

        void SetVariable(std::string name, std::any value);

        std::any GetVariable(const std::string& name);

        void RemoveVariable(const std::string& name);

        void ExecuteFile(const std::string filepath = DEFAULT_CONFIGURATION_FILE_PATH);

        void Save(std::string filepath = DEFAULT_CONFIGURATION_FILE_PATH);

        std::any& operator [] (std::string name);
    };
}