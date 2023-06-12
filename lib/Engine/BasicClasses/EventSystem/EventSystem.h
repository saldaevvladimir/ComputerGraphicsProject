#pragma once

#include <any>
#include <map>
#include <string>
#include <vector>
#include <functional>




class EventSystem
{
public:
    std::map<std::string, std::vector<std::function<void(std::vector<std::any>)>>> events;

    EventSystem();

    void Add(std::string name);

    void Remove(std::string name);

    void Handle(std::string name, std::function<void(std::vector<std::any>)> func);

    void RemoveHandled(std::string name, std::function<void(std::vector<std::any>)> func);

    void Trigger(std::string name, const std::vector<std::any>& args);

    std::vector<std::function<void(std::vector<std::any>)>> GetHandled(std::string name);
    // this metod returns all functions for given event name

    std::vector<std::function<void(std::vector<std::any>)>> operator [] (std::string name);
    // eventSystem[<name>] -> getHandled(name);

    static bool CompareFunctions(const std::function<void(std::vector<std::any>)>& func1, const std::function<void(std::vector<std::any>)>& func2);

    void operator = (EventSystem es);
};

bool operator == (const std::function<void(std::vector<std::any>)>& func1, const std::function<void(std::vector<std::any>)>& func2);
