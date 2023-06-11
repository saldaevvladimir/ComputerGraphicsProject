#include "Configuration.h"
#include "../../../Exceptions/EngineExceptions/EngineException.h"

#include "json/json.h"

#include <fstream>
#include <iostream>


namespace Engine
{
    Configuration::Configuration(std::string filepath)
    {
        std::ifstream configFile(filepath, std::ifstream::binary);
        
        if (!configFile.is_open())
            throw ConfigurationException::FileNotFound(filepath);

        this->filepath = filepath;

        Json::Value config;

        configFile >> config;

        this->configuration["precision"] = config["precision"];
        this->configuration["drawDistance"] = config["drawDistance"];
        
        configFile.close();
    }

    void Configuration::SetVariable(std::string name, std::any value)
    {
        this->configuration[name] = value;
    }

    std::any Configuration::GetVariable(const std::string& name)
    {
        if (configuration.find(name) == configuration.end())
            configuration[name] = "";

        return configuration[name];
    }

    void Configuration::RemoveVariable(const std::string& name)
    {
        auto iter = configuration.find(name);

        if (iter != configuration.end())
            configuration.erase(iter);
    }

    void Configuration::ExecuteFile(std::string filepath)
    {
        std::ifstream configFile (filepath, std::ifstream::binary);

        if (!configFile.is_open())
            throw ConfigurationException::FileNotFound(filepath);

        Json::Value config;

        configFile >> config;

        for (const auto& name : config.getMemberNames())
            SetVariable(name, config[name]);

        configFile.close();
    }

    void Configuration::Save(std::string filepath)
    {
        if (filepath.empty())
            filepath = this->filepath;

        std::ofstream configFile (filepath, std::ofstream::binary);

        if (!configFile.is_open())
            throw ConfigurationException::FileNotFound(filepath);

        Json::Value config;

        for (const auto& [key, value] : configuration)
        {
            if (value.type() == typeid(int))
                config[key] = std::any_cast<int>(value);
            else if (value.type() == typeid(float))
                config[key] = std::any_cast<float>(value);
            else if (value.type() == typeid(bool))
                config[key] = std::any_cast<bool>(value);
            else if (value.type() == typeid(std::string))
                config[key] = std::any_cast<std::string>(value);
            else
                config[key] = Json::Value::null;
        }
        
        configFile << config;

        configFile.close();
    }

    std::any& Configuration::operator [] (std::string name)
    {
        if (configuration.find(name) == configuration.end())
            configuration[name] = "";

        return configuration[name];
    }
}




